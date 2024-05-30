#ifndef CAMERA_H
#define CAMERA_H

#include "macros.h"

namespace Terabithia {

class Camera {
public:
private:
  float fov_;
  float near_;
  float far_;
  float aspect_;
};

} // namespace Terabithia

#endif // CAMERA_H