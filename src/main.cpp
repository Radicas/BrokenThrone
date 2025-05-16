#include "core/AssetManager.h"
#include "core/Renderer.h"
#include "core/Window.h"

#include "raylib.h"  // 用于音频和 UI 绘制

enum class GameState
{
    MainMenu,
    InGame,
    Settings,
    Exit
};

int main()
{
    Window window(1920, 1080, "Broken Throne");
    InitAudioDevice();

    AssetManager::loadTexture("test",
                              "C:/Users/11768/Desktop/Repos/BrokenThrone/assets/tilesets/HR_Fantasy_Landscape.png");
    Music bgm = LoadMusicStream("C:/Users/11768/Desktop/Repos/BrokenThrone/assets/music/bgm2.ogg");
    PlayMusicStream(bgm);

    GameState gameState = GameState::MainMenu;

    while (!window.ShouldClose())
    {
        UpdateMusicStream(bgm);
        window.BeginFrame();

        Renderer::drawTexture(AssetManager::getTexture("test"), 100, 100);

        switch (gameState)
        {
            case GameState::MainMenu:
            {
                Renderer::drawText("Broken Throne", 750, 100, 40, DARKGRAY);

                // 三个按钮
                Rectangle startBtn = {810, 250, 300, 50};
                Rectangle settingsBtn = {810, 320, 300, 50};
                Rectangle quitBtn = {810, 390, 300, 50};

                DrawRectangleRec(startBtn, LIGHTGRAY);
                DrawRectangleRec(settingsBtn, LIGHTGRAY);
                DrawRectangleRec(quitBtn, LIGHTGRAY);

                DrawText("Start Game", 900, 265, 20, DARKGRAY);
                DrawText("Settings", 915, 335, 20, DARKGRAY);
                DrawText("Exit Game", 910, 405, 20, DARKGRAY);

                // 检测点击
                Vector2 mouse = GetMousePosition();
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    if (CheckCollisionPointRec(mouse, startBtn))
                    {
                        gameState = GameState::InGame;
                    }
                    else if (CheckCollisionPointRec(mouse, settingsBtn))
                    {
                        gameState = GameState::Settings;
                    }
                    else if (CheckCollisionPointRec(mouse, quitBtn))
                    {
                        gameState = GameState::Exit;
                    }
                }
            }
            break;

            case GameState::InGame:
            {
                Renderer::drawText("Game Running... (Press ESC to return)", 100, 50, 20, DARKGRAY);
                Renderer::drawTexture(AssetManager::getTexture("test"), 100, 100);

                if (IsKeyPressed(KEY_ESCAPE))
                {
                    gameState = GameState::MainMenu;
                }
            }
            break;

            case GameState::Settings:
            {
                Renderer::drawText("Settings... (Press ESC to return)", 100, 50, 20, DARKGRAY);

                if (IsKeyPressed(KEY_ESCAPE))
                {
                    gameState = GameState::MainMenu;
                }
            }
            break;

            case GameState::Exit:
                window.close();  // 提前退出
                break;
        }

        window.EndFrame();
    }

    UnloadMusicStream(bgm);
    AssetManager::unloadAll();
    CloseAudioDevice();

    return 0;
}
