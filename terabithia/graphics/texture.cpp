#include "terabithia/graphics/include/texture.h"
#include "terabithia/graphics/include/graphics_wrappers.h"

namespace Terabithia {

// TEXTURE INFORMATION

TextureInformation::TextureInformation(uint32_t width, uint32_t height, uint32_t depth, uint32_t levels)
  : width_(width), height_(height), depth_(depth), levels_(levels) {
}

uint32_t TextureInformation::GetWidth() const {
  return width_;
}

uint32_t TextureInformation::GetHeight() const {
  return height_;
}

uint32_t TextureInformation::GetDepth() const {
  return depth_;
}

uint32_t TextureInformation::GetLevels() const {
  return levels_;
}

Extent2D TextureInformation::GetExtent2D() const {
  return Extent2D(GetWidth(), GetHeight());
}

Extent3D TextureInformation::GetExtent3D() const {
  return Extent3D(GetWidth(), GetHeight(), GetDepth());
}

// TEXTURE

Texture::Texture(TextureTarget texture_target, InternalFormat internal_format, const TextureInformation &texture_information)
  : texture_target_(texture_target), internal_format_(internal_format), texture_information_(texture_information) {
  CreateTexture(texture_, texture_target);
  CreateStorage();
}

Texture::~Texture() {
  DeleteTexture(texture_);
}

Texture::Texture(Texture &&other) noexcept {
  texture_ = std::move(other.texture_);
}

Texture &Texture::operator=(Texture &&other) noexcept {
  texture_ = std::move(other.texture_);
  return *this;
}

void Texture::Bind(uint32_t unit) {
  BindTextureUnit(GetHandle(), unit);
}

InternalFormat Texture::GetFormat() const {
  return internal_format_;
}

TextureTarget Texture::GetTarget() const {
  return texture_target_;
}

Handle Texture::GetHandle() const {
  return texture_;
}

const TextureInformation &Texture::GetTextureInformation() const {
  return texture_information_;
}

void Texture::CreateStorage() {
  auto dimensions_number = GetTextureDimensions(GetTarget());
  const auto &ti = GetTextureInformation();
  switch (dimensions_number) {
  case 0: break;
  case 1: CreateTextureStorage(GetHandle(), ti.GetLevels(), ti.GetWidth(), GetFormat()); break;
  case 2: CreateTextureStorage(GetHandle(), ti.GetLevels(), ti.GetExtent2D(), GetFormat()); break;
  case 3: CreateTextureStorage(GetHandle(), ti.GetLevels(), ti.GetExtent3D(), GetFormat()); break;
  default: std::unreachable(); break;
  }
}

void Texture::BindImage(uint32_t unit, BufferAccess access, uint32_t level, int32_t layer) {
  BindImageTexture(texture_, unit, access, internal_format_, level, layer);
}

void Texture::SetParameters() {
}

} // namespace Terabithia