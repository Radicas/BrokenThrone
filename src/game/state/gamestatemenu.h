#pragma once

#include "core/assetmanager.h"
#include "core/renderer.h"
#include "gamestate.h"
#include "gamestatemanager.h"

#include <memory>
#include "raylib.h"

class StateMainMenu : public GameState
{
   public:
    StateMainMenu(GameStateManager& manager) : manager(manager)
    {
        AssetManager::loadTexture("menu_background", "assets/tilesets/HR_Fantasy_Landscape.png");
        AssetManager::loadMusic("menu_music", "assets/music/bgm2.ogg");
    }

    void update() override;
    void render() override;

   private:
    GameStateManager& manager;
};
