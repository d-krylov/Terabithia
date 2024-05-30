#ifndef RENDERBUFFER_H
#define RENDERBUFFER_H

#include "graphics_types.h"

namespace Terabithia {

class Renderbuffer {
public:
  Renderbuffer();

  ~Renderbuffer();

  operator Handle() const { return renderbuffer_; }

private:
  Handle renderbuffer_{0};
};

} // namespace Terabithia

#endif // RENDERBUFFER_H