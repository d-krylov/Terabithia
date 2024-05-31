#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include "graphics_types.h"
#include "renderbuffer.h"
#include "texture.h"
#include <vector>

namespace Terabithia {

struct FramebufferAttachment {

  FramebufferAttachment(FramebufferAttachmentType attachment_type, Texture *texture,
                        uint32_t texture_level, uint32_t texture_layer)
    : attachment_type_{attachment_type}, texture_level_{texture_level},
      texture_layer_{texture_layer}, texture_{texture} {}

  FramebufferAttachment(FramebufferAttachmentType attachment_type, Renderbuffer *renderbuffer)
    : attachment_type_{attachment_type}, renderbuffer_{renderbuffer} {}

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

  void Attach(const std::initializer_list<FramebufferAttachment> &attachments);

  void Attach(const FramebufferAttachment &attachment);

protected:
  bool Verify();

private:
  Handle framebuffer_{0};
  std::vector<FramebufferAttachment> attachments_;
};

} // namespace Terabithia

#endif // FRAMEBUFFER_H