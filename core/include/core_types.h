#ifndef CORE_TYPES_H
#define CORE_TYPES_H

#include <cstdint>

#ifndef GLM_IMPLEMENTATION
#include "linalg/linalg.h"
#endif

namespace Terabithia {

using Handle = uint32_t;

#ifndef GLM_IMPLEMENTATION
using Vector2f = linalg::aliases::float2;
using Vector3f = linalg::aliases::float3;
using Vector4f = linalg::aliases::float4;
using Vector2i = linalg::aliases::int2;
using Vector3i = linalg::aliases::int3;
using Vector4i = linalg::aliases::int4;
using Vector2u = linalg::aliases::uint2;
using Vector3u = linalg::aliases::uint3;
using Vector4u = linalg::aliases::uint4;
using Matrix4f = linalg::aliases::float4x4;
#endif

} // namespace Terabithia

#endif // CORE_TYPES_H