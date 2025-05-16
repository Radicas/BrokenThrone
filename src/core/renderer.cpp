#include "renderer.h"

void Renderer::drawTexture(Texture2D& texture, int x, int y)
{
    DrawTexture(texture, x, y, WHITE);
}

void Renderer::drawText(const std::string& text, int x, int y, int fontSize, Color color)
{
    ::DrawText(text.c_str(), x, y, fontSize, color);
}
