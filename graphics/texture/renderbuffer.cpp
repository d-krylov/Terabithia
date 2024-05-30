#include "renderbuffer.h"

namespace Terabithia {

Renderbuffer::Renderbuffer() { glCreateRenderbuffers(1, &renderbuffer_); }

Renderbuffer::~Renderbuffer() { glDeleteRenderbuffers(1, &renderbuffer_); }

} // namespace Terabithia