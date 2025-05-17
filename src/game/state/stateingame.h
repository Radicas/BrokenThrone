#pragma once

#include "gamestatemanager.h"  // 拿到 manager
#include "gamestatemenu.h"     // 用来拿到 GameState 基类

class StateInGame : public GameState
{
   public:
    StateInGame(GameStateManager& manager) : manager(manager) {}

    void update() override;
    void render() override { /* 如无额外渲染可留空 */ }
    bool shouldQuit() const override { return false; }

   private:
    GameStateManager& manager;
};
