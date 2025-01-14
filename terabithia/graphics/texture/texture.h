#ifndef TERABITHIA_TEXTURE_H
#define TERABITHIA_TEXTURE_H

#include "graphics/include/graphics_wrappers.h"
#include "core/include/macros.h"
#include "core/include/image.h"

namespace Terabithia {

class Texture {
public:
  Texture(int32_t w, int32_t h, int32_t d, TextureTarget target, InternalFormat format, bool mipmap, MinFilter min, MagFilter mag,
          const Wrap &wrap);

  Texture(const ImageWrapper &image_wrapper, bool mipmap = false);

  template <ContiguousSizedRange R> Texture(int32_t width, int32_t height, InternalFormat format, R &&data);

  ~Texture() { GL::DeleteTexture(texture_); }

  operator GL::DescriptorType() const { return texture_; }

  InternalFormat GetFormat() const { return internal_format_; }
  bool IsLayered() const { return IsTextureLayered(target_); }
  uint32_t GetDimensions() { return GetTextureDimensions(target_); }
  PixelInformation GetPixelInformation() { return Terabithia::GetPixelInformation(internal_format_); }

  int32_t GetWidth() const { return size_.w; }
  int32_t GetHeight() const { return size_.h; }
  int32_t GetDepth() const { return size_.d; }
  const Extent3i &GetSize() const { return size_; }

  uint64_t GetHandleARB() const;

  template <ContiguousSizedRange R>
  void SetData(R &&data, int32_t level = 0, int32_t xoffset = 0, int32_t yoffset = 0, int32_t zoffset = 0);

  void Bind(uint32_t unit) { GL::BindTextureUnit(texture_, unit); }

protected:
  void CreateStorage();
  void SetParameters(MagFilter mag, MinFilter min, const Wrap &wrap);

private:
  GL::DescriptorType texture_{0};
  TextureTarget target_;
  InternalFormat internal_format_;
  int32_t levels_{1};
  Extent3i size_;
};

} // namespace Terabithia

#include "texture.ipp"

#endif // TERABITHIA_TEXTURE_H