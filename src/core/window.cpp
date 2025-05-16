#include "Window.h"

Window::Window(int w, int h, const std::string& title) : width(w), height(h)
{
    InitWindow(width, height, title.c_str());
    SetTargetFPS(60);
}

Window::~Window()
{
    CloseWindow();
}

bool Window::ShouldClose() const
{
    return WindowShouldClose();
}

void Window::BeginFrame()
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
}

void Window::EndFrame()
{
    EndDrawing();
}
