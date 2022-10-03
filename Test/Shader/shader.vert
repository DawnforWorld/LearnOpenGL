#version 450 core

layout (location = 0) in vec3 pos;
layout (location = 1) in vec3 color;
layout (location = 2) in vec2 texCoord;

out vec3 frag_color;
out vec2 tex_coord;

void main() {
    gl_Position = vec4(pos, 1.0);
    frag_color = color;
    tex_coord = texCoord;
}