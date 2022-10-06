#include "Window.h"

int main() {
    Window window(800, 600, "Learn OpenGL");

    Shader shader("./Shader/shader.vert", nullptr, "./Shader/shader.frag");

    window.Show(&shader);

    return 0;
}