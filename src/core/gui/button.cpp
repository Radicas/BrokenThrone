#include "button.h"

Button::Button(float x, float y, float width, float height, Texture2D texture, const char* text, Sound* hoverSound)
    : rect{x, y, width, height}, texture(texture), label(text ? text : ""), hovered(false), hoverSound(hoverSound)
{
}

void Button::update(const Vector2& mouse)
{
    bool wasHovered = hovered;
    hovered = CheckCollisionPointRec(mouse, rect);

    if (hovered && !wasHovered && hoverSound)
    {
        PlaySound(*hoverSound);
    }
}

bool Button::isClicked(const Vector2& mouse) const
{
    return hovered && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
}

void Button::draw() const
{
    Color tint = hovered ? LIGHTGRAY : WHITE;

    DrawTexturePro(texture, {0, 0, (float)texture.width, (float)texture.height}, rect, {0, 0}, 0, tint);

    if (!label.empty())
    {
        int fontSize = 20;
        Vector2 textSize = MeasureTextEx(GetFontDefault(), label.c_str(), fontSize, 1);
        float textX = rect.x + (rect.width - textSize.x) / 2;
        float textY = rect.y + (rect.height - textSize.y) / 2;

        DrawText(label.c_str(), (int)textX, (int)textY, fontSize, DARKGRAY);
    }
}
