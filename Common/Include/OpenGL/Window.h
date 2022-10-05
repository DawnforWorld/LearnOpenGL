#ifndef __OPENGL_WINDOW_H__
#define __OPENGL_WINDOW_H__

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <vector>

#include "Shader.h"

static float last_X = 400.0f;
static float last_Y = 400.0f;

static float pitch = 0.0f;
static float yaw = -90.0f;

static bool is_first = true;

static float fov = 45.0f;

static glm::vec3 camera_position(0.0, 0.0, 3.0);
static glm::vec3 camera_front(0.0, 0.0, -1.0);
static glm::vec3 camera_up(0.0, 1.0, 0.0);

void MouseCallBack(GLFWwindow* window, double xpos, double ypos);
void ScrollCallBack(GLFWwindow* window, double x_offset, double y_offset);

class Window {
public:
    Window(int width, int height, const char* title);
    ~Window();

    void Show(Shader* shader);

private:
    static void FramebufferSizeCallBack(GLFWwindow* window, int width, int height);

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
