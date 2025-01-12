#version 460 core

struct Vertex {
  float position[3];
  float normal[3];
};

layout(binding = 0, std430) readonly buffer vertex_buffer {
  Vertex vertices[];
};

vec3 get_position(int index) { return vec3(vertices[index].position[0], vertices[index].position[1], vertices[index].position[2]); }
vec3 get_normal(int index)   { return vec3(vertices[index].normal[0],   vertices[index].normal[1],   vertices[index].normal[2]); }

// OUT
layout (location = 0) out vec3 out_position;
layout (location = 1) out vec3 out_normal;

// UNIFORM
uniform mat4 u_view_matrix  = mat4(1.0);
uniform mat4 u_projection_matrix = mat4(1.0);
uniform mat4 u_model_matrix = mat4(1.0);

out gl_PerVertex {
  vec4 gl_Position;
};

void main() {
  vec3 in_position = get_position(gl_VertexID);
  vec3 in_normal = get_normal(gl_VertexID);

  gl_Position = u_projection_matrix * u_view_matrix * u_model_matrix * vec4(in_position, 1.0);
  out_normal = normalize(mat3(transpose(inverse(u_model_matrix))) * in_normal);
  out_position = vec3(u_model_matrix * vec4(in_position, 1.0));
}