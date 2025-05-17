#include "gamestatemenu.h"
#include "stateingame.h"
#include "statesettings.h"

void StateMainMenu::update()
{
    Vector2 mouse = GetMousePosition();

    Rectangle startBtn = {810, 250, 300, 50};
    Rectangle settingsBtn = {810, 320, 300, 50};
    Rectangle quitBtn = {810, 390, 300, 50};

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        if (CheckCollisionPointRec(mouse, startBtn))
        {
            manager.setState(std::make_unique<StateInGame>(manager));
        }
        else if (CheckCollisionPointRec(mouse, settingsBtn))
        {
            manager.setState(std::make_unique<StateSettings>(manager));
        }
        else if (CheckCollisionPointRec(mouse, quitBtn))
        {
            manager.setState(nullptr);  // nullptr 表示退出
        }
    }

    Texture2D& background = AssetManager::getTexture("menu_background");
    DrawTexture(background, 0, 0, WHITE);

}

void StateMainMenu::render()
{
    Renderer::drawText("Broken Throne", 750, 100, 40, DARKGRAY);

    DrawRectangle(810, 250, 300, 50, LIGHTGRAY);
    DrawRectangle(810, 320, 300, 50, LIGHTGRAY);
    DrawRectangle(810, 390, 300, 50, LIGHTGRAY);

    DrawText("Start Game", 900, 265, 20, DARKGRAY);
    DrawText("Settings", 915, 335, 20, DARKGRAY);
    DrawText("Exit Game", 910, 405, 20, DARKGRAY);
}
