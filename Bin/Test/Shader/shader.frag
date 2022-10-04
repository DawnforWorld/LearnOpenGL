#version 450 core

in vec2 tex_coord;

out vec4 frag_color;

uniform sampler2D texture1;
uniform sampler2D texture2;

uniform float mix_value;

void main() {
    frag_color = mix(texture(texture1, tex_coord), texture(texture2, tex_coord) , mix_value);
} 