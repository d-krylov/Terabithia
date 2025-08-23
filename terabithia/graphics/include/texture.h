#ifndef TERABITHIA_TEXTURE_H
#define TERABITHIA_TEXTURE_H

#include "graphics_types.h"

namespace Terabithia {

class TextureInformation {
public:
  TextureInformation(uint32_t width = 0, uint32_t height = 0, uint32_t depth = 0, uint32_t levels = 1);

  uint32_t GetWidth() const;
  uint32_t GetHeight() const;
  uint32_t GetDepth() const;
  uint32_t GetLevels() const;
  Extent2D GetExtent2D() const;
  Extent3D GetExtent3D() const;

private:
  uint32_t levels_;
  uint32_t width_;
  uint32_t height_;
  uint32_t depth_;
};

class Texture {
public:
  Texture(TextureTarget texture_target, InternalFormat internal_format, const TextureInformation &texture_information);

  ~Texture();

  Texture(const Texture &) = delete;

  Texture &operator=(const Texture &) = delete;

  Texture(Texture &&other) noexcept;

  Texture &operator=(Texture &&other) noexcept;

  void Bind(uint32_t unit);

  void BindImage(uint32_t unit, BufferAccess access, uint32_t level = 0, int32_t layer = -1);

  InternalFormat GetFormat() const;

  TextureTarget GetTarget() const;

  const TextureInformation &GetTextureInformation() const;

  Handle GetHandle() const;

  template <typename T>
  void SetData(std::span<const T> data);

protected:
  void CreateStorage();
  void SetParameters();

private:
  Descriptor texture_;
  TextureTarget texture_target_;
  InternalFormat internal_format_;
  TextureInformation texture_information_;
};

} // namespace Terabithia

#include "texture.ipp"

#endif // TERABITHIA_TEXTURE_H