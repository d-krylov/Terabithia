#ifndef MESH_ALLOCATOR_H
#define MESH_ALLOCATOR_H

#include "graphics.h"
#include "mesh.h"
#include <unordered_map>

namespace Terabithia {

class MeshAllocator {
public:
  MeshAllocator();

  [[nodiscard]] std::optional<std::size_t> GetOffsetInVBO(const Mesh &mesh);
  [[nodiscard]] std::optional<std::size_t> GetOffsetInIBO(const Mesh &mesh);

  [[nodiscard]] bool IsInVBO(const Mesh &mesh) const;
  [[nodiscard]] bool IsInIBO(const Mesh &mesh) const;

  void PushMesh(const Mesh &mesh);

  void OnDrawMesh();

private:
  VertexArray vertex_array_;
  VertexBuffer vertex_buffer_;
  Buffer index_buffer_;
  Buffer ssbo_buffer_;
  std::unordered_map<uint64_t, std::size_t> vbo_offsets_;
  std::unordered_map<uint64_t, std::size_t> ibo_offsets_;
};

} // namespace Terabithia

#endif // MESH_ALLOCATOR_H