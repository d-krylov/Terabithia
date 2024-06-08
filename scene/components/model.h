#ifndef MODEL_H
#define MODEL_H

#include "mesh.h"

namespace Terabithia {

class Model {
public:
  NO_COPY_SEMANTIC(Model);

  Model(PrimitiveMeshType primitive);
  Model(const std::filesystem::path &path);

  [[nodiscard]] std::shared_ptr<Mesh> GetMesh() const { return mesh_; }
  [[nodiscard]] const std::filesystem::path &GetPath() const { return path_; }

protected:
  void CreatePrimitive();

private:
  std::shared_ptr<Mesh> mesh_;
  std::filesystem::path path_;
};

} // namespace Terabithia

#endif // MODEL_H