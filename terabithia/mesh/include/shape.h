#ifndef TERABITHIA_SHAPE_H
#define TERABITHIA_SHAPE_H

#include <vector>
#include <span>
#include "mesh.h"

namespace Terabithia {

std::vector<float> MakeBox();

std::vector<PlainVertex> MakeIcosahedron();
std::vector<PlainVertex> MakeDodecahedron();

template <typename T> inline std::vector<T> GetVerticesWithNormals(std::span<Vector3f> vertices, std::span<const uint32_t> indices) {
  std::vector<T> result(indices.size());
  for (uint32_t i = 0; i < indices.size(); i += 3) {
    auto v0 = vertices[indices[i + 0]];
    auto v1 = vertices[indices[i + 1]];
    auto v2 = vertices[indices[i + 2]];
    auto normal = glm::normalize(glm::cross(v1 - v0, v2 - v0));
    result[i + 0] = T(v0, normal);
    result[i + 1] = T(v1, normal);
    result[i + 2] = T(v2, normal);
  }
  return result;
}

} // namespace Terabithia

#endif // TERABITHIA_SHAPE_H
