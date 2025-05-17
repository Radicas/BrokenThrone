#pragma once

#include "raylib.h"

// 以最大比例居中绘制纹理，适配屏幕尺寸，保持原始比例
inline void drawTextureFitScreen(Texture2D texture, int screenWidth, int screenHeight)
{
    float scaleX = (float)screenWidth / texture.width;
    float scaleY = (float)screenHeight / texture.height;
    float scale = (scaleX < scaleY) ? scaleX : scaleY;

    float targetWidth = texture.width * scale;
    float targetHeight = texture.height * scale;

    Vector2 position = {(screenWidth - targetWidth) / 2.0f, (screenHeight - targetHeight) / 2.0f};

    DrawTextureEx(texture, position, 0.0f, scale, WHITE);
}

// 将纹理强制拉伸以填满整个屏幕，不保留原始比例
inline void drawTextureStretchToScreen(Texture2D texture, int screenWidth, int screenHeight)
{
    Rectangle source = {0, 0, (float)texture.width, (float)texture.height};
    Rectangle dest = {0, 0, (float)screenWidth, (float)screenHeight};
    Vector2 origin = {0, 0};

    DrawTexturePro(texture, source, dest, origin, 0.0f, WHITE);
}