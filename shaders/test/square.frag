#version 460 core

// IN
layout (location = 0) in vec2 in_uv;

// OUT
layout (location = 0) out vec4 out_color;

uniform sampler2D u_texture;

void main() {

  vec4 color = texture(u_texture, in_uv);

  out_color = color;
}