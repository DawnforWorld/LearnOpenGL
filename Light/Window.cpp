#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "stb_image.h"

#include <iostream>

#include "OpenGL/Camera.h"

#include "Window.h"

// camera
static Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
static float lastX = 800 / 2.0f;
static float lastY = 600 / 2.0f;
static bool firstMouse = true;

Window::Window(int width, int height, const char* title) :
    m_Width(width),
    m_Height(height),
    m_Title(title) {
    
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
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

    glfwSetInputMode(this->m_Window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetFramebufferSizeCallback(this->m_Window, Window::FramebufferSizeCallBack);
    glfwSetCursorPosCallback(this->m_Window, Window::MouseCallback);
    glfwSetScrollCallback(this->m_Window, Window::ScrollCallback);
}

Window::~Window() {
    glfwTerminate();
}

void Window::Show() {
    Shader shader("./Shader/shader.vert", nullptr, "./Shader/shader.frag");
    Shader light_shader("./Shader/light.vert", nullptr, "./Shader/light.frag");

    float vertices[] = {
        -0.5f, -0.5f, -0.5f, 
         0.5f, -0.5f, -0.5f,  
         0.5f,  0.5f, -0.5f,  
         0.5f,  0.5f, -0.5f,  
        -0.5f,  0.5f, -0.5f, 
        -0.5f, -0.5f, -0.5f, 

        -0.5f, -0.5f,  0.5f, 
         0.5f, -0.5f,  0.5f,  
         0.5f,  0.5f,  0.5f,  
         0.5f,  0.5f,  0.5f,  
        -0.5f,  0.5f,  0.5f, 
        -0.5f, -0.5f,  0.5f, 

        -0.5f,  0.5f,  0.5f, 
        -0.5f,  0.5f, -0.5f, 
        -0.5f, -0.5f, -0.5f, 
        -0.5f, -0.5f, -0.5f, 
        -0.5f, -0.5f,  0.5f, 
        -0.5f,  0.5f,  0.5f, 

         0.5f,  0.5f,  0.5f,  
         0.5f,  0.5f, -0.5f,  
         0.5f, -0.5f, -0.5f,  
         0.5f, -0.5f, -0.5f,  
         0.5f, -0.5f,  0.5f,  
         0.5f,  0.5f,  0.5f,  

        -0.5f, -0.5f, -0.5f, 
         0.5f, -0.5f, -0.5f,  
         0.5f, -0.5f,  0.5f,  
         0.5f, -0.5f,  0.5f,  
        -0.5f, -0.5f,  0.5f, 
        -0.5f, -0.5f, -0.5f, 

        -0.5f,  0.5f, -0.5f, 
         0.5f,  0.5f, -0.5f,  
         0.5f,  0.5f,  0.5f,  
         0.5f,  0.5f,  0.5f,  
        -0.5f,  0.5f,  0.5f, 
        -0.5f,  0.5f, -0.5f, 
    };

    unsigned int VAO, light_VAO, VBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    glGenVertexArrays(1, &light_VAO);

    glBindVertexArray(light_VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);

    glEnable(GL_DEPTH_TEST);  

    shader.Use();
    shader.SetUniform("objectColor", glm::vec3(1.0f, 0.5f, 0.31f));
    shader.SetUniform("lightColor",  glm::vec3(1.0f, 1.0f, 1.0f));

    while(!glfwWindowShouldClose(this->m_Window)) {
        float current_time = glfwGetTime();
        this->m_DeltaTime = current_time - this->m_LastFrame;
        this->m_LastFrame = current_time;

        this->ProcessInput();

        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glBindVertexArray(VAO);

        glm::mat4 view = camera.GetViewMatrix();

        glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), float(this->m_Width) / float(this->m_Height), 0.1f, 100.0f);

        glBindVertexArray(VAO);

        glm::mat4 model = glm::mat4(1.0f);
        
        model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));

        shader.Use();

        shader.SetUniform("model", model);
        shader.SetUniform("view", view);
        shader.SetUniform("projection", projection);

        glDrawArrays(GL_TRIANGLES, 0, 36);

        glBindVertexArray(light_VAO);

        model = glm::mat4(1.0f);
        
        model = glm::translate(model, glm::vec3(1.0, 1.0, 1.0));
        model = glm::scale(model, glm::vec3(0.2, 0.2, 0.2));

        light_shader.Use();

        light_shader.SetUniform("model", model);
        light_shader.SetUniform("view", view);
        light_shader.SetUniform("projection", projection);

        glDrawArrays(GL_TRIANGLES, 0, 36);

        glfwSwapBuffers(this->m_Window);
        glfwPollEvents();
    }

    glBindVertexArray(0);

    glDeleteBuffers(1, &VBO);
    glDeleteVertexArrays(1, &VAO);
}

void Window::ProcessInput() {
    if (glfwGetKey(this->m_Window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(this->m_Window, true);
    }
    else if (glfwGetKey(this->m_Window, GLFW_KEY_UP) == GLFW_PRESS) {
        if (m_MixValue < 1.0f) {
            m_MixValue += 0.0005;
        }
        else m_MixValue == 1.0f;
    }
    else if (glfwGetKey(this->m_Window, GLFW_KEY_DOWN) == GLFW_PRESS) {
        if (m_MixValue > 0.0f) {
            m_MixValue -= 0.0005;
        }
        else m_MixValue == 0.0f;
    }
    
    if (glfwGetKey(this->m_Window, GLFW_KEY_W) == GLFW_PRESS) {
        camera.ProcessKeyboard(FORWARD, m_DeltaTime);
    }
    else if (glfwGetKey(this->m_Window, GLFW_KEY_S) == GLFW_PRESS) {
        camera.ProcessKeyboard(BACKWARD, m_DeltaTime);
    }
    else if (glfwGetKey(this->m_Window, GLFW_KEY_A) == GLFW_PRESS) {
        camera.ProcessKeyboard(LEFT, m_DeltaTime);
    }
    else if (glfwGetKey(this->m_Window, GLFW_KEY_D) == GLFW_PRESS) {
        camera.ProcessKeyboard(RIGHT, m_DeltaTime);
    }
}

void Window::FramebufferSizeCallBack(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void Window::MouseCallback(GLFWwindow* window, double xpos, double ypos) {
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

    lastX = xpos;
    lastY = ypos;

    camera.ProcessMouseMovement(xoffset, yoffset);
}

void Window::ScrollCallback(GLFWwindow* window, double xoffset, double yoffset) {
    camera.ProcessMouseScroll(static_cast<float>(yoffset));
}