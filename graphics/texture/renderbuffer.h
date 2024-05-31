#ifndef RENDERBUFFER_H
#define RENDERBUFFER_H

#include "graphics_types.h"

namespace Terabithia {

class Renderbuffer {
public:
  Renderbuffer(TextureInternalFormat internal_format, int32_t width, int32_t height);

  ~Renderbuffer();

  operator Handle() const { return renderbuffer_; }

  [[nodiscard]] const Vector2i &GetSize() const { return size_; }
  [[nodiscard]] int32_t GetWidth() const { return size_.x; }
  [[nodiscard]] int32_t GetHeight() const { return size_.y; }

protected:
  void CreateStorage();

private:
  Handle renderbuffer_{0};
  TextureInternalFormat internal_format_;
  Vector2i size_;
};

} // namespace Terabithia

#endif // RENDERBUFFER_H