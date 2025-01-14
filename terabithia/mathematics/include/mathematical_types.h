#ifndef TERABITHIA_MATHEMATICAL_TYPES_H
#define TERABITHIA_MATHEMATICAL_TYPES_H

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

constexpr inline auto X_ = Vector3f(1.0f, 0.0f, 0.0f);
constexpr inline auto Y_ = Vector3f(0.0f, 1.0f, 0.0f);
constexpr inline auto Z_ = Vector3f(0.0f, 0.0f, 1.0f);

constexpr inline float PI_ = glm::pi<float>();

constexpr inline float SQRT5_ = 2.23606797749979f;

constexpr inline float PHI_ = 0.5f * SQRT5_ + 0.5f;

template <typename T> inline auto CastToPointer(const T &value) { return glm::value_ptr(value); }

} // namespace Terabithia

#endif // TERABITHIA_MATHEMATICAL_TYPES_H