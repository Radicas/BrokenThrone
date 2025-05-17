#pragma once
#include "core/window.h"
#include "state/gamestatemanager.h"

class Game
{
   public:
    Game(int width, int height, const char* title);
    ~Game();

    void run();

   private:
    void init();
    void shutdown();

    Window window;
    GameStateManager stateManager;
    Music mBGM;
};
