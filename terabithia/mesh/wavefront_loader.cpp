#define TINYOBJLOADER_IMPLEMENTATION
#include "tiny_obj_loader.h"
#include "mesh/include/mesh_loader.h"
#include <iostream>
#include <span>

namespace Terabithia {

std::vector<PlainVertex> LoadWavefront(std::span<const tinyobj::shape_t> shapes, const tinyobj::attrib_t &attributes) {
  std::vector<PlainVertex> vertices;
  for (const auto &shape : shapes) {
    for (const auto &index : shape.mesh.indices) {
      auto &new_vertex = vertices.emplace_back();
      new_vertex.position_.x = attributes.vertices[3 * index.vertex_index + 0];
      new_vertex.position_.y = attributes.vertices[3 * index.vertex_index + 1];
      new_vertex.position_.z = attributes.vertices[3 * index.vertex_index + 2];
      if (attributes.normals.empty() == false) {
        new_vertex.normal_.x = attributes.normals[3 * index.normal_index + 0];
        new_vertex.normal_.y = attributes.normals[3 * index.normal_index + 1];
        new_vertex.normal_.z = attributes.normals[3 * index.normal_index + 2];
      }
    }
  }
  return vertices;
}

void GetNormals(std::span<PlainVertex> vertices) {
  for (uint32_t i = 0; i < vertices.size(); i += 3) {
    auto &v0 = vertices[i + 0].position_;
    auto &v1 = vertices[i + 1].position_;
    auto &v2 = vertices[i + 2].position_;
    auto normal = glm::normalize(glm::cross(v1 - v0, v2 - v0));
    vertices[i + 0].normal_ = normal;
    vertices[i + 1].normal_ = normal;
    vertices[i + 2].normal_ = normal;
  }
}

std::vector<PlainVertex> LoadWavefront(const std::filesystem::path &path) {
  tinyobj::ObjReader reader;
  tinyobj::ObjReaderConfig reader_config;

  auto status = reader.ParseFromFile(path.string(), reader_config);

  auto &shapes = reader.GetShapes();
  auto &attributes = reader.GetAttrib();

  auto vertices = LoadWavefront(shapes, attributes);

  GetNormals(vertices);

  return vertices;
}

} // namespace Terabithia