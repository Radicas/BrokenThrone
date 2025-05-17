#include "stateingame.h"
#include "statemenu.h"

StateInGame::StateInGame(GameStateManager& manager) : manager(manager), map(), player()
{
    // 加载贴图
    Texture2D tileset = AssetManager::getTexture("tile_map");
    map.load("assets/maps/tilemap.json", "assets/tilesets/kenney_tiny-town/Tilemap/tilemap_packed.png", 16, 16, 12);
    initPlayer(player, {32 + 16, 32 + 16});
}

void StateInGame::update(float frameTime)
{
    if (IsKeyPressed(KEY_ESCAPE))
    {
        manager.setState(std::make_unique<StateMainMenu>(manager));
    }

    // 其他游戏逻辑
    updatePlayer(player, frameTime);
}

void StateInGame::render()
{
    map.draw();
    drawPlayer(player);
}
