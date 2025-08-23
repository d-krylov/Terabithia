#ifndef TERABITHIA_MESH_H
#define TERABITHIA_MESH_H

#include "terabithia/mathematics/include/mathematics_types.h"
#include <string>
#include <vector>

namespace Terabithia {

struct MeshVertex {
  Vector3f position_;
  Vector3f normal_;
  Vector2f uv_;
};

struct Material {
  Vector3f ambient_;
  Vector3f diffuse_;
  Vector3f specular_;
};

struct Mesh {
  uint32_t vertices_offset_;
  uint32_t vertices_number_;
};

} // namespace Terabithia

#endif // TERABITHIA_MESH_H