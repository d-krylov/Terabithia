#include "transform.h"

namespace Terabithia {

Matrix4f Transform::GetMatrix() {
  Matrix4f model(1.0f);
  model = glm::translate(model, position_);
  rotation_ = glm::quat(rotation_angles_);
  glm::mat4 rotation_matrix = glm::toMat4(rotation_);
  model = rotation_matrix * model;
  model = glm::scale(model, scale_);
}

} // namespace Terabithia