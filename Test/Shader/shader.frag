#version 450 core

in vec3 frag_color;
in vec2 tex_coord;

out vec4 color;

uniform sampler2D texture1;
uniform sampler2D texture2;

void main() {
    color = mix(texture(texture1, tex_coord), texture(texture2, tex_coord) , 0.5) * vec4(frag_color, 1.0);
} 