#ifndef TERABITHIA_SHAPES_H
#define TERABITHIA_SHAPES_H

#include <vector>
#include "terabithia/mathematics/include/mathematics_types.h"

namespace Terabithia {

struct Vertex {
  Vector3f position;
  Vector3f normal;
};

std::vector<Vertex> MakeHexahedron(float size_x, float size_y, float size_z);

} // namespace Terabithia

#endif // TERABITHIA_SHAPES_H