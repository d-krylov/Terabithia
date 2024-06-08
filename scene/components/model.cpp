#include "model.h"

namespace Terabithia {

Model::Model(PrimitiveMeshType primitive) {
  switch (primitive) {
  case PrimitiveMeshType::BOX:
    break;
  case PrimitiveMeshType::CAPSULE:
    break;
  case PrimitiveMeshType::CONE:
    break;
  case PrimitiveMeshType::CYLINDER:
    break;
  case PrimitiveMeshType::PLANE:
    break;
  case PrimitiveMeshType::SPHERE:
    break;
  case PrimitiveMeshType::TERRAIN:
    break;
  case PrimitiveMeshType::TORUS:
    break;
  default:
    break;
  }
}

Model::Model(const std::filesystem::path &path) : path_(path) {}

} // namespace Terabithia