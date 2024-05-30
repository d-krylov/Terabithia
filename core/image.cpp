#include "image.h"
#include "tools.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

namespace Terabithia {

Image::Image(const std::filesystem::path &path) {
  auto data = ToBytePointer(stbi_load(path.c_str(), &size_.x, &size_.y, &channels_, 0));
  if (data != nullptr) {
    image_data_ = std::span(data, size_.x * size_.y * channels_);
  }
}

TextureInternalFormat Image::GetFormat() const {
  switch (channels_) {
  case 1:
    return TextureInternalFormat::R8;
  case 3:
    return TextureInternalFormat::RGB8;
  case 4:
    return TextureInternalFormat::RGBA8;
  default:
    break;
  }
  CORE_UNREACHABLE();
}

Image::~Image() { stbi_image_free(image_data_.data()); }

} // namespace Terabithia