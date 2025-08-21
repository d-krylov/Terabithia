#ifndef TERABITHIA_VERTEX_ARRAY_H
#define TERABITHIA_VERTEX_ARRAY_H

#include "graphics_types.h"

namespace Terabithia {

class VertexArray {
public:
  VertexArray();

  ~VertexArray();

  VertexArray(const VertexArray &) = delete;

  VertexArray &operator=(const VertexArray &) = delete;

  VertexArray(VertexArray &&other) noexcept;

  VertexArray &operator=(VertexArray &&other) noexcept;

  void SetAttributes(std::span<const AttributeType> attributes);

  void Bind();

  Handle GetHandle() const;

private:
  Descriptor vertex_array_{0};
};

} // namespace Terabithia

#endif // TERABITHIA_VERTEX_ARRAY_H