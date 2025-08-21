#version 460 core

layout (location = 0) in vec2 in_position;
layout (location = 1) in vec2 in_uv;
layout (location = 2) in uint in_color;

layout (location = 0) out vec2 out_uv;
layout (location = 1) out vec4 out_color;

uniform mat4 u_projection_matrix;

vec4 unpack_color(uint color) {
  return vec4(
    float((color >>  0) & 0xff) / 255.0,
    float((color >>  8) & 0xff) / 255.0,
    float((color >> 16) & 0xff) / 255.0,
    float((color >> 24) & 0xff) / 255.0
  );
}

void main() {
  out_uv = in_uv;
  out_color = unpack_color(in_color); 
  gl_Position = u_projection_matrix * vec4(in_position.xy, 0, 1);
}