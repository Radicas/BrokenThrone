#include "my_learn_opengl/mainwindow.h"

#include <glad/glad.h>
#include <stdexcept>

MainWindow::MainWindow(int width, int height, const char* title)
{
    if (!glfwInit())
        throw std::runtime_error("Failed to initialize GLFW");

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW window");
    }

    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        throw std::runtime_error("Failed to initialize GLAD");

    glfwSwapInterval(1);  // Enable vsync
}

MainWindow::~MainWindow()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}

bool MainWindow::shouldClose() const
{
    return glfwWindowShouldClose(window);
}

void MainWindow::pollEvents() const
{
    glfwPollEvents();
}

void MainWindow::swapBuffers() const
{
    glfwSwapBuffers(window);
}

void MainWindow::clear(float r, float g, float b, float a) const
{
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT);
}

GLFWwindow* MainWindow::getGLFWwindow() const
{
    return window;
}
