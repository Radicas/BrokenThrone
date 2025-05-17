#include "player.h"
#include <math.h>

void initPlayer(Player& player, Vector2 startPos)
{
    player.position = startPos;
    player.speed = 100.0f;
    player.size = {32, 32};  // 你可以根据 tile 尺寸自行修改
}

void updatePlayer(Player& player, float deltaTime)
{
    Vector2 move = {0, 0};

    if (IsKeyDown(KEY_W))
        move.y -= 1;
    if (IsKeyDown(KEY_S))
        move.y += 1;
    if (IsKeyDown(KEY_A))
        move.x -= 1;
    if (IsKeyDown(KEY_D))
        move.x += 1;

    // 归一化移动方向（防止斜方向速度更快）
    float length = sqrtf(move.x * move.x + move.y * move.y);
    if (length > 0.01f)
    {
        move.x /= length;
        move.y /= length;
    }

    // 应用移动
    player.position.x += move.x * player.speed * deltaTime;
    player.position.y += move.y * player.speed * deltaTime;
}

void drawPlayer(const Player& player)
{
    DrawRectangleV({player.position.x - player.size.x / 2, player.position.y - player.size.y / 2}, player.size, RED);
}
