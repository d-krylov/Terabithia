#include "buffer.h"
#include "tools.h"

namespace Terabithia {

Buffer::Buffer(BufferTarget target, std::size_t size, BufferStorage storage)
  : target_(target), buffer_size_(size), storage_(storage) {
  CreateBuffer();
}

Buffer::~Buffer() { Destroy(); }

void Buffer::CreateBuffer() {
  glCreateBuffers(1, &buffer_);
  glNamedBufferStorage(buffer_, buffer_size_, nullptr, static_cast<uint16_t>(storage_));
}

void Buffer::Destroy() { glDeleteBuffers(1, &buffer_); }

void Buffer::MapRange(std::size_t offset, std::size_t size) {
  CORE_VERIFY(mapped_data_.empty() == true);
  CORE_VERIFY(offset + size <= buffer_size_);
  auto *raw = glMapNamedBufferRange(buffer_, offset, size, static_cast<uint16_t>(storage_));
  CORE_VERIFY(raw != nullptr);
  mapped_data_ = std::span<std::byte>(ToBytePointer(raw), size);
}

void Buffer::Unmap() {
  CORE_VERIFY(mapped_data_.empty() == false);
  auto result = glUnmapNamedBuffer(buffer_);
  CORE_VERIFY(result == GL_TRUE);
  mapped_data_ = {};
}

void Buffer::FlushRange(std::size_t offset, std::size_t size) {
  CORE_VERIFY(offset + size <= buffer_size_);
  glFlushMappedNamedBufferRange(buffer_, offset, size);
}

void Buffer::Reset() { buffer_offset_ = 0; }

std::size_t Buffer::PushData(std::span<const std::byte> raw) {
  CORE_VERIFY(storage_ == BufferStorage::DYNAMIC_STORAGE);
  CORE_VERIFY(buffer_offset_ + raw.size() <= buffer_size_);
  glNamedBufferSubData(buffer_, buffer_offset_, raw.size(), raw.data());
  auto ret = GetOffset();
  buffer_offset_ += raw.size();
  return ret;
}

void Buffer::Bind() { glBindBuffer(static_cast<uint16_t>(target_), buffer_); }

void Buffer::BindRange(uint32_t index, int64_t offset, uint64_t size) {
  size = (size == WHOLE_SIZE) ? buffer_size_ : size;
  glBindBufferRange(static_cast<uint16_t>(target_), index, buffer_, offset, size);
}

void Buffer::Resize(std::size_t size) {
  Destroy();
  buffer_size_ = size;
  CreateBuffer();
}

} // namespace Terabithia