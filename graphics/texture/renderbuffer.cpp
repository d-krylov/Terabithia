#include "renderbuffer.h"

namespace Terabithia {

Renderbuffer::Renderbuffer(TextureInternalFormat internal_format, int32_t width,
                           int32_t height)
  : internal_format_(internal_format), size_(width, height) {
  glCreateRenderbuffers(1, &renderbuffer_);
}

Renderbuffer::~Renderbuffer() { glDeleteRenderbuffers(1, &renderbuffer_); }

void Renderbuffer::CreateStorage() {
  glNamedRenderbufferStorage(renderbuffer_, static_cast<uint16_t>(internal_format_), size_.x,
                             size_.y);
}

} // namespace Terabithia