#include "core/include/image.h"
#include "stb_image.h"

namespace Terabithia {

ImageWrapper::ImageWrapper(const std::filesystem::path &path) {
  stbi_set_flip_vertically_on_load(true);
  auto data = stbi_load(path.c_str(), &width_, &height_, &channels_, STBI_rgb_alpha);
  if (data != nullptr) {
    image_data_ = std::span(data, GetSize());
  }
}

ImageWrapper::~ImageWrapper() { stbi_image_free(image_data_.data()); }

} // namespace Terabithia