#ifndef VERTEX_FORMAT_H
#define VERTEX_FORMAT_H

#include "vertex_attribute.h"
#include <initializer_list>
#include <vector>

namespace Terabithia {

class VertexFormat {
public:
  VertexFormat(const std::initializer_list<VertexAttribute> &attributes);

  [[nodiscard]] std::size_t GetStride() const { return stride_; }

  [[nodiscard]] const std::vector<VertexAttribute> &GetAttributes() const {
    return attributes_;
  }

protected:
  void AddAttribute(const VertexAttribute &attributed);

private:
  std::size_t stride_{0};
  std::vector<VertexAttribute> attributes_;
};

} // namespace Terabithia

#endif // VERTEX_FORMAT_H