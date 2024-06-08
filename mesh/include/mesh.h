#ifndef MESH_H
#define MESH_H

#include "UUID.h"
#include "material.h"
#include "mesh_factory.h"
#include "vertex.h"

namespace Terabithia {

enum class PrimitiveMeshType {
  NONE,
  BOX,
  SPHERE,
  PLANE,
  TERRAIN,
  CYLINDER,
  CONE,
  TORUS,
  CAPSULE
};

class Mesh {
public:
  Mesh() = default;

  Mesh(PrimitiveMeshType primitive);

  NO_COPY_SEMANTIC(Mesh);

  void GetNormals();

  const std::vector<Vertex> &GetVertices() const { return vertices_; }
  const std::vector<uint32_t> &GetIndices() const { return indices_; }

  void AddVertex(const Vertex &vertex);

  UUID GetUUID() const { return uuid_; }

  [[nodiscard]] bool HasIndices() const { return false; }

private:
  std::vector<Vertex> vertices_;
  std::vector<uint32_t> indices_;
  std::vector<uint32_t> submesh_offsets_;
  UUID uuid_;
};

} // namespace Terabithia

#endif // MESH_H