#pragma once

#include "gamestate.h"

#include <memory>

class GameStateManager
{
   public:
    void setState(std::unique_ptr<GameState> state) { currentState = std::move(state); }

    void update()
    {
        if (currentState)
            currentState->update();
    }

    void render()
    {
        if (currentState)
            currentState->render();
    }

    bool shouldQuit() const { return currentState && currentState->shouldQuit(); }

   private:
    std::unique_ptr<GameState> currentState;
};
