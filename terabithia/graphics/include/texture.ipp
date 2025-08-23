#ifndef TERABITHIA_TEXTURE_IPP
#define TERABITHIA_TEXTURE_IPP

namespace Terabithia {

template <typename T>
void Texture::SetData(std::span<const T> data) {
  auto dimensions_number = GetTextureDimensions(GetTarget());
  auto format_information = GetFormatInformation(GetFormat());
  const auto &ti = GetTextureInformation();
  switch (dimensions_number) {
  case 1: TextureSubImage(GetHandle(), ti.GetWidth(), format_information, std::as_bytes(data)); break;
  case 2: TextureSubImage(GetHandle(), ti.GetExtent2D(), format_information, std::as_bytes(data)); break;
  case 3: TextureSubImage(GetHandle(), ti.GetExtent3D(), format_information, std::as_bytes(data)); break;
  default: std::unreachable(); break;
  }
}

} // namespace Terabithia

#endif // TERABITHIA_TEXTURE_IPP