#ifndef TERABITHIA_CAMERA_H
#define TERABITHIA_CAMERA_H

#include "terabithia/mathematics/include/mathematics_types.h"

namespace Terabithia {

class Camera {
public:
  Camera();

  void SetPosition(const Vector3f &position);
  void SetAspect(float aspect);
  void SetFov(float fov);

  const Vector3f &GetPosition() const;

  Matrix4f GetLookAt() const;
  Matrix4f GetProjection() const;

private:
  Vector3f position_{0.0f, 0.0f, 0.0f};
  Vector3f front_{0.0f, 0.0f, -1.0f};
  Vector3f right_{1.0f, 0.0f, 0.0f};
  Vector3f up_{0.0f, 1.0f, 0.0f};
  float near_{0.1f};
  float far_{1000.0f};
  float aspect_{1.0f};
  float fov_;
};

} // namespace Terabithia

#endif // TERABITHIA_CAMERA_H