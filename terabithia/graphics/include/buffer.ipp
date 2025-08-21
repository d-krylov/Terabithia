#ifndef TERABITHIA_BUFFER_IPP
#define TERABITHIA_BUFFER_IPP

namespace Terabithia {

template <typename T>
std::span<T> Buffer::GetMappedBufferData() {
  auto raw_data = reinterpret_cast<T *>(mapped_buffer_data_.data());
  auto new_size = mapped_buffer_data_.size() / sizeof(T);
  return std::span<T>(raw_data, new_size);
}

} // namespace Terabithia

#endif // TERABITHIA_BUFFER_IPP