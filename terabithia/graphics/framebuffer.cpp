#include "terabithia/graphics/include/framebuffer.h"
#include "terabithia/graphics/include/graphics_wrappers.h"

namespace Terabithia {

Framebuffer::Framebuffer() {
  CreateFramebuffer(framebuffer_);
}

Framebuffer::~Framebuffer() {
  DeleteFramebuffer(framebuffer_);
}

} // namespace Terabithia