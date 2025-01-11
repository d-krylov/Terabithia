#ifndef TERABITHIA_FRAMEBUFFER_H
#define TERABITHIA_FRAMEBUFFER_H

#include "texture.h"
#include "renderbuffer.h"

namespace Terabithia {

class Framebuffer {
public:
  Framebuffer() {}

  ~Framebuffer() {}

private:
  GL::DescriptorType framebuffer_{0};
};

} // namespace Terabithia

#endif // TERABITHIA_FRAMEBUFFER_H