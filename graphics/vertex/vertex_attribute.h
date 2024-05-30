#ifndef VERTEX_ATTRIBUTE_H
#define VERTEX_ATTRIBUTE_H

#include "graphics_types.h"

namespace Terabithia {

class VertexFormat;

class VertexAttribute {
public:
  VertexAttribute(DataType type, bool normalize = false,
                  AttributeUsage usage = AttributeUsage::NONE)
    : type_(type), normalize_(normalize), attribute_usage_(usage) {}

  [[nodiscard]] DataType GetDataType() const { return type_; }
  [[nodiscard]] AttributeUsage GetUsage() const { return attribute_usage_; }
  [[nodiscard]] std::size_t GetSize() const { return Terabithia::GetSize(type_); }
  [[nodiscard]] bool IsFloat() const { return (GetComponentType() == CoreType::FLOAT); }
  [[nodiscard]] bool IsRGBA() const { return (GetDataType() == DataType::PACKED_RGBA); }

  [[nodiscard]] std::size_t GetComponentCount() const {
    return Terabithia::GetComponentCount(type_);
  }

  [[nodiscard]] CoreType GetComponentType() const {
    return Terabithia::GetComponentType(type_);
  }

  [[nodiscard]] bool IsDouble() const { return (GetComponentType() == CoreType::DOUBLE); }

  [[nodiscard]] bool Normalize() const { return normalize_; }
  [[nodiscard]] std::size_t GetOffset() const { return offset_; }

private:
  DataType type_;
  AttributeUsage attribute_usage_;
  bool normalize_{false};
  std::size_t offset_{0};
  friend class VertexFormat;
};

} // namespace Terabithia

#endif // VERTEX_ATTRIBUTE_H