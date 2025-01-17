#ifndef TERABITHIA_IMAGE_H
#define TERABITHIA_IMAGE_H

#include <filesystem>
#include <vector>
#include <span>

namespace Terabithia {

class ImageWrapper {
public:
  ImageWrapper(const std::filesystem::path &path);

  ~ImageWrapper();

  int32_t GetWidth() const { return width_; }
  int32_t GetHeight() const { return height_; }
  int32_t GetChannels() const { return channels_; }
  int32_t GetSize() const { return width_ * height_ * channels_; }

  std::span<const uint8_t> GetData() const { return image_data_; }

private:
  int32_t width_;
  int32_t height_;
  int32_t channels_;
  std::span<uint8_t> image_data_;
};

} // namespace Terabithia

#endif // TERABITHIA_IMAGE_H