#include "model_loader.h"
#include "tinyobjloader/tiny_obj_loader.h"

namespace Terabithia {

void LoadOBJ(const std::filesystem::path &path, Mesh &mesh) {
  tinyobj::ObjReader reader;
  tinyobj::ObjReaderConfig reader_config;

  auto status = reader.ParseFromFile(path.string(), reader_config);

  auto &attributes = reader.GetAttrib();
  auto &shapes = reader.GetShapes();
  auto &materials = reader.GetMaterials();

  for (const auto &shape : shapes) {
    std::size_t index_offset = 0;

    for (auto i = 0; i < shape.mesh.num_face_vertices.size(); i++) {
      auto vertices_in_face = shape.mesh.num_face_vertices[i];

      for (auto v = 0; v < vertices_in_face; v++) {
        auto index = shape.mesh.indices[index_offset + v];

        Vertex vertex{};

        auto vx = attributes.vertices[3 * index.vertex_index + 0];
        auto vy = attributes.vertices[3 * index.vertex_index + 1];
        auto vz = attributes.vertices[3 * index.vertex_index + 2];
        vertex.position_ = Vector3f(vx, vy, vz);

        if (attributes.normals.empty() == false) {
          auto nx = attributes.normals[3 * index.normal_index + 0];
          auto ny = attributes.normals[3 * index.normal_index + 1];
          auto nz = attributes.normals[3 * index.normal_index + 2];
          vertex.normal_ = Vector3f(nx, ny, nz);
        }

        if (index.texcoord_index >= 0) {
          auto uvx = attributes.texcoords[2 * index.texcoord_index + 0];
          auto uvy = attributes.texcoords[2 * index.texcoord_index + 1];
          vertex.uv_ = Vector2f(uvx, uvy);
        }

        mesh.AddVertex(vertex);
      }
      index_offset += vertices_in_face;
    }
  }
}

} // namespace Terabithia
