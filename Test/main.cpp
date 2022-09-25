#include "OpenGL/Window.h"
#include "OpenGL/Shader.h"
#include "OpenGL/VertexArray.h"

#include <iostream>

void Render(std::vector<Shader*> shaders);

int main() {
    Window window(800, 600, "Learn OpenGL");

    window.SetRender(Render);

    float vertices[] = {
        // positions         // colors
         0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // bottom left
         0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // top 
    };

    VertexArray vertex_array_object(vertices, sizeof(vertices), GL_STATIC_DRAW);

    vertex_array_object.Bind();

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

  

    Shader shader("./Shader/shader.vert", nullptr, "./Shader/shader.frag");
    shader.Use();

    window.Show();

    return 0;
}

void Render(std::vector<Shader*> shaders) {
    glDrawArrays(GL_TRIANGLES, 0, 3);

}