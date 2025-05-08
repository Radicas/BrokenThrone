#pragma once
// To make sure there will be no header conflicts,
// you can define GLFW_INCLUDE_NONE before the GLFW header to
// explicitly disable inclusion of the development environment header.
// This also allows the two headers to be included in any order.
#define GLFW_INCLUDE_NONE

#include <GLFW/glfw3.h>

class MainWindow
{
   public:
    MainWindow(int width, int height, const char* title);
    ~MainWindow();

    bool shouldClose() const;
    void pollEvents() const;
    void swapBuffers() const;
    void clear(float r, float g, float b, float a) const;
    GLFWwindow* getGLFWwindow() const;

   private:
    GLFWwindow* window;
};
