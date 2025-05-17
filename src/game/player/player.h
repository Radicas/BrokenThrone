#pragma once

#include "raylib.h"

struct Player {
    Vector2 position;   // 玩家坐标（单位：像素）
    float speed;        // 每秒移动速度（像素/秒）
    Vector2 size;       // 玩家矩形大小
};

void initPlayer(Player& player, Vector2 startPos);
void updatePlayer(Player& player, float deltaTime);
void drawPlayer(const Player& player);
