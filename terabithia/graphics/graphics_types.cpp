#include "terabithia/graphics/include/graphics_types.h"
#include <utility>
#include <unordered_map>

namespace Terabithia {

struct AttributeInformation {
  uint32_t components_count;
  VertexAttributeType vertex_attribute_type;
};

// clang-format off
std::unordered_map<AttributeType, AttributeInformation> attribute_information{
  {AttributeType::FLOAT, {1, VertexAttributeType::FLOAT}},
  {AttributeType::FLOAT_VEC2, {2, VertexAttributeType::FLOAT}},
  {AttributeType::FLOAT_VEC3, {3, VertexAttributeType::FLOAT}},
  {AttributeType::FLOAT_VEC4, {4, VertexAttributeType::FLOAT}},
  {AttributeType::FLOAT_MAT2, {4, VertexAttributeType::FLOAT}},
  {AttributeType::FLOAT_MAT3, {9, VertexAttributeType::FLOAT}},
  {AttributeType::FLOAT_MAT4, {16, VertexAttributeType::FLOAT}},
  {AttributeType::FLOAT_MAT2x3, {6, VertexAttributeType::FLOAT}},
  {AttributeType::FLOAT_MAT2x4, {8, VertexAttributeType::FLOAT}},
  {AttributeType::FLOAT_MAT3x2, {6, VertexAttributeType::FLOAT}},
  {AttributeType::FLOAT_MAT3x4, {12, VertexAttributeType::FLOAT}},
  {AttributeType::FLOAT_MAT4x2, {8, VertexAttributeType::FLOAT}},
  {AttributeType::FLOAT_MAT4x3, {12, VertexAttributeType::FLOAT}},
  {AttributeType::INT, {1, VertexAttributeType::INT}},
  {AttributeType::INT_VEC2, {2, VertexAttributeType::INT}},
  {AttributeType::INT_VEC3, {3, VertexAttributeType::INT}},
  {AttributeType::INT_VEC4, {4, VertexAttributeType::INT}},
  {AttributeType::UNSIGNED_INT, {1, VertexAttributeType::UNSIGNED_INT}},
  {AttributeType::UNSIGNED_INT_VEC2, {2, VertexAttributeType::UNSIGNED_INT}},
  {AttributeType::UNSIGNED_INT_VEC3, {3, VertexAttributeType::UNSIGNED_INT}},
  {AttributeType::UNSIGNED_INT_VEC4, {4, VertexAttributeType::UNSIGNED_INT}},
  {AttributeType::DOUBLE, {1, VertexAttributeType::DOUBLE}},
  {AttributeType::DOUBLE_VEC2, {2, VertexAttributeType::DOUBLE}},
  {AttributeType::DOUBLE_VEC3, {3, VertexAttributeType::DOUBLE}},
  {AttributeType::DOUBLE_VEC4, {4, VertexAttributeType::DOUBLE}},
  {AttributeType::DOUBLE_MAT2, {4, VertexAttributeType::DOUBLE}},
  {AttributeType::DOUBLE_MAT3, {9, VertexAttributeType::DOUBLE}},
  {AttributeType::DOUBLE_MAT4, {16, VertexAttributeType::DOUBLE}},
  {AttributeType::DOUBLE_MAT2x3, {6, VertexAttributeType::DOUBLE}},
  {AttributeType::DOUBLE_MAT2x4, {8, VertexAttributeType::DOUBLE}},
  {AttributeType::DOUBLE_MAT3x2, {6, VertexAttributeType::DOUBLE}},
  {AttributeType::DOUBLE_MAT3x4, {12, VertexAttributeType::DOUBLE}},
  {AttributeType::DOUBLE_MAT4x2, {8, VertexAttributeType::DOUBLE}},
  {AttributeType::DOUBLE_MAT4x3, {12, VertexAttributeType::DOUBLE}}
};
// clang-format on

// clang-format off
std::unordered_map<InternalFormat, Pixel> format_information{
  {InternalFormat::R8, {PixelFormat::RED, PixelType::UNSIGNED_BYTE}},
  {InternalFormat::R8_SNORM, {PixelFormat::RED, PixelType::BYTE}},
  {InternalFormat::R16, {PixelFormat::RED, PixelType::UNSIGNED_SHORT}},
  {InternalFormat::R16_SNORM, {PixelFormat::RED, PixelType::SHORT}},
  {InternalFormat::RG8, {PixelFormat::RG, PixelType::UNSIGNED_BYTE}},
  {InternalFormat::RG8_SNORM, {PixelFormat::RG, PixelType::BYTE}},
  {InternalFormat::RG16, {PixelFormat::RG, PixelType::UNSIGNED_SHORT}},
  {InternalFormat::RG16_SNORM, {PixelFormat::RG, PixelType::SHORT}},
  {InternalFormat::R3_G3_B2, {PixelFormat::RGB, PixelType::UNSIGNED_BYTE_3_3_2}},
  {InternalFormat::RGB4, {PixelFormat::RGB, PixelType::UNSIGNED_SHORT_4_4_4_4}},
  {InternalFormat::RGB5, {PixelFormat::RGB, PixelType::UNSIGNED_SHORT_5_6_5}},
  {InternalFormat::RGB8, {PixelFormat::RGB, PixelType::UNSIGNED_BYTE}},
  {InternalFormat::RGB8_SNORM, {PixelFormat::RGB, PixelType::BYTE}},
  {InternalFormat::RGB10, {PixelFormat::RGB, PixelType::UNSIGNED_INT_2_10_10_10_REV}},
  {InternalFormat::RGB12, {PixelFormat::RGB, PixelType::UNSIGNED_SHORT}},
  {InternalFormat::RGB16_SNORM, {PixelFormat::RGB, PixelType::SHORT}},
  {InternalFormat::RGBA2, {PixelFormat::RGBA, PixelType::UNSIGNED_BYTE}},
  {InternalFormat::RGBA4, {PixelFormat::RGBA, PixelType::UNSIGNED_SHORT_4_4_4_4}},
  {InternalFormat::RGB5_A1, {PixelFormat::RGBA, PixelType::UNSIGNED_SHORT_5_5_5_1}},
  {InternalFormat::RGBA8, {PixelFormat::RGBA, PixelType::UNSIGNED_BYTE}},
  {InternalFormat::RGBA8_SNORM, {PixelFormat::RGBA, PixelType::BYTE}},
  {InternalFormat::RGB10_A2, {PixelFormat::RGBA, PixelType::UNSIGNED_INT_2_10_10_10_REV}},
  {InternalFormat::RGB10_A2UI, {PixelFormat::RGBA, PixelType::UNSIGNED_INT_2_10_10_10_REV}},
  {InternalFormat::RGBA12, {PixelFormat::RGBA, PixelType::UNSIGNED_SHORT}},
  {InternalFormat::RGBA16, {PixelFormat::RGBA, PixelType::UNSIGNED_SHORT}},
  {InternalFormat::SRGB8, {PixelFormat::RGB, PixelType::BYTE}},
  {InternalFormat::SRGB8_ALPHA8, {PixelFormat::RGBA, PixelType::BYTE}},
  {InternalFormat::R16F, {PixelFormat::RED, PixelType::UNSIGNED_SHORT}},
  {InternalFormat::RG16F, {PixelFormat::RG, PixelType::FLOAT}},
  {InternalFormat::RGB16F, {PixelFormat::RGB, PixelType::FLOAT}},
  {InternalFormat::RGBA16F, {PixelFormat::RGBA, PixelType::FLOAT}},
  {InternalFormat::R32F, {PixelFormat::RED, PixelType::FLOAT}},
  {InternalFormat::RG32F, {PixelFormat::RG, PixelType::FLOAT}},
  {InternalFormat::RGB32F, {PixelFormat::RGB, PixelType::FLOAT}},
  {InternalFormat::RGBA32F, {PixelFormat::RGBA, PixelType::FLOAT}},
  {InternalFormat::R11F_G11F_B10F, {PixelFormat::RGB, PixelType::FLOAT}},
  {InternalFormat::RGB9_E5, {PixelFormat::RGB, PixelType::UNSIGNED_SHORT}},
  {InternalFormat::R8I, {PixelFormat::RED, PixelType::BYTE}},
  {InternalFormat::R8UI, {PixelFormat::RED, PixelType::UNSIGNED_BYTE}},
  {InternalFormat::R16I, {PixelFormat::RED, PixelType::SHORT}},
  {InternalFormat::R16UI, {PixelFormat::RED, PixelType::UNSIGNED_SHORT}},
  {InternalFormat::R32I, {PixelFormat::RED, PixelType::INT}},
  {InternalFormat::R32UI, {PixelFormat::RED, PixelType::UNSIGNED_INT}},
  {InternalFormat::RG8I, {PixelFormat::RG, PixelType::BYTE}},
  {InternalFormat::RG8UI,{PixelFormat::RG, PixelType::UNSIGNED_BYTE}},
  {InternalFormat::RG16I, {PixelFormat::RG, PixelType::SHORT}},
  {InternalFormat::RG16UI, {PixelFormat::RG, PixelType::UNSIGNED_SHORT}},
  {InternalFormat::RG32I, {PixelFormat::RG, PixelType::INT}},
  {InternalFormat::RG32UI, {PixelFormat::RG, PixelType::UNSIGNED_INT}},
  {InternalFormat::RGB8I, {PixelFormat::RGB, PixelType::BYTE}},
  {InternalFormat::RGB8UI, {PixelFormat::RGB, PixelType::UNSIGNED_BYTE}},
  {InternalFormat::RGB16I, {PixelFormat::RGB, PixelType::SHORT}},
  {InternalFormat::RGB16UI, {PixelFormat::RGB, PixelType::UNSIGNED_SHORT}},
  {InternalFormat::RGB32I, {PixelFormat::RGB, PixelType::INT}},
  {InternalFormat::RGB32UI, {PixelFormat::RGB, PixelType::UNSIGNED_INT}},
  {InternalFormat::RGBA8I, {PixelFormat::RGBA, PixelType::BYTE}},
  {InternalFormat::RGBA8UI, {PixelFormat::RGBA, PixelType::UNSIGNED_BYTE}},
  {InternalFormat::RGBA16I, {PixelFormat::RGBA, PixelType::SHORT}},
  {InternalFormat::RGBA16UI, {PixelFormat::RGBA, PixelType::UNSIGNED_SHORT}},
  {InternalFormat::RGBA32I, {PixelFormat::RGBA, PixelType::INT}},
  {InternalFormat::RGBA32UI, {PixelFormat::RGBA, PixelType::UNSIGNED_INT}}
};
// clang-format on

AttributeInformation GetAttributeInformation(AttributeType type) {
  return attribute_information[type];
}

uint32_t GetAttributeSize(AttributeType type) {
  auto information = GetAttributeInformation(type);
  auto size = GetVertexAttributeSize(information.vertex_attribute_type);
  return information.components_count * size;
}

uint32_t GetAttributeComponentsCount(AttributeType type) {
  auto information = GetAttributeInformation(type);
  return information.components_count;
}

VertexAttributeType GetVertexAttributeType(AttributeType type) {
  auto information = GetAttributeInformation(type);
  return information.vertex_attribute_type;
}

uint32_t GetStride(std::span<const AttributeType> types) {
  uint32_t stride = 0;
  for (auto type : types) {
    stride += GetAttributeSize(type);
  }
  return stride;
}

uint32_t GetVertexAttributeSize(VertexAttributeType type) {
  switch (type) {
  case VertexAttributeType::BYTE:
  case VertexAttributeType::UNSIGNED_BYTE: return 1;
  case VertexAttributeType::SHORT:
  case VertexAttributeType::HALF_FLOAT:
  case VertexAttributeType::UNSIGNED_SHORT: return 2;
  case VertexAttributeType::FLOAT:
  case VertexAttributeType::FIXED:
  case VertexAttributeType::INT:
  case VertexAttributeType::UNSIGNED_INT:
  case VertexAttributeType::UNSIGNED_INT_10F_11F_11F_REV:
  case VertexAttributeType::UNSIGNED_INT_2_10_10_10_REV:
  case VertexAttributeType::INT_2_10_10_10_REV: return 4;
  case VertexAttributeType::DOUBLE: return 8;
  default: std::unreachable(); break;
  }
}

uint32_t GetTextureDimensions(TextureTarget texture_target) {
  switch (texture_target) {
  case TextureTarget::TEXTURE_1D: return 1;
  case TextureTarget::TEXTURE_1D_ARRAY:
  case TextureTarget::TEXTURE_2D:
  case TextureTarget::TEXTURE_2D_MULTISAMPLE:
  case TextureTarget::TEXTURE_RECTANGLE:
  case TextureTarget::TEXTURE_CUBE_MAP: return 2;
  case TextureTarget::TEXTURE_CUBE_MAP_ARRAY:
  case TextureTarget::TEXTURE_2D_ARRAY:
  case TextureTarget::TEXTURE_3D:
  case TextureTarget::TEXTURE_2D_MULTISAMPLE_ARRAY: return 3;
  case TextureTarget::TEXTURE_BUFFER: return 0;
  default: std::unreachable(); break;
  }
}

const Pixel &GetFormatInformation(InternalFormat internal_format) {
  return format_information[internal_format];
}

ErrorCode GetErrorCode(uint32_t error_code) {
  switch (error_code) {
  case GL_NO_ERROR: return ErrorCode::NO_ERROR;
  case GL_INVALID_ENUM: return ErrorCode::INVALID_ENUM;
  case GL_INVALID_VALUE: return ErrorCode::INVALID_VALUE;
  case GL_INVALID_OPERATION: return ErrorCode::INVALID_OPERATION;
  case GL_INVALID_FRAMEBUFFER_OPERATION: return ErrorCode::INVALID_FRAMEBUFFER_OPERATION;
  case GL_OUT_OF_MEMORY: return ErrorCode::OUT_OF_MEMORY;
  case GL_STACK_UNDERFLOW: return ErrorCode::STACK_UNDERFLOW;
  case GL_STACK_OVERFLOW: return ErrorCode::STACK_OVERFLOW;
  default: std::unreachable();
  }
}

std::string_view ToString(ErrorCode error_code) {
  switch (error_code) {
  case ErrorCode::NO_ERROR: return "ErrorCode::NO_ERROR";
  case ErrorCode::INVALID_ENUM: return "ErrorCode::INVALID_ENUM";
  case ErrorCode::INVALID_VALUE: return "ErrorCode::INVALID_VALUE";
  case ErrorCode::INVALID_OPERATION: return "ErrorCode::INVALID_OPERATION";
  case ErrorCode::INVALID_FRAMEBUFFER_OPERATION: return "ErrorCode::INVALID_FRAMEBUFFER_OPERATION";
  case ErrorCode::OUT_OF_MEMORY: return "ErrorCode::OUT_OF_MEMORY";
  case ErrorCode::STACK_UNDERFLOW: return "ErrorCode::STACK_UNDERFLOW";
  case ErrorCode::STACK_OVERFLOW: return "ErrorCode::STACK_OVERFLOW";
  default: std::unreachable();
  }
}

std::string_view ToString(AttributeType attribute_type) {
  switch (attribute_type) {
  case AttributeType::FLOAT: return "AttributeType::FLOAT";
  case AttributeType::FLOAT_VEC2: return "AttributeType::FLOAT_VEC2";
  case AttributeType::FLOAT_VEC3: return "AttributeType::FLOAT_VEC3";
  case AttributeType::FLOAT_VEC4: return "AttributeType::FLOAT_VEC4";
  case AttributeType::FLOAT_MAT2: return "AttributeType::FLOAT_MAT2";
  case AttributeType::FLOAT_MAT3: return "AttributeType::FLOAT_MAT3";
  case AttributeType::FLOAT_MAT4: return "AttributeType::FLOAT_MAT4";
  case AttributeType::FLOAT_MAT2x3: return "AttributeType::FLOAT_MAT2x3";
  case AttributeType::FLOAT_MAT2x4: return "AttributeType::FLOAT_MAT2x4";
  case AttributeType::FLOAT_MAT3x2: return "AttributeType::FLOAT_MAT3x2";
  case AttributeType::FLOAT_MAT3x4: return "AttributeType::FLOAT_MAT3x4";
  case AttributeType::FLOAT_MAT4x2: return "AttributeType::FLOAT_MAT4x2";
  case AttributeType::FLOAT_MAT4x3: return "AttributeType::FLOAT_MAT4x3";
  case AttributeType::DOUBLE: return "AttributeType::DOUBLE";
  case AttributeType::DOUBLE_VEC2: return "AttributeType::DOUBLE_VEC2";
  case AttributeType::DOUBLE_VEC3: return "AttributeType::DOUBLE_VEC3";
  case AttributeType::DOUBLE_VEC4: return "AttributeType::DOUBLE_VEC4";
  case AttributeType::DOUBLE_MAT2: return "AttributeType::DOUBLE_MAT2";
  case AttributeType::DOUBLE_MAT3: return "AttributeType::DOUBLE_MAT3";
  case AttributeType::DOUBLE_MAT4: return "AttributeType::DOUBLE_MAT4";
  case AttributeType::DOUBLE_MAT2x3: return "AttributeType::DOUBLE_MAT2x3";
  case AttributeType::DOUBLE_MAT2x4: return "AttributeType::DOUBLE_MAT2x4";
  case AttributeType::DOUBLE_MAT3x2: return "AttributeType::DOUBLE_MAT3x2";
  case AttributeType::DOUBLE_MAT3x4: return "AttributeType::DOUBLE_MAT3x4";
  case AttributeType::DOUBLE_MAT4x2: return "AttributeType::DOUBLE_MAT4x2";
  case AttributeType::DOUBLE_MAT4x3: return "AttributeType::DOUBLE_MAT4x3";
  case AttributeType::INT: return "AttributeType::INT";
  case AttributeType::INT_VEC2: return "AttributeType::INT_VEC2";
  case AttributeType::INT_VEC3: return "AttributeType::INT_VEC3";
  case AttributeType::INT_VEC4: return "AttributeType::INT_VEC4";
  case AttributeType::UNSIGNED_INT: return "AttributeType::UNSIGNED_INT";
  case AttributeType::UNSIGNED_INT_VEC2: return "AttributeType::UNSIGNED_INT_VEC2";
  case AttributeType::UNSIGNED_INT_VEC3: return "AttributeType::UNSIGNED_INT_VEC3";
  case AttributeType::UNSIGNED_INT_VEC4: return "AttributeType::UNSIGNED_INT_VEC4";
  default: std::unreachable();
  }
}

} // namespace Terabithia