#pragma once

#include <memory>
#include <vector>
#include "gamestate.h"
#include "gamestatemanager.h"
#include "raylib.h"

class Button;  // 前向声明，减少头文件依赖

class StateMainMenu : public GameState
{
   public:
    explicit StateMainMenu(GameStateManager& manager);
    ~StateMainMenu() override;

    void update(float frameTime) override;
    void render() override;

   private:
    GameStateManager& manager;
    Texture2D backgroundTexture;
    std::vector<std::unique_ptr<Button>> buttons;
    Sound hoverSound;
};
