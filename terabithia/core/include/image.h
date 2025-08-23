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

  int32_t GetChannels() const;

private:
  int32_t width_{0};
  int32_t height_{0};
  int32_t channels_{0};
};

} // namespace Terabithia

#endif // TERABITHIA_IMAGE_H