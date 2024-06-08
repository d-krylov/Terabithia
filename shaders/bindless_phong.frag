#version 460
#extension GL_ARB_bindless_texture : require

#define LIGHT_COUNT 32

layout (location = 0) out vec4 FragColor;

layout (location = 0) in vec3 in_normal;
layout (location = 1) in vec2 in_uv;
layout (location = 2) in vec3 in_fragment_position;

struct PointLight {
  vec4 u_position;
  vec4 u_color;
};

struct Material {
  sampler2D ambient_texture;
  sampler2D diffuse_texture;
  sampler2D specular_texture;
};

layout(binding = 0, std430) readonly buffer ssbo3 {
  Material textures[];
};

layout (std140, binding = 1) uniform PointLightBuffer {
  PointLight u_PointLights[LIGHT_COUNT];
};

float getDiffuse(vec3 light_direction) {
  return max(dot(light_direction, in_normal), 0.0);
}

float getSpecular(vec3 light_direction, vec3 view_direction) {
  vec3 halfway_direction = normalize(light_direction + view_direction);  
  return pow(max(dot(in_normal, halfway_direction), 0.0), 32.0);
}

void main() {
  FragColor = vec4(1.0, 0.0, 0.0, 1.0);
}