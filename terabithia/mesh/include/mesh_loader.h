#ifndef TERABITHIA_MESH_LOADER_H
#define TERABITHIA_MESH_LOADER_H

#include <vector>
#include <filesystem>
#include "mesh.h"

namespace Terabithia {

std::vector<PlainVertex> LoadWavefront(const std::filesystem::path &path);

} // namespace Terabithia

#endif // TERABITHIA_MESH_LOADER_H