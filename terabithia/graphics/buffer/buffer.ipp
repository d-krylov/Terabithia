#ifndef TERABITHIA_BUFFER_IPP
#define TERABITHIA_BUFFER_IPP

namespace Terabithia {

template <BufferStorage S> Buffer<S>::Buffer(Buffer &&other) noexcept {}

template <BufferStorage S> Buffer<S> &Buffer<S>::operator=(Buffer &&other) { return *this; }

template <BufferStorage S> inline void Buffer<S>::Bind() { GL::BindBuffer(buffer_, target_); }

template <BufferStorage S> inline void Buffer<S>::Bind(uint32_t index) { GL::BindBufferBase(buffer_, target_, index); }

template <BufferStorage S> inline Buffer<S>::Buffer(BufferTarget target, int64_t size) : target_(target), size_(size) {
  GL::CreateBuffer(buffer_);
  GL::CreateBufferStorage(buffer_, S, size);
}

// clang-format off

template <BufferStorage S>
inline std::span<std::byte> Buffer<S>::GetMappedData() requires IsMapWrite<S> {
  return mapped_data_;
}

template <BufferStorage S>
template <ContiguousSizedRange R>
inline void Buffer<S>::SetData(R &&source, int64_t offset) requires IsDynamic<S> {
  GL::SetBufferData<std::ranges::range_value_t<R>>(buffer_, offset, std::forward<R>(source));
}

template <BufferStorage S>
inline void Buffer<S>::Map(int64_t offset, int64_t size, MapAccess map_access) requires IsMapWrite<S> {
  auto mapped_data = GL::MapBuffer(buffer_, offset, size, map_access);

  if (mapped_data == nullptr) {

  }

  mapped_data_ = std::span(mapped_data, size);
}

template <BufferStorage S>
inline void Buffer<S>::Unmap() requires IsMapWrite<S> {
  auto status = GL::UnmapBuffer(buffer_);

  if (status == true) {
  
  }

  mapped_data_ = {};
}

template <BufferStorage S>
template <PodType T, ContiguousSizedRangeT<T> R>
inline void Buffer<S>::Memcpy(R &&source, int64_t offset) requires IsMapWrite<S> {
  std::memcpy(mapped_data_.subspan(offset).data(), std::ranges::data(source), sizeof(T) * std::ranges::size(source));
}

// clang-format on

} // namespace Terabithia

#endif // TERABITHIA_BUFFER_IPP