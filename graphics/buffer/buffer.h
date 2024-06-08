#ifndef BUFFER_H
#define BUFFER_H

#include "graphics_types.h"
#include <span>
#include <vector>

namespace Terabithia {

class Buffer {
public:
  Buffer(BufferTarget target, std::size_t size,
         BufferStorage storage = BufferStorage::DYNAMIC_STORAGE);

  ~Buffer();

  NO_COPY_SEMANTIC(Buffer);

  template <typename T> std::size_t PushData(std::span<T> data) {
    return PushData(std::as_bytes(data));
  }

  template <typename T> std::size_t PushData(const std::vector<T> &data) {
    std::span<const T> span_data(data.data(), data.size());
    return PushData(std::as_bytes(span_data));
  }

  std::size_t PushData(std::span<const std::byte> data);
  void FlushRange(std::size_t offset, std::size_t size);
  void MapRange(std::size_t offset, std::size_t size);
  void Unmap();

  void Bind();
  void BindRange(uint32_t index, int64_t offset = 0, uint64_t size = WHOLE_SIZE);

  operator Handle() const { return buffer_; }

  [[nodiscard]] std::size_t GetSize() const { return buffer_size_; }
  [[nodiscard]] std::size_t GetOffset() const { return buffer_offset_; }
  [[nodiscard]] BufferTarget GetTarget() const { return target_; }
  [[nodiscard]] BufferStorage GetStorage() const { return storage_; }

  template <typename T> std::span<T> MapRange(std::size_t offset, std::size_t count) {
    auto byte_offset = offset * sizeof(T);
    auto byte_count = count * sizeof(T);
    auto raw = reinterpret_cast<T *>(mapped_data_.data());
    return std::span<T>(raw, mapped_data_.size_bytes() / sizeof(T));
  }

  void Resize(std::size_t size);
  void Reset();

protected:
  void Destroy();
  void CreateBuffer();

private:
  Handle buffer_{0};
  BufferTarget target_;
  BufferStorage storage_{BufferStorage::DYNAMIC_STORAGE};
  std::size_t buffer_size_{0};
  std::size_t buffer_offset_{0};
  std::span<std::byte> mapped_data_;
};

} // namespace Terabithia

#endif // BUFFER_H