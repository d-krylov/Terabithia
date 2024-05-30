#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "core_types.h"

namespace Terabithia {

class Transform {
public:
private:
  Vector3f local_position_;
  Quaternion local_rotation_;
  Vector3f local_scale_;
};

} // namespace Terabithia

#endif // TRANSFORM_H