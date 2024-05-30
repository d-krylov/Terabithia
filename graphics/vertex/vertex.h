#ifndef VERTEX_H
#define VERTEX_H

#include "graphics_types.h"
#include "vertex_format.h"

namespace Terabithia {

struct Vertex {
  Vector3f position_{0.0f};
  Vector3f normal_{0.0f};
  Vector2f uv_{0.0f};

  static VertexFormat GetFormat() {
    return VertexFormat({DataType::VECTOR3, DataType::VECTOR3, DataType::VECTOR2});
  }
};

struct ExtendedVertex {
  Vector3f position_{0.0f};
  Vector3f normal_{0.0f};
  Vector2f uv_{0.0f};
  Vector3f tangent_{0.0f};
  Vector3f bitangent_{0.0f};

  static VertexFormat GetFormat() {
    return VertexFormat({DataType::VECTOR3, DataType::VECTOR3, DataType::VECTOR2,
                         DataType::VECTOR3, DataType::VECTOR3});
  }
};

} // namespace Terabithia

#endif // VERTEX_H