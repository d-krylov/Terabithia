#include "mesh.h"

namespace Terabithia {

Mesh::Mesh(PrimitiveMeshType primitive) {}

void Mesh::GetNormals() {}

void Mesh::AddVertex(const Vertex &vertex) { vertices_.emplace_back(vertex); }

} // namespace Terabithia