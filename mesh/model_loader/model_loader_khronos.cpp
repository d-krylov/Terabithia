#include "fastgltf/core.hpp"
#include "fastgltf/tools.hpp"
#include "fastgltf/types.hpp"
#include "model_loader.h"

namespace Terabithia {

void LoadGLTF(const std::filesystem::path &path) {
  fastgltf::Parser parser{};
  fastgltf::GltfDataBuffer data;
  data.loadFromFile(path);
  auto type = fastgltf::determineGltfFileType(&data);

  fastgltf::Options options{};

  fastgltf::Asset asset;

  if (type == fastgltf::GltfType::glTF) {
    auto opt_asset = parser.loadGltf(&data, path.parent_path(), options);
    if (opt_asset) {
      asset = std::move(opt_asset.get());
    }
  } else if (type == fastgltf::GltfType::GLB) {
    auto opt_asset = parser.loadGltfBinary(&data, path.parent_path(), options);
    if (opt_asset) {
      asset = std::move(opt_asset.get());
    }
  } else {
  }

  for (auto &mesh : asset.meshes) {
    for (auto &&p : mesh.primitives) {
      {
        auto &index_accessor = asset.accessors[p.indicesAccessor.value()];
        auto index_callback = [&](std::uint32_t idx) {};
        fastgltf::iterateAccessor<std::uint32_t>(asset, index_accessor, index_callback);
      }
    }
  }
}

} // namespace Terabithia