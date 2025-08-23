#include "model.h"
#define TINYOBJLOADER_IMPLEMENTATION
#include "tiny_obj_loader.h"

namespace Terabithia {

std::array texture_name_pointers{
  &tinyobj::material_t::ambient_texname, &tinyobj::material_t::diffuse_texname,  &tinyobj::material_t::specular_texname,
  &tinyobj::material_t::bump_texname,    &tinyobj::material_t::metallic_texname, &tinyobj::material_t::roughness_texname,
  &tinyobj::material_t::sheen_texname,   &tinyobj::material_t::emissive_texname, &tinyobj::material_t::normal_texname};

void LoadMaterials() {
}

void LoadVertices(const tinyobj::ObjReader &reader, std::span<MeshVertex> out_vertices) {
  const auto &shapes = reader.GetShapes();
  const auto &attributes = reader.GetAttrib();

  uint32_t out_index = 0;

  for (const auto &shape : shapes) {
    for (const auto &index : shape.mesh.indices) {

      out_vertices[out_index].position_.x = attributes.vertices[3 * index.vertex_index + 0];
      out_vertices[out_index].position_.y = attributes.vertices[3 * index.vertex_index + 1];
      out_vertices[out_index].position_.z = attributes.vertices[3 * index.vertex_index + 2];

      if (attributes.normals.empty() == false) {
        out_vertices[out_index].normal_.x = attributes.normals[3 * index.normal_index + 0];
        out_vertices[out_index].normal_.y = attributes.normals[3 * index.normal_index + 1];
        out_vertices[out_index].normal_.z = attributes.normals[3 * index.normal_index + 2];
      }

      if (index.texcoord_index >= 0) {
        out_vertices[out_index].uv_.x = attributes.texcoords[2 * index.texcoord_index + 0];
        out_vertices[out_index].uv_.y = attributes.texcoords[2 * index.texcoord_index + 1];
      }
    }
  }
}

void LoadWavefront(const std::filesystem::path &path) {
  tinyobj::ObjReader reader;
  tinyobj::ObjReaderConfig reader_config;

  auto status = reader.ParseFromFile(path.string(), reader_config);

  auto &shapes = reader.GetShapes();
  auto &attributes = reader.GetAttrib();
}

} // namespace Terabithia