#version 460 core

// IN
layout (location = 0) in vec3 in_position;
layout (location = 1) in vec3 in_normal;
layout (location = 2) in vec3 in_color;
layout (location = 3) in vec2 in_uv;

// OUT
layout (location = 0) out vec4 out_color;

void main() {
  vec3 color = in_color;
  
  out_color = vec4(color, 1.0);
}