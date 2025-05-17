#pragma once

#include "gamestatemanager.h"
#include "gamestatemenu.h"

class StateSettings : public GameState
{
   public:
    StateSettings(GameStateManager& manager) : manager(manager) {}

    void update() override;
    void render() override { /* 无渲染或自定义 */ }
    bool shouldQuit() const override { return false; }

   private:
    GameStateManager& manager;
};
