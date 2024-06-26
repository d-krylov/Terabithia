#ifndef IMAGE_H
#define IMAGE_H

#include "graphics_types.h"
#include <filesystem>
#include <span>

namespace Terabithia {

class Image {
public:
  Image(const std::filesystem::path &path);

  ~Image();

  [[nodiscard]] std::span<const std::byte> GetData() const { return image_data_; }

  [[nodiscard]] const Vector2i &GetSize() const { return size_; }
  [[nodiscard]] int32_t GetWidth() const { return size_.x; }
  [[nodiscard]] int32_t GetHeight() const { return size_.y; }
  [[nodiscard]] int32_t GetChannels() const { return channels_; }

  TextureInternalFormat GetFormat() const;

private:
  int32_t channels_;
  Vector2i size_;
  std::span<std::byte> image_data_;
};

} // namespace Terabithia

#endif // IMAGE_H