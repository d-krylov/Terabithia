#version 460

layout (location = 0) in vec2 in_position;
layout (location = 1) in vec2 in_uv;
layout (location = 2) in vec4 in_color;

uniform mat4 ProjectionMatrix;

layout (location = 0) out vec2 fragment_uv;
layout (location = 1) out vec4 fragment_color;

void main() {
  fragment_uv = in_uv;
  fragment_color = in_color;
  gl_Position = ProjectionMatrix * vec4(in_position.xy, 0, 1);
}