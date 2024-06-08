#ifndef RENDERBUFFER_H
#define RENDERBUFFER_H

#include "graphics_types.h"

namespace Terabithia {

class Renderbuffer {
public:
  Renderbuffer(TextureInternalFormat internal_format, int32_t width, int32_t height,
               uint32_t samples = 0);

  ~Renderbuffer();

  operator Handle() const { return renderbuffer_; }

  void Bind();

  [[nodiscard]] const Vector2i &GetSize() const { return size_; }
  [[nodiscard]] int32_t GetWidth() const { return size_.x; }
  [[nodiscard]] int32_t GetHeight() const { return size_.y; }
  [[nodiscard]] int32_t GetSamples() const { return samples_; }

protected:
  void CreateStorage();

private:
  Handle renderbuffer_{0};
  TextureInternalFormat internal_format_;
  Vector2i size_;
  uint32_t samples_;
};

} // namespace Terabithia

#endif // RENDERBUFFER_H