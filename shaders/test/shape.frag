#version 460 core

// IN
layout (location = 0) in vec3 in_position;
layout (location = 1) in vec3 in_normal;

// OUT
layout (location = 0) out vec4 out_color;

// UNIFORM
uniform vec3 u_ambient = vec3(0.5);
uniform vec3 u_diffuse = vec3(0.5);

uniform vec3 u_light_color = vec3(1.0);
uniform vec3 u_light_direction = vec3(0.0, 1.0, 0.0);

void main() {

  // ambient
  vec3 ambient = u_ambient;
  	
  // diffuse 
  float NdotL = max(dot(in_normal, u_light_direction), 0.0);
  
  vec3 diffuse = u_diffuse *  NdotL;
  
  // result
  vec3 color = u_light_color * (ambient + diffuse);

  out_color = vec4(color, 1.0);
}