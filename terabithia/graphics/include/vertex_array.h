#ifndef TERABITHIA_VERTEX_ARRAY_H
#define TERABITHIA_VERTEX_ARRAY_H

#include "graphics_wrappers.h"

namespace Terabithia {

class VertexArray {
public:
  VertexArray() { GL::CreateVertexArray(vertex_array_); }

  ~VertexArray() { GL::DeleteVertexArray(vertex_array_); }

  void Bind() { GL::BindVertexArray(vertex_array_); }

  void SetIndexBuffer(const GL::DescriptorType &ebo) { GL::SetElementBuffer(vertex_array_, ebo); }

  void SetVertexBuffer(const GL::DescriptorType &vbo, int32_t stride, uint32_t binding = 0, int64_t offset = 0);

  template <ContiguousSizedRangeT<Format> R> uint32_t SetVertexFormat(R &&formats, uint32_t binding = 0);

  operator GL::DescriptorType() const { return vertex_array_; }

private:
  GL::DescriptorType vertex_array_{0};
};

} // namespace Terabithia

#include "vertex_array.ipp"

#endif // TERABITHIA_VERTEX_ARRAY_H