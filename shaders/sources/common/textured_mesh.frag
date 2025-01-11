#version 460 core

// IN
layout (location = 0) in vec3 in_position;
layout (location = 1) in vec3 in_normal;
layout (location = 2) in vec2 in_uv;

// OUT
layout (location = 0) out vec4 out_color;

uniform sampler2D u_diffuse;

void main() {
  vec3 color = texture(u_diffuse, in_uv).rgb;

  out_color = vec4(color, 1.0);
}