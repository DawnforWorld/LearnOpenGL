#include "OpenGL/Window.h"
#include "OpenGL/Shader.h"

#include <iostream>

int main() {
    Window window(800, 600, "Learn OpenGL");

    Shader shader("./Shader/shader.vert", nullptr, "./Shader/shader.frag");
    shader.Use();

    window.Show();

    return 0;
}