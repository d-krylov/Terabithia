#ifndef MODEL_LOADER_H
#define MODEL_LOADER_H

#include "mesh.h"
#include "vertex.h"

namespace Terabithia {

void LoadOBJ(const std::filesystem::path &path, Mesh &mesh);

} // namespace Terabithia

#endif // MODEL_LOADER_H