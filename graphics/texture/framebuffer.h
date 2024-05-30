#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include "graphics_types.h"
#include "renderbuffer.h"
#include "texture.h"
#include <vector>

namespace Terabithia {

struct FramebufferAttachment {
  FramebufferAttachmentType attachment_type_;
  uint32_t texture_level_{0};
  uint32_t texture_layer_{0};
  Texture *texture_{nullptr};
  Renderbuffer *renderbuffer_{nullptr};
};

class Framebuffer {
public:
  Framebuffer();

  ~Framebuffer();

  NO_COPY_SEMANTIC(Framebuffer);

  operator Handle() const { return framebuffer_; }

  void Bind();
  void Unbind();

  void Attach(const FramebufferAttachment &attachment);

protected:
  bool Verify();

private:
  Handle framebuffer_{0};
  std::vector<FramebufferAttachment> attachments_;
};

} // namespace Terabithia

#endif // FRAMEBUFFER_H