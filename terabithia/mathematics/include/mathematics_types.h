#ifndef TERABITHIA_MATHEMATICS_TYPES_H
#define TERABITHIA_MATHEMATICS_TYPES_H

#include <glm/ext.hpp>
#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>

namespace Terabithia {

using Vector2f = glm::vec2;
using Vector3f = glm::vec3;
using Vector4f = glm::vec4;
using Vector2i = glm::ivec2;
using Vector3i = glm::ivec3;
using Vector4i = glm::ivec4;
using Vector2u = glm::uvec2;
using Vector3u = glm::uvec3;
using Vector4u = glm::uvec4;
using Vector2d = glm::dvec2;
using Vector3d = glm::dvec3;
using Vector4d = glm::dvec4;
using Matrix3f = glm::mat3x3;
using Matrix4f = glm::mat4x4;
using Quaternion = glm::quat;

} // namespace Terabithia

#endif // TERABITHIA_MATHEMATICS_TYPES_H