#ifndef TERABITHIA_MODEL_H
#define TERABITHIA_MODEL_H

#include "mesh.h"
#include <filesystem>

namespace Terabithia {

class Model {
public:
private:
  std::vector<MeshVertex> vertices_;
  std::vector<Mesh> meshes_;
};

} // namespace Terabithia

#endif // TERABITHIA_MODEL_H