#include "stb_image.h"
#include "terabithia/core/include/core.h"
#include "terabithia/core/include/image.h"

namespace Terabithia {

Image::Image(const std::filesystem::path &path) {
  auto data = stbi_load(path.c_str(), &width_, &height_, &channels_, STBI_rgb_alpha);
  CORE_ASSERT(data != nullptr, "Can't load an image");
}

int32_t Image::GetWidth() const {
  return width_;
}

int32_t Image::GetHeight() const {
  return height_;
}

int32_t Image::GetChannels() const {
  return channels_;
}

} // namespace Terabithia