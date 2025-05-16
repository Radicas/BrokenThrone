#pragma once
#include <string>
#include "raylib.h"

class Renderer
{
   public:
    static void drawTexture(Texture2D& texture, int x, int y);
    static void drawText(const std::string& text, int x, int y, int fontSize, Color color);
};
