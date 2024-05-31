#ifndef MESH_H
#define MESH_H

#include "material.h"
#include "mesh_factory.h"
#include "vertex.h"

namespace Terabithia {

enum class PrimitiveMeshType { CUBE, SPHERE, PLANE, TERRAIN, CYLINDER };

class Mesh {
public:
  Mesh() = default;

  Mesh(PrimitiveMeshType primitive);

  NO_COPY_SEMANTIC(Mesh);

  void LoadOBJ(const std::filesystem::path &path);

  void GetNormal();

public:
  std::vector<Vertex> vertices_;
  std::vector<uint32_t> indices_;
  uint32_t buffer_offset_{0};
  uint32_t buffer_handle_{0};

  std::filesystem::path path_;
};

} // namespace Terabithia

#endif // MESH_H