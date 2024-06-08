#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "core_types.h"

namespace Terabithia {

class Transform {
public:
  Vector3f &GetPosition() { return position_; }
  Vector3f &GetRotation() { return rotation_angles_; }
  Vector3f &GetScale() { return scale_; }

  Matrix4f GetMatrix();

private:
  Vector3f position_;
  Quaternion rotation_;
  Vector3f rotation_angles_;
  Vector3f scale_;
};

} // namespace Terabithia

#endif // TRANSFORM_H