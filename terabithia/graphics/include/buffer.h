#ifndef TERABITHIA_BUFFER_H
#define TERABITHIA_BUFFER_H

#include "graphics_types.h"
#include <span>

namespace Terabithia {

class Buffer {
public:
  Buffer(std::size_t size, BufferStorageMask storage_mask);

  ~Buffer();

  template <typename T>
  std::span<T> GetMappedBufferData();

  std::size_t GetBufferSize() const;

  void MapRange(int64_t offset, int64_t size, MapBufferAccessMask map_access_mask);

  void Map(MapBufferAccess map_access);

  void Unmap();

  Handle GetHandle() const;

private:
  Descriptor buffer_;
  std::size_t buffer_size_;
  std::span<std::byte> mapped_buffer_data_;
};

} // namespace Terabithia

#include "buffer.ipp"

#endif // TERABITHIA_BUFFER_H