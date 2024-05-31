#ifndef MODEL_H
#define MODEL_H

#include "mesh.h"

namespace Terabithia {

class Model {
public:
  Model() = default;

  Model(PrimitiveMeshType primitive);

private:
  std::shared_ptr<Mesh> mesh_;
};

} // namespace Terabithia

#endif // MODEL_H