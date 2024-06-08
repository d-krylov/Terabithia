#ifndef LIGHT_H
#define LIGHT_H

#include "core_types.h"

namespace Terabithia {

class Light {
public:
  Vector3f &GetColor() { return color_; }

private:
  Vector3f color_;
};

} // namespace Terabithia

#endif // LIGHT_H