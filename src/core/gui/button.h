#pragma once

#include <string>
#include "raylib.h"

class Button
{
   public:
    Button(float x, float y, float width, float height, Texture2D texture, const char* text = "",
           Sound* hoverSound = nullptr);

    void update(const Vector2& mouse);
    void draw() const;
    bool isClicked(const Vector2& mouse) const;

    Rectangle rect;
    Texture2D texture;
    std::string label;

   private:
    bool hovered = false;
    Sound* hoverSound = nullptr;  // 指向外部加载好的 sound
};
