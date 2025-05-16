#pragma once
#include <string>
#include "raylib.h"

class Window
{
   public:
    Window(int width, int height, const std::string& title);
    ~Window();

    bool ShouldClose() const;

    void BeginFrame();
    void EndFrame();

    int GetWidth() const { return width; }
    int GetHeight() const { return height; }

    void close() { CloseWindow(); }

   private:
    int width;
    int height;
};
