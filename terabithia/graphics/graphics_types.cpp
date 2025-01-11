#include "graphics/include/graphics_types.h"
#include <unordered_map>

namespace Terabithia {

// clang-format off
template <typename T> PrimitiveFormat GetPrimitiveFormat() {
  if constexpr (std::same_as<T, float>)    return PrimitiveFormat::FLOAT;
  if constexpr (std::same_as<T, double>)   return PrimitiveFormat::DOUBLE;
  if constexpr (std::same_as<T, int32_t>)  return PrimitiveFormat::INT;
  if constexpr (std::same_as<T, uint32_t>) return PrimitiveFormat::UNSIGNED_INT;
  if constexpr (std::same_as<T, uint8_t>)  return PrimitiveFormat::UNSIGNED_BYTE;
  if constexpr (std::same_as<T, int8_t>)   return PrimitiveFormat::BYTE;
}
// clang-format on

std::unordered_map<InternalFormat, PixelInformation> pixel_information{
#define TEXTURE_FORMAT(X, Y, Z) {InternalFormat::X, {PixelFormat::Y, PixelType::Z}},
#include "graphics/include/graphics_types.def"
};

std::unordered_map<Format, FormatInformation> format_information{
#define FORMAT(X, Y, Z, W) {Format::X, {Y, sizeof(Z), GetPrimitiveFormat<Z>(), W}},
#include "graphics/include/graphics_types.def"
};

const PixelInformation &GetPixelInformation(InternalFormat format) { return pixel_information[format]; }
const FormatInformation &GetFormatInformation(Format format) { return format_information[format]; }

bool IsTextureLayered(TextureTarget target) {
  auto result = false;
  switch (target) {
  case TextureTarget::TEXTURE_1D_ARRAY:
  case TextureTarget::TEXTURE_2D_ARRAY:
  case TextureTarget::TEXTURE_CUBE_MAP_ARRAY:
  case TextureTarget::TEXTURE_2D_MULTISAMPLE_ARRAY:
    result = true;
    break;
  default:
    break;
  }
  return result;
}

uint32_t GetTextureDimensions(TextureTarget target) {
  auto result{0};
  switch (target) {
  case TextureTarget::TEXTURE_1D:
    return 1;
  case TextureTarget::TEXTURE_2D:
  case TextureTarget::TEXTURE_2D_MULTISAMPLE:
  case TextureTarget::TEXTURE_1D_ARRAY:
  case TextureTarget::TEXTURE_RECTANGLE:
  case TextureTarget::TEXTURE_CUBE_MAP:
    return 2;
  case TextureTarget::TEXTURE_3D:
  case TextureTarget::TEXTURE_2D_ARRAY:
  case TextureTarget::TEXTURE_CUBE_MAP_ARRAY:
  case TextureTarget::TEXTURE_2D_MULTISAMPLE_ARRAY:
    return 3;
  default:
    break;
  }
  return result;
}

} // namespace Terabithia