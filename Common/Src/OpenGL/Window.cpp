#include "OpenGL/Window.h"

#include <iostream>

Window::Window(int width, int height, const char* title) :
    m_Width(width),
    m_Height(height),
    m_Title(title) {
    
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    this->m_Window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (nullptr == this->m_Window) {
        std::cout << "Failed to creaet window." << std::endl;
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(this->m_Window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return;
    }    

    glfwSetFramebufferSizeCallback(this->m_Window, Window::FramebufferSizeCallBack);
}

Window::~Window() {
    glfwTerminate();
}

void Window::Show() {
    while(!glfwWindowShouldClose(this->m_Window)) {
        this->ProcessInput();

        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(this->m_Window);\
        glfwPollEvents();
    }
}

void Window::ProcessInput() {
    if (glfwGetKey(this->m_Window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(this->m_Window, true);
    }
}

void Window::FramebufferSizeCallBack(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}