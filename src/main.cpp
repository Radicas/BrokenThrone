#include "graphicslab/mainwindow.h"

struct Color
{
    float r;
    float g;
    float b;
    float a;
    Color(float r, float g, float b, float a) : r(r), g(g), b(b), a(a) {}
};

int main()
{
    MainWindow window(640, 480, "My Window");

    while (!window.shouldClose())
    {
        Color color(0, 0.5, 0.5, 1);
        window.clear(color.r, color.g, color.b, color.a);
        window.swapBuffers();
        window.pollEvents();
    }

    return 0;
}
