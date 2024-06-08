#ifndef CORE_TYPES_H
#define CORE_TYPES_H

#include <glm/ext.hpp>
#include <glm/glm.hpp>
#include <glm/gtx/normal.hpp>
#include <glm/gtx/quaternion.hpp>

namespace Terabithia {

using Handle = uint32_t;

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
using Matrix4f = glm::mat4x4;
using Quaternion = glm::quat;

constexpr inline std::size_t operator""_KiB(unsigned long long int x) { return 1024ULL * x; }
constexpr inline std::size_t operator""_MiB(unsigned long long int x) { return 1024_KiB * x; }

constexpr Vector3f X_ = Vector3f(1.0f, 0.0f, 0.0f);
constexpr Vector3f Y_ = Vector3f(0.0f, 1.0f, 0.0f);
constexpr Vector3f Z_ = Vector3f(0.0f, 0.0f, 1.0f);

constexpr Vector3f WORLD_UP = Y_;

constexpr float PI_ = glm::pi<float>();

} // namespace Terabithia

#endif // CORE_TYPES_H