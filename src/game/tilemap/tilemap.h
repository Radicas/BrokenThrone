#ifndef TILEMAP_H
#define TILEMAP_H

#include "core/json/cjson.h"
#include "raylib.h"

class TileMap
{
   public:
    TileMap();
    ~TileMap();

    // 加载地图 JSON 文件和 tileset 纹理
    bool load(const char* jsonPath, const char* tilesetPath, int tileWidth, int tileHeight, int tilesetCols);

    // 渲染整个地图
    void draw() const;

    // 释放内存
    void unload();

   private:
    int* tiles;         // 瓦片数据
    int mapWidth;       // 地图宽度（单位：瓦片）
    int mapHeight;      // 地图高度（单位：瓦片）
    int tileWidth;      // 每个瓦片宽度
    int tileHeight;     // 每个瓦片高度
    int tilesetCols;    // tileset中每行的瓦片数
    Texture2D tileset;  // 瓦片集纹理
};

#endif  // TILEMAP_H
