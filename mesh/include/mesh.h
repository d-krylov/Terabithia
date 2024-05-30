#ifndef MESH_H
#define MESH_H

#include "material.h"
#include "vertex.h"

namespace Terabithia {

class Mesh {
public:
  Mesh() = default;

  NO_COPY_SEMANTIC(Mesh);

  void Load(const std::filesystem::path &path);

  void GetNormal();

public:
  std::vector<Vertex> vertices_;
  uint32_t buffer_offset_{0};
  uint32_t buffer_handle_{0};
};

} // namespace Terabithia

#endif // MESH_H