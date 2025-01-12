#ifndef TERABITHIA_MESH_H
#define TERABITHIA_MESH_H

#include "mathematics/include/mathematical_types.h"

namespace Terabithia {

struct PlainVertex {
  Vector3f position_;
  Vector3f normal_;
};

struct TexturedVertex {
  Vector3f position_;
  Vector3f normal_;
  Vector2f uv_;
};

struct ColoredVertex {
  Vector3f position_;
  Vector3f normal_;
  Vector3f color_;
};

struct Vertex {
  Vector3f position_;
  Vector3f normal_;
  Vector2f uv_;
  Vector3f tangent_;
  Vector3f bitangent_;
};

} // namespace Terabithia

#endif // TERABITHIA_MESH_H