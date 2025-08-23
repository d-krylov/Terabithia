#include "shapes.h"

namespace Terabithia {

std::vector<Vector3f> GetHexahedronVertices(float size_x, float size_y, float size_z) {
  return std::vector<Vector3f>{
    {-size_x, -size_y, +size_z}, // FRONT LEFT BOTTOM
    {+size_x, -size_y, +size_z}, // FRONT RIGTH BOTTOM
    {+size_x, +size_y, +size_z}, // FRONT RIGHT TOP
    {-size_x, +size_y, +size_z}, // FRONT LEFT TOP
    {-size_x, -size_y, -size_z}, // BACK LEFT BOTTOM
    {+size_x, -size_y, -size_z}, // BACK RIGTH BOTTOM
    {+size_x, +size_y, -size_z}, // BACK RIGHT TOP
    {-size_x, +size_y, -size_z}  // BACK LEFT TOP
  };
}

std::vector<Vector3i> GetHexahedronIndices() {
  return std::vector<Vector3i>{
    {0, 1, 2}, {2, 3, 0}, // FRONT
    {1, 5, 6}, {6, 2, 1}, // RIGHT
    {5, 4, 7}, {7, 6, 5}, // BACK
    {4, 0, 3}, {3, 7, 4}, // LEFT
    {3, 2, 6}, {6, 7, 3}, // TOP
    {4, 5, 1}, {1, 0, 4}  // BOTTOM
  };
}

std::vector<Vertex> MakeHexahedron(float size_x, float size_y, float size_z) {
  auto result = std::vector<Vertex>();
  auto vertices = GetHexahedronVertices(size_x, size_y, size_z);
  auto indices = GetHexahedronIndices();
  for (const auto &tringle : indices) {
    auto v0 = vertices[tringle.x];
    auto v1 = vertices[tringle.y];
    auto v2 = vertices[tringle.z];
    auto normal = glm::normalize(glm::cross(v1 - v0, v2 - v0));
    result.emplace_back(v0, normal);
    result.emplace_back(v1, normal);
    result.emplace_back(v2, normal);
  }
  return result;
}

void MakeTerrain() {
}

} // namespace Terabithia