#ifndef TERABITHIA_MODEL_H
#define TERABITHIA_MODEL_H

#include "mesh.h"
#include <vector>
#include <filesystem>

namespace Terabithia {

class Model {
public:
private:
  std::vector<Vertex> vertices_;
};

} // namespace Terabithia

#endif // TERABITHIA_MODEL_H