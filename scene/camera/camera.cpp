#include "camera.h"

namespace Terabithia {

// clang-format off
Camera::Camera()
  : position_(0.0f, 1.0f, 0.0f), 
    front_(0.0f, 0.0f, -1.0f), 
    near_(0.1f),
    far_(500.0f), 
    fovy_{PI_ / 3.0f}, 
    pitch_(0.0f), 
    yaw_(-PI_ / 2.0f),
    aspect_(1.0f) {
  UpdateVectors();
}
//clang-format on

Matrix4f Camera::GetLookAtMatrix() const {
  return glm::lookAt(position_, position_ + front_, up_);
}

Matrix4f Camera::GetPerspectiveMatrix() const {
  return glm::perspective(fovy_, aspect_, near_, far_);
}

void Camera::SetFovy(float value) {

}

void Camera::SetAspect(float value) {

}

void Camera::SetYaw(float value) {
  yaw_ = value;
  UpdateVectors();
}

void Camera::SetPosition(const Vector3f &position) {
  position_ = position;
}

void Camera::UpdateVectors() {
  Vector3f front;
  front.x = glm::cos(yaw_) * glm::cos(pitch_);
  front.y = glm::sin(pitch_);
  front.z = glm::sin(yaw_) * glm::cos(pitch_);
  front_ = glm::normalize(front);
  right_ = glm::normalize(glm::cross(front_, WORLD_UP));
  up_ = glm::normalize(glm::cross(right_, front_));
}

} // namespace Terabithia