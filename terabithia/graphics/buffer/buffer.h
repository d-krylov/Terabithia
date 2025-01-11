#ifndef TERABITHIA_BUFFER_H
#define TERABITHIA_BUFFER_H

#include "graphics/include/graphics_wrappers.h"
#include "core/include/macros.h"
#include <span>
#include <cstring>

namespace Terabithia {

template <BufferStorage S = BufferStorage::DYNAMIC_STORAGE> class Buffer {
public:
  Buffer(BufferTarget target, int64_t size);

  Buffer(const Buffer<S> &other) = delete;

  void operator=(const Buffer<S> &) = delete;

  Buffer(Buffer &&other) noexcept;

  Buffer &operator=(Buffer &&other);

  ~Buffer() { GL::DeleteBuffer(buffer_); }

  void Bind();

  void Bind(uint32_t index);

  uint64_t GetSize() const { return size_; }

  operator GL::DescriptorType() const { return buffer_; }

  // clang-format off

  [[nodiscard]] std::span<std::byte> GetMappedData() requires IsMapWrite<S>;

  template <ContiguousSizedRange R> void SetData(R &&source, int64_t offset = 0) requires IsDynamic<S>;

  template <PodType T, ContiguousSizedRangeT<T> R> void Memcpy(R &&source, int64_t offset = 0) requires IsMapWrite<S>;

  void Map(int64_t offset, int64_t size, MapAccess map_access = MapAccess::WRITE) requires IsMapWrite<S>;

  void Unmap() requires IsMapWrite<S>;

  // clang-format on

protected:
  GL::DescriptorType buffer_{0};
  std::span<std::byte> mapped_data_;
  BufferTarget target_;
  int64_t size_;
};

} // namespace Terabithia

#include "buffer.ipp"

#endif // TERABITHIA_BUFFER_H