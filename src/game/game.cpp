#include "game.h"
#include "core/assetmanager.h"
#include "state/statemenu.h"  // 主菜单状态

#include <raylib.h>

Game::Game(int width, int height, const char* title) : window(width, height, title), mBGM() {}

Game::~Game() {}

void Game::init()
{
    InitAudioDevice();
    AssetManager::loadMusic("bgm", "assets/music/8bit-spaceshooter.mp3");
    mBGM = AssetManager::getMusic("bgm");
    PlayMusicStream(mBGM);

    // 加载资源
    AssetManager::loadTexture("tile_map", "assets/tilesets/kenney_tiny-town/Tilemap/tilemap.png");
    stateManager.setState(std::make_unique<StateMainMenu>(stateManager));
}

void Game::shutdown()
{
    AssetManager::unloadAll();
    CloseAudioDevice();
}

void Game::run()
{
    init();

    while (!window.ShouldClose())
    {
        window.BeginFrame();
        float time = GetFrameTime();
        UpdateMusicStream(mBGM);

        // 交给状态机当前状态更新和绘制
        stateManager.update(time);
        stateManager.render();

        window.EndFrame();
    }

    shutdown();
}
