#include "mesh_allocator.h"

namespace Terabithia {

MeshAllocator::MeshAllocator()
  : vertex_arrays_{VertexArray(), VertexArray()},
    vertex_buffers_{VertexBuffer(32_MiB, Vertex::GetFormat()),
                    VertexBuffer(32_MiB, Vertex::GetFormat())},
    index_buffer_(BufferTarget::ELEMENT_ARRAY_BUFFER, 32_MiB) {}

std::optional<std::size_t> MeshAllocator::GetOffsetInVertexBuffer(const Mesh &mesh) {}

std::optional<std::size_t> MeshAllocator::GetOffsetInIndexBuffer(const Mesh &mesh) {}

} // namespace Terabithia