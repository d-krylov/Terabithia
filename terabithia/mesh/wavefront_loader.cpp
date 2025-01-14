#define TINYOBJLOADER_IMPLEMENTATION
#include "tiny_obj_loader.h"
#include "mesh/include/mesh_loader.h"
#include "graphics/texture/texture.h"
#include <unordered_map>
#include <span>

namespace Terabithia {

bool HasSmoothingGroup(const tinyobj::shape_t &shape) {
  return std::any_of(shape.mesh.smoothing_group_ids.begin(), shape.mesh.smoothing_group_ids.end(), [](auto id) { return id > 0; });
}

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

std::unordered_map<std::string, Texture> LoadMaterials(const std::filesystem::path image_root,
                                                       std::span<const tinyobj::material_t> materials) {
  std::unordered_map<std::string, Texture> textures;

  for (const auto &material : materials) {
    if (material.ambient_texname.size() > 0) {
      if (textures.contains(material.ambient_texname) == false) {
        textures.emplace(material.ambient_texname, Texture(image_root / material.ambient_texname));
      }
    }

    if (material.diffuse_texname.size() > 0) {
      if (textures.contains(material.diffuse_texname) == false) {
        textures.emplace(material.diffuse_texname, Texture(image_root / material.diffuse_texname));
      }
    }

    if (material.specular_texname.size() > 0) {
      if (textures.contains(material.specular_texname) == false) {
        textures.emplace(material.specular_texname, Texture(image_root / material.specular_texname));
      }
    }

    if (material.bump_texname.size() > 0) {
      if (textures.contains(material.bump_texname) == false) {
        textures.emplace(material.bump_texname, Texture(image_root / material.bump_texname));
      }
    }

    if (material.metallic_texname.size() > 0) {
      if (textures.contains(material.metallic_texname) == false) {
        textures.emplace(material.metallic_texname, Texture(image_root / material.metallic_texname));
      }
    }

    if (material.roughness_texname.size() > 0) {
      if (textures.contains(material.roughness_texname) == false) {
        textures.emplace(material.roughness_texname, Texture(image_root / material.roughness_texname));
      }
    }
  }

  return textures;
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