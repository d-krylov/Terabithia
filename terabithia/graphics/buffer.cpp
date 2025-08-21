#include "terabithia/graphics/include/buffer.h"
#include "terabithia/graphics/include/graphics_wrappers.h"
#include "terabithia/core/include/core.h"

namespace Terabithia {

Buffer::Buffer(std::size_t size, BufferStorageMask storage_mask) : buffer_size_(size) {
  CreateBuffer(buffer_);
  CreateBufferStorage(buffer_, storage_mask, buffer_size_);
}

Buffer::~Buffer() {
  DeleteBuffer(buffer_);
}

std::size_t Buffer::GetBufferSize() const {
  return buffer_size_;
}

Handle Buffer::GetHandle() const {
  return buffer_;
}

void Buffer::MapRange(int64_t offset, int64_t size, MapBufferAccessMask map_access_mask) {
  auto void_mapped = MapBufferRange(buffer_, offset, size, map_access_mask);
  auto byte_mapped = static_cast<std::byte *>(void_mapped);
  CORE_ASSERT(byte_mapped != nullptr, "Can't map buffer");
  mapped_buffer_data_ = std::span(byte_mapped, size);
}

void Buffer::Map(MapBufferAccess map_access) {
  auto void_mapped = MapBuffer(buffer_, map_access);
  auto byte_mapped = static_cast<std::byte *>(void_mapped);
  CORE_ASSERT(byte_mapped != nullptr, "Can't map buffer");
  mapped_buffer_data_ = std::span(byte_mapped, GetBufferSize());
}

void Buffer::Unmap() {
  CORE_ASSERT(mapped_buffer_data_.empty() == false, "Buffer isn't mapped");
  UnmapBuffer(buffer_);
  mapped_buffer_data_ = {};
}

} // namespace Terabithia