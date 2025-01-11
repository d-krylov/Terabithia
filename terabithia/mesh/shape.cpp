#include "mesh/include/shape.h"

namespace Terabithia {

std::vector<float> MakeBox() {
  return std::vector<float>{
#define DEFINE_HEXAHEDRON_VERTICES
#include "hexahedron.def"
  };
}

} // namespace Terabithia