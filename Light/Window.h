#ifndef __OPENGL_WINDOW_H__
#define __OPENGL_WINDOW_H__

#include <vector>

#include "glad/glad.h"

#include "OpenGL/Shader.h"

class Window {
public:
    Window(int width, int height, const char* title);
    ~Window();

    void Show(Shader* shader);

private:
    static void FramebufferSizeCallBack(GLFWwindow* window, int width, int height);
    static void MouseCallback(GLFWwindow* window, double xpos, double ypos);
    static void ScrollCallback(GLFWwindow* window, double xoffset, double yoffset);

    void ProcessInput();

    int m_Width = 0;
    int m_Height = 0;
    const char* m_Title = nullptr;
    float m_MixValue = 0.5f;

    GLFWwindow* m_Window = nullptr;

    float m_DeltaTime = 0.0f;
    float m_LastFrame = 0.0f;
};

#endif
