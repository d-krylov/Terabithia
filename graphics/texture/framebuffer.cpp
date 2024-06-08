#include "framebuffer.h"

namespace Terabithia {

Framebuffer::Framebuffer() { glCreateFramebuffers(1, &framebuffer_); }

Framebuffer::~Framebuffer() { glDeleteFramebuffers(1, &framebuffer_); }

FramebufferStatus Framebuffer::GetStatus() const {
  auto kind = static_cast<uint16_t>(FramebufferKind::FULL);
  return FramebufferStatus(glCheckNamedFramebufferStatus(framebuffer_, kind));
}

void Framebuffer::Attach(const FramebufferAttachment &attachment) {
  auto attachment_type = static_cast<uint16_t>(attachment.attachment_type_);
  if (attachment.texture_ != nullptr) {
    if (attachment.texture_->IsLayered()) {
      glNamedFramebufferTextureLayer(framebuffer_, attachment_type, *attachment.texture_,
                                     attachment.texture_level_, attachment.texture_layer_);
    } else {
      glNamedFramebufferTexture(framebuffer_, attachment_type, *attachment.texture_,
                                attachment.texture_level_);
    }
  } else if (attachment.renderbuffer_ != nullptr) {
    glNamedFramebufferRenderbuffer(framebuffer_, attachment_type, GL_RENDERBUFFER,
                                   *attachment.renderbuffer_);
  }
}

void Framebuffer::Attach(const std::initializer_list<FramebufferAttachment> &attachments) {}

void Framebuffer::Bind() {
  glBindFramebuffer(static_cast<uint16_t>(FramebufferKind::FULL), framebuffer_);
}

void Framebuffer::Unbind() {
  glBindFramebuffer(static_cast<uint16_t>(FramebufferKind::FULL), 0);
}

} // namespace Terabithia