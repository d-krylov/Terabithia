#version 460

layout (location = 0) in vec2 in_fragment_uv;

layout (location = 0) out vec4 FragColor;

uniform vec3 u_position;

struct Ray {
  vec3 origin;
  vec3 direction;
};

float sdSphere(vec3 p, float r) { return length(p) - r; }

float sdBox(vec3 p, vec3 size, float r) {
  vec3 q = abs(p) - size + r;
  return length(max(q, 0.0)) + min(max(q.x, max(q.y, q.z)), 0.0) - r;
}

void main() {
  FragColor = vec4(1.0, 0.0, 0.0, 1.0);
}