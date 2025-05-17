#include "tilemap.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "raylib.h"

TileMap::TileMap() : tiles(nullptr), mapWidth(0), mapHeight(0), tileWidth(0), tileHeight(0), tilesetCols(0) {}

TileMap::~TileMap()
{
    unload();
}

bool TileMap::load(const char* jsonPath, const char* tilesetPath, int tileWidth, int tileHeight, int tilesetCols)
{
    this->tileWidth = tileWidth;
    this->tileHeight = tileHeight;
    this->tilesetCols = tilesetCols;

    // 加载 JSON 文件内容
    FILE* file = fopen(jsonPath, "rb");
    if (!file)
        return false;
    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    rewind(file);
    char* jsonData = (char*)malloc(length + 1);
    fread(jsonData, 1, length, file);
    jsonData[length] = '\0';
    fclose(file);

    // 解析 JSON
    cJSON* root = cJSON_Parse(jsonData);
    if (!root)
    {
        free(jsonData);
        return false;
    }

    cJSON* widthItem = cJSON_GetObjectItem(root, "width");
    cJSON* heightItem = cJSON_GetObjectItem(root, "height");
    cJSON* layers = cJSON_GetObjectItem(root, "layers");

    if (!cJSON_IsNumber(widthItem) || !cJSON_IsNumber(heightItem) || !cJSON_IsArray(layers))
    {
        cJSON_Delete(root);
        free(jsonData);
        return false;
    }

    mapWidth = widthItem->valueint;
    mapHeight = heightItem->valueint;

    cJSON* layer = cJSON_GetArrayItem(layers, 0);
    cJSON* data = cJSON_GetObjectItem(layer, "data");

    if (!cJSON_IsArray(data))
    {
        cJSON_Delete(root);
        free(jsonData);
        return false;
    }

    int size = mapWidth * mapHeight;
    tiles = (int*)malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++)
    {
        cJSON* val = cJSON_GetArrayItem(data, i);
        tiles[i] = cJSON_IsNumber(val) ? val->valueint : 0;
    }

    cJSON_Delete(root);
    free(jsonData);

    // 加载纹理
    tileset = LoadTexture(tilesetPath);

    return true;
}

void TileMap::draw() const
{
    if (!tiles)
        return;

    for (int y = 0; y < mapHeight; y++)
    {
        for (int x = 0; x < mapWidth; x++)
        {
            int index = y * mapWidth + x;
            int tileId = tiles[index] - 1;  // Tiled 从 1 开始，C++ 从 0 开始

            if (tileId < 0)
                continue;

            int srcX = (tileId % tilesetCols) * tileWidth;
            int srcY = (tileId / tilesetCols) * tileHeight;

            Rectangle src = {(float)srcX, (float)srcY, (float)tileWidth, (float)tileHeight};
            Rectangle dst = {(float)(x * tileWidth), (float)(y * tileHeight), (float)tileWidth, (float)tileHeight};
            DrawTexturePro(tileset, src, dst, {0, 0}, 0.0f, WHITE);
        }
    }
}

void TileMap::unload()
{
    if (tiles)
    {
        free(tiles);
        tiles = nullptr;
    }
    if (tileset.id > 0)
    {
        UnloadTexture(tileset);
        tileset.id = 0;
    }
}
