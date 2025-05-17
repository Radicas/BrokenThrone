#include "stateingame.h"
#include "core/assetmanager.h"
#include "core/renderer.h"
#include "raylib.h"

void StateInGame::update()
{
    // 进入战斗场景前的演示逻辑
    Renderer::drawText("In-Game State (ESC to return)", 100, 50, 20, DARKGRAY);

    if (IsKeyPressed(KEY_ESCAPE))
    {
        manager.setState(std::make_unique<StateMainMenu>(manager));
    }
}
