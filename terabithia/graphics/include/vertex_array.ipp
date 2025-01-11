#ifndef TERABITHIA_VERTEX_ARRAY_IPP
#define TERABITHIA_VERTEX_ARRAY_IPP

namespace Terabithia {

inline void VertexArray::SetVertexBuffer(const GL::DescriptorType &vbo, int32_t stride, uint32_t binding, int64_t offset) {
  GL::SetVertexBuffer(vertex_array_, vbo, binding, stride, offset);
}

template <ContiguousSizedRangeT<Format> R> inline uint32_t VertexArray::SetVertexFormat(R &&formats, uint32_t binding) {
  uint32_t offset = 0;
  for (uint32_t index = 0; index < std::ranges::size(formats); index++) {
    auto [count, size, type, normalized] = GetFormatInformation(formats[index]);
    auto flag = normalized || type == PrimitiveFormat::FLOAT;
    GL::EnableAttribute(vertex_array_, index + binding);
    flag ? GL::SetAttributeFormat(vertex_array_, index, count, type, offset, normalized)
         : GL::SetAttributeFormat(vertex_array_, index, count, type, offset);
    GL::SetAttributeBinding(vertex_array_, index + binding, binding);
    GL::SetBindingDivisor(vertex_array_, index + binding, 0);
    offset += count * size;
  }
  return offset;
}

} // namespace Terabithia

#endif // TERABITHIA_VERTEX_ARRAY_IPP