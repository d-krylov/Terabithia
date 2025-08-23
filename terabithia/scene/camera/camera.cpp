#include "camera.h"

namespace Terabithia {

Camera::Camera() {
}

void Camera::SetPosition(const Vector3f &position) {
  position_ = position;
}

void Camera::SetAspect(float aspect) {
  aspect_ = aspect;
}

void Camera::SetFov(float fov) {
  fov_ = fov;
}

const Vector3f &Camera::GetPosition() const {
  return position_;
}

Matrix4f Camera::GetLookAt() const {
  return glm::lookAt(position_, position_ + front_, up_);
}

Matrix4f Camera::GetProjection() const {
  return glm::perspective(fov_, aspect_, near_, far_);
}

} // namespace Terabithia