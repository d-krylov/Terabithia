#version 460

layout (location = 0) in vec2 fragment_uv;
layout (location = 1) in vec4 fragment_color;

uniform sampler2D Texture;

layout (location = 0) out vec4 out_color;

void main() {
  out_color = fragment_color * texture(Texture, fragment_uv.st);
}