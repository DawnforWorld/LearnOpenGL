#ifndef __OPENGL_WINDOW_H__
#define __OPENGL_WINDOW_H__

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <vector>

#include "Shader.h"

class Window {
public:
    Window(int width, int height, const char* title);
    ~Window();

    void Show();

    using Render = void(*)(std::vector<Shader*>);

    void SetRender(Render render);
    void AddShader(Shader* shader);

private:
    static void FramebufferSizeCallBack(GLFWwindow* window, int width, int height);

    void ProcessInput();

    int m_Width = 0;
    int m_Height = 0;
    const char* m_Title = nullptr;

    GLFWwindow* m_Window = nullptr;

    Render m_Render = nullptr;

    std::vector<Shader*> m_Shaders;
};

#endif
