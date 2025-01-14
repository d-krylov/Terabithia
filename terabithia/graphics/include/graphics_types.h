#ifndef TERABITHIA_GRAPHICS_TYPES_H
#define TERABITHIA_GRAPHICS_TYPES_H

#include "glad/glad.h"
#include "core/include/concepts.h"
#include <array>

namespace Terabithia {

enum class BufferBit : uint32_t {
#define BUFFER_BIT(X) X = GL_##X##_BUFFER_BIT,
#include "graphics_types.def"
};

enum class PolygonMode : uint32_t {
#define POLYGON_MODE(X) X = GL_##X,
#include "graphics_types.def"
};

enum class PixelFormat : uint32_t {
#define PIXEL_FORMAT(X) X = GL_##X,
#include "graphics_types.def"
};

enum class MinFilter : int32_t {
#define MIN_FILTER(X) X = GL_##X,
#include "graphics_types.def"
};

enum class MagFilter : int32_t {
#define MAG_FILTER(X) X = GL_##X,
#include "graphics_types.def"
};

enum class WrapMode : uint16_t {
#define WRAP_MODE(X) X = GL_##X,
#include "graphics_types.def"
};

enum class BlendEquation : uint32_t {
#define BLEND_OPERATION(X) X = GL_##X,
#include "graphics_types.def"
};

enum class BlendFactor : uint32_t {
#define BLEND_FACTOR(X) X = GL_##X,
#include "graphics_types.def"
};

enum class ShaderBit : uint32_t {
#define SHADER_TYPE(X) X = GL_##X##_SHADER_BIT,
#include "graphics_types.def"
};

enum class ShaderParameter : uint32_t {
#define SHADER_PARAMETER(X) X = GL_##X,
#include "graphics_types.def"
};

enum class ProgramParameter : uint32_t {
#define PROGRAM_PARAMETER(X) X = GL_##X,
#include "graphics_types.def"
};

enum class BufferStorage : uint32_t {
#define BUFFER_STORAGE(X) X = GL_##X##_BIT,
#include "graphics_types.def"
};

enum class MapAccess : uint32_t {
#define MAP_ACCESS(X) X = GL_MAP_##X##_BIT,
#include "graphics_types.def"
};

enum class Access : uint32_t {
#define ACCESS(X) X = GL_##X,
#include "graphics_types.def"
};

enum class ShaderType : uint32_t {
#define SHADER_TYPE(X) X = GL_##X##_SHADER,
#include "graphics_types.def"
};

enum class Format : uint16_t {
#define FORMAT(X, Y, Z, V) X,
#include "graphics_types.def"
};

enum class PrimitiveKind : uint32_t {
#define PRIMITIVE_KIND(X) X = GL_##X,
#include "graphics_types.def"
};

enum class BufferTarget : uint32_t {
#define BUFFER_TARGET(X) X = GL_##X##_BUFFER,
#include "graphics_types.def"
};

// TEXTURE

enum class TextureTarget : uint32_t {
#define TEXTURE_TARGET(X) X = GL_##X,
#include "graphics_types.def"
};

enum class InternalFormat : uint32_t {
#define TEXTURE_FORMAT(X, Y, Z) X = GL_##X,
#include "graphics_types.def"
};

enum class PixelType : uint32_t {
#define PIXEL_TYPE(X) X = GL_##X,
#include "graphics_types.def"
};

enum class TextureParameter : uint32_t {
#define TEXTURE_PARAMETER(X) X = GL_##X,
#include "graphics_types.def"
};

enum class AttachmentPoint : uint32_t {
#define ATTACHMENT_POINT(X) X = GL_##X,
#include "graphics_types.def"
};

enum class FramebufferStatus {
#define FRAMEBUFFER_STATUS(X) X = GL_FRAMEBUFFER_##X,
#include "graphics_types.def"
};

enum class BarrierBit : uint32_t {
#define BARRIER_BIT(X) X = GL_##X##_BARRIER_BIT,
#include "graphics_types.def"
};

enum class ComparasionFunction : uint32_t {
#define COMPARASION_FUNCTION(X) X = GL_##X,
#include "graphics_types.def"
};

enum class StencilOperation : uint32_t {
#define STENCIL_OPERATION(X) X = GL_##X,
#include "graphics_types.def"
};

enum class PrimitiveFormat : uint32_t {
#define PRIMITIVE_DATA_TYPE(X) X = GL_##X,
#include "graphics_types.def"
};

enum class IndexType : uint32_t {
#define INDEX_TYPE(X) X = GL_##X,
#include "graphics_types.def"
};

enum class Capabilities : uint32_t {
#define CAPABILITIES(X) X = GL_##X,
#include "graphics_types.def"
};

// DEBUG

enum class DebugType : uint16_t {
#define DEBUG_TYPE(X) X = GL_DEBUG_TYPE_##X,
#include "graphics_types.def"
};

enum class DebugSource : uint16_t {
#define DEBUG_SOURCE(X) X = GL_DEBUG_SOURCE_##X,
#include "graphics_types.def"
};

enum class DebugSeverity : uint16_t {
#define DEBUG_SEVERITY(X) X = GL_DEBUG_SEVERITY_##X,
#include "graphics_types.def"
};

enum class Error : uint32_t {
#define ERROR(X) X = GL_##X,
#include "graphics_types.def"
};

struct DrawArraysIndirectCommand {
  uint32_t count_{0};
  uint32_t instance_count_{0};
  uint32_t first_vertex_{0};
  uint32_t base_instance_{0};
};

struct DrawElementsIndirectCommand {
  uint32_t count_{0};
  uint32_t instance_count_{0};
  uint32_t first_index_{0};
  int32_t base_vertex_{0};
  uint32_t base_instance_{0};
};

struct Wrap {
  Wrap(WrapMode v) : s_(v), t_(v), r_(v) {}
  Wrap(WrapMode s, WrapMode t, WrapMode r) : s_(s), t_(t), r_(r) {}
  WrapMode s_;
  WrapMode t_;
  WrapMode r_;
};

struct PixelInformation {
  PixelFormat format;
  PixelType type;
};

struct FormatInformation {
  uint32_t component_count_;
  int32_t component_size_;
  PrimitiveFormat component_type_;
  bool normalized_;
};

struct Extent2i {
  int32_t w{0};
  int32_t h{0};
};

struct Extent3i {
  int32_t w{0};
  int32_t h{0};
  int32_t d{0};
};

ALLOW_BITMASK_ENUM(BufferStorage);
ALLOW_BITMASK_ENUM(MapAccess);
ALLOW_BITMASK_ENUM(BarrierBit);
ALLOW_BITMASK_ENUM(BufferBit);

template <BufferStorage S>
concept IsDynamic = ((S & BufferStorage::DYNAMIC_STORAGE) == BufferStorage::DYNAMIC_STORAGE);

template <BufferStorage S>
concept IsMapWrite = ((S & BufferStorage::MAP_WRITE) == BufferStorage::MAP_WRITE);

template <BufferStorage S>
concept IsMapRead = ((S & BufferStorage::MAP_READ) == BufferStorage::MAP_READ);

const PixelInformation &GetPixelInformation(InternalFormat format);
const FormatInformation &GetFormatInformation(Format format);
bool IsTextureLayered(TextureTarget target);
uint32_t GetTextureDimensions(TextureTarget target);

} // namespace Terabithia

#endif // TERABITHIA_GRAPHICS_TYPES_H