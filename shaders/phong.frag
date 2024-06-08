// SIMPLE PHONG MODEL
#version 460

// IN
layout (location = 0) in vec3 in_normal;
layout (location = 1) in vec2 in_uv;
layout (location = 2) in vec3 in_fragment_position;

// OUT
layout (location = 0) out vec4 out_color;

// LIGHTS
struct PointLight {
  vec4 u_position;
  vec4 u_color;
};

// PHONG
float getDiffuse(vec3 light_direction) {
  return max(dot(light_direction, in_normal), 0.0);
}

float getSpecular(vec3 light_direction, vec3 view_direction) {
  vec3 halfway_direction = normalize(light_direction + view_direction);  
  return pow(max(dot(in_normal, halfway_direction), 0.0), 32.0);
}

void main() {
  out_color = vec4(1.0, 0.0, 0.0, 1.0);
}