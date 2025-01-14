#include "mesh/include/shape.h"
#include <algorithm>

namespace Terabithia {

std::vector<float> MakeBox() {
  return std::vector<float>{
#define DEFINE_HEXAHEDRON_VERTICES
#include "hexahedron.def"
  };
}

std::vector<Vector3f> GetIcosahedronVertices() {
  float phi = (1.0f + std::sqrt(5.0f)) * 0.5f;
  float a = 0.5f;
  float b = 0.5f / phi;
  return std::vector<Vector3f>{
#define DEFINE_ICOSAHEDRON_VERTICES
#include "icosahedron.def"
  };
}

std::vector<uint32_t> GetIcosahedronIndices() {
  return std::vector<uint32_t>{
#define DEFINE_ICOSAHEDRON_INDICES
#include "icosahedron.def"
  };
}

std::vector<PlainVertex> MakeIcosahedron() {
  auto vertices = GetIcosahedronVertices();
  auto indices = GetIcosahedronIndices();
  return GetVerticesWithNormals<PlainVertex>(vertices, indices);
}

std::vector<Vector3f> GetDodecahedronVertices() {
  float b = 1.0f / PHI_;
  float c = 2.0f - PHI_;
  return std::vector<Vector3f>{
#define DEFINE_DODECAHEDRON_VERTICES
#include "dodecahedron.def"
  };
}

std::vector<uint32_t> GetDodecahedronIndices() {
  return std::vector<uint32_t>{
#define DEFINE_DODECAHEDRON_INDICES
#include "dodecahedron.def"
  };
}

std::vector<PlainVertex> MakeDodecahedron() {
  auto vertices = GetDodecahedronVertices();
  auto indices = GetDodecahedronIndices();
  return GetVerticesWithNormals<PlainVertex>(vertices, indices);
}

} // namespace Terabithia