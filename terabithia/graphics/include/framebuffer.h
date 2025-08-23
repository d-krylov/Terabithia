#ifndef TERABITHIA_FRAMEBUFFER_H
#define TERABITHIA_FRAMEBUFFER_H

#include "graphics_types.h"

namespace Terabithia {

class Framebuffer {
public:
  Framebuffer();

  ~Framebuffer();

private:
  Descriptor framebuffer_;
};

} // namespace Terabithia

#endif // TERABITHIA_FRAMEBUFFER_H
