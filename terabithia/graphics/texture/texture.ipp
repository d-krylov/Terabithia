#ifndef TERABITHIA_TEXTURE_IPP
#define TERABITHIA_TEXTURE_IPP

#include <cmath>

namespace Terabithia {

template <ContiguousSizedRange R>
inline Texture::Texture(int32_t width, int32_t height, InternalFormat format, R &&data)
  : Texture(width, height, 1, TextureTarget::TEXTURE_2D, format, false, MinFilter::LINEAR, MagFilter::LINEAR, WrapMode::CLAMP_TO_EDGE) {
  SetData(std::forward<R>(data));
}

inline Texture::Texture(int32_t width, int32_t height, int32_t depth, TextureTarget target, InternalFormat format, bool mipmap,
                        MinFilter min, MagFilter mag, const Wrap &wrap)
  : size_{width, height, depth}, target_(target), internal_format_(format) {
  GL::CreateTexture(texture_, target);
  CreateStorage();
}

template <ContiguousSizedRange R> inline void Texture::SetData(R &&data, int32_t level, int32_t x, int32_t y, int32_t z) {
  auto [pixel_format, pixel_type] = GetPixelInformation();
  auto dimensions = GetDimensions();
  switch (dimensions) {
  case 1:
    GL::TextureSubImage(texture_, size_.w, pixel_format, pixel_type, std::forward<R>(data), x, level);
    break;
  case 2:
    GL::TextureSubImage(texture_, size_.w, size_.h, pixel_format, pixel_type, std::forward<R>(data), x, y, level);
    break;
  case 3:
    GL::TextureSubImage(texture_, size_.w, size_.h, size_.d, pixel_format, pixel_type, std::forward<R>(data), x, y, z, level);
    break;
  default:
    break;
  }
}

inline void Texture::CreateStorage() {
  auto dimensions = GetDimensions();
  switch (dimensions) {
  case 1:
    GL::CreateTextureStorage(texture_, levels_, internal_format_, size_.w);
    break;
  case 2:
    GL::CreateTextureStorage(texture_, levels_, internal_format_, size_.w, size_.h);
    break;
  case 3:
    GL::CreateTextureStorage(texture_, levels_, internal_format_, size_.w, size_.h, size_.d);
    break;
  default:
    break;
  }
}

inline void Texture::SetParameters(MagFilter mag, MinFilter min, const Wrap &wrap) {}

inline uint32_t GetMipLevels(int32_t x, int32_t y, int32_t z) {
  auto m = std::max(x, std::max(y, z));
  return static_cast<uint32_t>(std::floor(std::log2(m))) + 1;
}

} // namespace Terabithia

#endif // TERABITHIA_TEXTURE_IPP