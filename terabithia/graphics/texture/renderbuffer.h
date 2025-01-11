#ifndef TERABITHIA_RENDERBUFFER_H
#define TERABITHIA_RENDERBUFFER_H

#include "graphics/include/graphics_wrappers.h"

namespace Terabithia {

class Renderbuffer {
public:
  Renderbuffer(int32_t width, int32_t height, InternalFormat format, uint32_t samples = 1)
    : size_{width, height}, format_(format), samples_(samples) {
    GL::CreateRenderbuffer(renderbuffer_);
    GL::CreateRenderbufferStorage(renderbuffer_, format_, size_.w, size_.h, samples_);
  }

  ~Renderbuffer() { GL::DeleteRenderbuffer(renderbuffer_); }

  operator GL::DescriptorType() const { return renderbuffer_; }

  void Bind() { GL::BindRenderbuffer(renderbuffer_); }

private:
  GL::DescriptorType renderbuffer_{0};
  InternalFormat format_;
  Extent2i size_;
  uint32_t samples_;
};

} // namespace Terabithia

#endif // TERABITHIA_RENDERBUFFER_H