#include "core/include/image.h"
#include "stb_image.h"

namespace Terabithia {

Image::Image(const std::filesystem::path &path) {
  stbi_set_flip_vertically_on_load(true);
  auto data = stbi_load(path.c_str(), &width_, &height_, &channels_, STBI_default);
  if (data != nullptr) {
    image_data_ = std::span(reinterpret_cast<std::byte *>(data), GetSize());
  }
}

Image::~Image() { stbi_image_free(image_data_.data()); }

} // namespace Terabithia