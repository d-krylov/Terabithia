#include "stb_image.h"
#include "terabithia/core/include/image.h"

namespace Terabithia {

Image::Image(const std::filesystem::path &path) {
}

int32_t Image::GetWidth() const {
  return width_;
}

int32_t Image::GetHeight() const {
  return height_;
}

} // namespace Terabithia