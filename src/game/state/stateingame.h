#pragma once

#include "core/assetmanager.h"
#include "game/player/player.h"
#include "game/tilemap/tilemap.h"
#include "gamestate.h"
#include "gamestatemanager.h"

class StateInGame : public GameState
{
   public:
    StateInGame(GameStateManager& manager);

    void update(float frameTime) override;
    void render() override;

   private:
    GameStateManager& manager;
    TileMap map;
    Player player;
};
