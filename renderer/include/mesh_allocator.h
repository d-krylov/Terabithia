#ifndef MESH_ALLOCATOR_H
#define MESH_ALLOCATOR_H

#include "graphics.h"
#include "mesh.h"
#include <unordered_map>

namespace Terabithia {

constexpr uint32_t BUFFERS_COUNT = 2;

class MeshAllocator {
public:
  MeshAllocator();

  [[nodiscard]] std::optional<std::size_t> GetOffsetInVertexBuffer(const Mesh &mesh);
  [[nodiscard]] std::optional<std::size_t> GetOffsetInIndexBuffer(const Mesh &mesh);

private:
  std::array<VertexArray, BUFFERS_COUNT> vertex_arrays_;
  std::array<VertexBuffer, BUFFERS_COUNT> vertex_buffers_;
  Buffer index_buffer_;
};

} // namespace Terabithia

#endif // MESH_ALLOCATOR_H