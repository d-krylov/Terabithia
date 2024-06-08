#include "mesh_allocator.h"
#include "shader_library.h"

namespace Terabithia {

MeshAllocator::MeshAllocator()
  : vertex_array_(), vertex_buffer_(128_MiB, Vertex::GetFormat()),
    index_buffer_(BufferTarget::ELEMENT_ARRAY_BUFFER, 128_MiB),
    ssbo_buffer_(BufferTarget::SHADER_STORAGE_BUFFER, 32_MiB) {}

std::optional<std::size_t> MeshAllocator::GetOffsetInVBO(const Mesh &mesh) {
  auto uuid = mesh.GetUUID();
  return (vbo_offsets_.contains(uuid)) ? vbo_offsets_[uuid] : std::optional<std::size_t>{};
}

std::optional<std::size_t> MeshAllocator::GetOffsetInIBO(const Mesh &mesh) {
  auto uuid = mesh.GetUUID();
  return (ibo_offsets_.contains(uuid)) ? ibo_offsets_[uuid] : std::optional<std::size_t>{};
}

bool MeshAllocator::IsInVBO(const Mesh &mesh) const {
  return vbo_offsets_.contains(mesh.GetUUID());
}

bool MeshAllocator::IsInIBO(const Mesh &mesh) const {
  return ibo_offsets_.contains(mesh.GetUUID());
}

void MeshAllocator::PushMesh(const Mesh &mesh) {
  auto byte_offset = vertex_buffer_.PushData(mesh.GetVertices());
  auto uuid = mesh.GetUUID();
  vbo_offsets_[uuid] = byte_offset / sizeof(Vertex);
}

void MeshAllocator::OnDrawMesh() {
  ShaderLibrary::Get().GetCore().Bind();
  vertex_array_.Bind();
  ssbo_buffer_.Bind();
}

} // namespace Terabithia