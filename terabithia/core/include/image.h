#ifndef TERABITHIA_IMAGE_H
#define TERABITHIA_IMAGE_H

#include <filesystem>
#include <vector>

namespace Terabithia {

class Image {
public:
  Image(const std::filesystem::path &path);

  int32_t GetWidth() const;

  int32_t GetHeight() const;

private:
  int32_t width_;
  int32_t height_;
};

} // namespace Terabithia

#endif // TERABITHIA_IMAGE_H