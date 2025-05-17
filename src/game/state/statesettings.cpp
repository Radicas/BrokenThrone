#include "statesettings.h"
#include "core/renderer.h"
#include "raylib.h"

void StateSettings::update(float frameTime)
{
    Renderer::drawText("Settings State (ESC to return)", 100, 50, 20, DARKGRAY);

    if (IsKeyPressed(KEY_ESCAPE))
    {
        manager.setState(std::make_unique<StateMainMenu>(manager));
    }
}
