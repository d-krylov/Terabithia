#include "mesh.h"
#include "tinyobjloader/tiny_obj_loader.h"

namespace Terabithia {

Mesh::Mesh(PrimitiveMeshType primitive) {}

void Mesh::LoadOBJ(const std::filesystem::path &path) {
  tinyobj::ObjReader reader;
  tinyobj::ObjReaderConfig reader_config;

  auto status = reader.ParseFromFile(path.string(), reader_config);

  auto &attributes = reader.GetAttrib();
  auto &shapes = reader.GetShapes();
  auto &materials = reader.GetMaterials();
}

} // namespace Terabithia