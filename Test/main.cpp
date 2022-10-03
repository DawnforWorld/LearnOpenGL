#include "OpenGL/Window.h"
#include "OpenGL/Shader.h"

#include <iostream>

int main() {
    Window window(800, 600, "Learn OpenGL");

    Shader shader("./Shader/shader.vert", nullptr, "./Shader/shader.frag");
    shader.Use();

    shader.SetUniform("texture1", 0);
    shader.SetUniform("texture2", 1);

    window.Show();

    return 0;
}