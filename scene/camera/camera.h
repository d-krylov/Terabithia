#ifndef CAMERA_H
#define CAMERA_H

#include "core_types.h"
#include "macros.h"

namespace Terabithia {

class Camera {
public:
  Camera();

  const Vector3f &GetPosition() { return position_; }
  const Vector3f &GetRight() { return right_; }
  const Vector3f &GetFront() { return front_; }
  const Vector3f &GetUp() { return up_; }

  void SetFovy(float value);
  void SetAspect(float value);

  void SetYaw(float value);
  void SetPosition(const Vector3f &position);

  float GetYaw() const { return yaw_; }

  [[nodiscard]] Matrix4f GetLookAtMatrix() const;
  [[nodiscard]] Matrix4f GetPerspectiveMatrix() const;

protected:
  void UpdateVectors();

private:
  Vector3f position_;
  Vector3f front_;
  Vector3f right_;
  Vector3f up_;
  float fovy_;
  float near_;
  float far_;
  float yaw_;
  float pitch_;
  float aspect_;
};

} // namespace Terabithia

#endif // CAMERA_H