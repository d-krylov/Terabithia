#include "terabithia/graphics/include/vertex_array.h"
#include "terabithia/graphics/include/graphics_wrappers.h"
#include <ranges>
#include <print>

namespace Terabithia {

VertexArray::VertexArray() {
  CreateVertexArray(vertex_array_);
}

VertexArray::~VertexArray() {
  DeleteVertexArray(vertex_array_);
}

VertexArray::VertexArray(VertexArray &&other) noexcept {
  vertex_array_ = std::move(other.vertex_array_);
}

VertexArray &VertexArray::operator=(VertexArray &&other) noexcept {
  vertex_array_ = std::move(other.vertex_array_);
  return *this;
}

void VertexArray::Bind() {
  BindVertexArray(vertex_array_);
}

Handle VertexArray::GetHandle() const {
  return vertex_array_;
}

void VertexArray::SetAttributes(std::span<const AttributeType> attributes) {
  auto offset = 0;
  for (const auto &[index, attribute] : std::views::enumerate(attributes)) {
    auto size = GetAttributeSize(attribute);
    auto type = GetVertexAttributeType(attribute);
    auto components = GetAttributeComponentsCount(attribute);
    switch (type) {
    case VertexAttributeType::FLOAT: VertexArrayAttributeFormat(vertex_array_, index, components, type, offset, false); break;
    case VertexAttributeType::DOUBLE: VertexArrayAttributeLFormat(vertex_array_, index, components, type, offset); break;
    case VertexAttributeType::UNSIGNED_INT:
    case VertexAttributeType::INT: VertexArrayAttributeIFormat(vertex_array_, index, components, type, offset); break;
    default: std::unreachable(); break;
    }

    EnableVertexArrayAttribute(vertex_array_, index);
    VertexArrayAttributeBinding(vertex_array_, index, 0);
    offset += size;
  }
}

} // namespace Terabithia