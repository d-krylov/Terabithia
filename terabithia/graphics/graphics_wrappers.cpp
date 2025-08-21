#include "terabithia/graphics/include/graphics_wrappers.h"

namespace Terabithia {

ErrorCode GetError() {
  auto status = glGetError();
  return GetErrorCode(status);
}

// PROGRAM

Handle CreateProgram() {
  return GL_CALL(glCreateProgram);
}

Handle CreateShader(ShaderType shader_type) {
  auto type = std::to_underlying(shader_type);
  auto shader = GL_CALL(glCreateShader, type);
  return shader;
}

void ShaderSource(Handle shader, const char *sources) {
  GL_CALL(glShaderSource, shader, 1, &sources, nullptr);
}

void CompileShader(Handle shader) {
  GL_CALL(glCompileShader, shader);
}

void AttachShader(Handle program, Handle shader) {
  GL_CALL(glAttachShader, program, shader);
}

void DeleteShader(Handle shader) {
  GL_CALL(glDeleteShader, shader);
}

void DeleteProgram(Handle program) {
  GL_CALL(glDeleteProgram, program);
}

void UseProgram(Handle program) {
  GL_CALL(glUseProgram, program);
}

void LinkProgram(Handle program) {
  GL_CALL(glLinkProgram, program);
}

int32_t GetUniformLocation(Handle program, std::string_view name) {
  return glGetUniformLocation(program, name.data());
}

void ProgramUniform(Handle program, int32_t location, int32_t value) {
  GL_CALL(glProgramUniform1i, program, location, value);
}

void ProgramUniform(Handle program, int32_t location, uint32_t value) {
  GL_CALL(glProgramUniform1ui, program, location, value);
}

void ProgramUniform(Handle program, int32_t location, float value) {
  glProgramUniform1f(program, location, value);
}

void ProgramUniform(Handle program, int32_t location, double value) {
  glProgramUniform1d(program, location, value);
}

void ProgramUniformV2(Handle program, int32_t location, std::span<const float> value) {
  glProgramUniform2fv(program, location, value.size() / 2, value.data());
}

void ProgramUniformV2(Handle program, int32_t location, std::span<const int32_t> value) {
  glProgramUniform2iv(program, location, value.size() / 2, value.data());
}

void ProgramUniformV2(Handle program, int32_t location, std::span<const uint32_t> value) {
  glProgramUniform2uiv(program, location, value.size() / 2, value.data());
}

void ProgramUniformV3(Handle program, int32_t location, std::span<const float> value) {
  glProgramUniform3fv(program, location, value.size() / 3, value.data());
}

void ProgramUniformV3(Handle program, int32_t location, std::span<const int32_t> value) {
  glProgramUniform3iv(program, location, value.size() / 3, value.data());
}

void ProgramUniformV3(Handle program, int32_t location, std::span<const uint32_t> value) {
  glProgramUniform3uiv(program, location, value.size() / 3, value.data());
}

void ProgramUniformV4(Handle program, int32_t location, std::span<const float> value) {
  glProgramUniform4fv(program, location, value.size() / 4, value.data());
}

void ProgramUniformV4(Handle program, int32_t location, std::span<const int32_t> value) {
  glProgramUniform4iv(program, location, value.size() / 4, value.data());
}

void ProgramUniformV4(Handle program, int32_t location, std::span<const uint32_t> value) {
  glProgramUniform4uiv(program, location, value.size() / 4, value.data());
}

void ProgramUniformM4(Handle program, int32_t location, std::span<const float> value, bool transpose) {
  glProgramUniformMatrix4fv(program, location, value.size() / 16, transpose, value.data());
}

void GetShaderParameter(Handle shader, ShaderParameterName parameter, int32_t &result) {
  auto native_parameter = std::to_underlying(parameter);
  GL_CALL(glGetShaderiv, shader, native_parameter, &result);
}

void GetProgramParameter(Handle program, ProgramParameterName parameter, int32_t &result) {
  auto native_parameter = std::to_underlying(parameter);
  GL_CALL(glGetProgramiv, program, native_parameter, &result);
}

std::string GetShaderInfoLog(Handle shader, uint32_t length) {
  std::string result(length, ' ');
  GL_CALL(glGetShaderInfoLog, shader, result.size(), nullptr, result.data());
  return result;
}

std::string GetProgramInfoLog(Handle program, uint32_t length) {
  std::string result(length, ' ');
  GL_CALL(glGetProgramInfoLog, program, result.size(), nullptr, result.data());
  return result;
}

// PROGRAM INTROSPECTION

std::vector<int32_t> GetProgramResource(Handle program, ProgramInterface interface, uint32_t index,
                                        std::span<const ProgramResourceProperty> properties) {
  auto size = properties.size();
  auto result = std::vector<int32_t>(size);
  auto native_interface = std::to_underlying(interface);
  GL_CALL(glGetProgramResourceiv, program, native_interface, index, size, (const GLenum *)properties.data(), size, nullptr, result.data());
  return result;
}

std::string GetProgramResourceName(Handle program, ProgramInterface interface, uint32_t index, uint32_t name_size) {
  auto name = std::string(name_size, ' ');
  auto native_interface = std::to_underlying(interface);
  GL_CALL(glGetProgramResourceName, program, native_interface, index, name_size, nullptr, name.data());
  return name;
}

void GetProgramInterface(Handle program, ProgramInterface program_interface, ProgramInterfaceParameterName name, int32_t &result) {
  auto native_interface = std::to_underlying(program_interface);
  auto native_name = std::to_underlying(name);
  GL_CALL(glGetProgramInterfaceiv, program, native_interface, native_name, &result);
}

// VERTEX ARRAY

void CreateVertexArray(Handle &vertex_array) {
  GL_CALL(glCreateVertexArrays, 1, &vertex_array);
}

void DeleteVertexArray(Handle &vertex_array) {
  GL_CALL(glDeleteVertexArrays, 1, &vertex_array);
}

void BindVertexArray(Handle vertex_array) {
  GL_CALL(glBindVertexArray, vertex_array);
}

void EnableVertexArrayAttribute(Handle vertex_array, uint32_t index) {
  GL_CALL(glEnableVertexArrayAttrib, vertex_array, index);
}

void VertexArrayBindingDivisor(Handle vertex_array, uint32_t binding_index, uint32_t divisor) {
  GL_CALL(glVertexArrayBindingDivisor, vertex_array, binding_index, divisor);
}

void VertexArrayVertexBuffer(Handle vertex_array, Handle vertex_buffer, uint32_t binding, int32_t stride, int64_t offset) {
  GL_CALL(glVertexArrayVertexBuffer, vertex_array, binding, vertex_buffer, offset, stride);
}

void VertexArrayElementBuffer(Handle vertex_array, Handle element_buffer) {
  GL_CALL(glVertexArrayElementBuffer, vertex_array, element_buffer);
}

void VertexArrayAttributeBinding(Handle vertex_array, uint32_t attribute_index, uint32_t binding_index) {
  GL_CALL(glVertexArrayAttribBinding, vertex_array, attribute_index, binding_index);
}

void VertexArrayAttributeFormat(Handle vertex_array, uint32_t index, int32_t size, VertexAttributeType type, uint32_t offset, bool normalized) {
  auto native_type = std::to_underlying(type);
  GL_CALL(glVertexArrayAttribFormat, vertex_array, index, size, native_type, GLboolean(normalized), offset);
}

void VertexArrayAttributeLFormat(Handle vertex_array, uint32_t index, int32_t size, VertexAttributeType type, uint32_t offset) {
  auto native_type = std::to_underlying(type);
  GL_CALL(glVertexArrayAttribLFormat, vertex_array, index, size, native_type, offset);
}

void VertexArrayAttributeIFormat(Handle vertex_array, uint32_t index, int32_t size, VertexAttributeType type, uint32_t offset) {
  auto native_type = std::to_underlying(type);
  GL_CALL(glVertexArrayAttribIFormat, vertex_array, index, size, native_type, offset);
}

// BUFFER

void CreateBuffer(Handle &buffer) {
  GL_CALL(glCreateBuffers, 1, &buffer);
}

void DeleteBuffer(Handle &buffer) {
  GL_CALL(glDeleteBuffers, 1, &buffer);
}

void CreateBufferStorage(Handle buffer, BufferStorageMask storage_mask, int64_t size) {
  GL_CALL(glNamedBufferStorage, buffer, size, nullptr, (int32_t)storage_mask);
}

bool UnmapBuffer(Handle buffer) {
  auto result = GL_CALL(glUnmapNamedBuffer, buffer);
  return result;
}

void *MapBuffer(Handle buffer, MapBufferAccess buffer_access) {
  auto access = std::to_underlying(buffer_access);
  auto mapped = GL_CALL(glMapNamedBuffer, buffer, access);
  return mapped;
}

void *MapBufferRange(Handle buffer, int64_t offset, int64_t size, MapBufferAccessMask map_access) {
  auto access = static_cast<int32_t>(map_access);
  auto mapped = GL_CALL(glMapNamedBufferRange, buffer, offset, size, access);
  return mapped;
}

// TEXTURE

void CreateTexture(Handle &texture, TextureTarget texture_target) {
  auto target = std::to_underlying(texture_target);
  GL_CALL(glCreateTextures, target, 1, &texture);
}

void DeleteTexture(Handle &texture) {
  GL_CALL(glDeleteTextures, 1, &texture);
}

void BindTextureUnit(Handle texture, uint32_t unit) {
  GL_CALL(glBindTextureUnit, unit, texture);
}

void CreateTextureStorage(Handle texture, int32_t levels, int32_t width, InternalFormat sized_format) {
  auto native_format = std::to_underlying(sized_format);
  GL_CALL(glTextureStorage1D, texture, levels, native_format, width);
}

void CreateTextureStorage(Handle texture, int32_t levels, const Extent2D &extent, InternalFormat sized_format) {
  auto native_format = std::to_underlying(sized_format);
  GL_CALL(glTextureStorage2D, texture, levels, native_format, extent.width, extent.height);
}

void CreateTextureStorage(Handle texture, int32_t levels, const Extent3D &extent, InternalFormat sized_format) {
  auto native_format = std::to_underlying(sized_format);
  GL_CALL(glTextureStorage3D, texture, levels, native_format, extent.width, extent.height, extent.depth);
}

void TextureSubImage(Handle texture, int32_t width, const Pixel &pixel, std::span<const std::byte> data, int32_t xoffset, int32_t level) {
  auto native_format = std::to_underlying(pixel.format);
  auto native_type = std::to_underlying(pixel.type);
  GL_CALL(glTextureSubImage1D, texture, level, xoffset, width, native_format, native_type, data.data());
}

// clang-format off
void TextureSubImage(Handle texture, const Extent2D &extent, const Pixel &pixel, std::span<const std::byte> data, const Offset2D offset, int32_t level) {
  auto native_format = std::to_underlying(pixel.format);
  auto native_type = std::to_underlying(pixel.type);
  GL_CALL(glTextureSubImage2D, texture, level, offset.x, offset.y, extent.width, extent.height, native_format, native_type, data.data());
}

void TextureSubImage(Handle texture, const Extent3D &extent, const Pixel &pixel, std::span<const std::byte> data, const Offset3D offset, int32_t level) {
  auto native_format = std::to_underlying(pixel.format);
  auto native_type = std::to_underlying(pixel.type);
  GL_CALL(glTextureSubImage3D, texture, level, offset.x, offset.y, offset.z, extent.width, extent.height, extent.depth, native_format, native_type, data.data());
}
// clang-format on

// OPTIONS

void Viewport(int32_t x, int32_t y, int32_t width, int32_t height) {
  GL_CALL(glViewport, x, y, width, height);
}

void Scissor(int32_t x, int32_t y, int32_t w, int32_t h) {
  GL_CALL(glScissor, x, y, w, h);
}

void ClearColor(float red, float green, float blue, float alpha) {
  GL_CALL(glClearColor, red, green, blue, alpha);
}

void Clear(ClearBufferMask mask) {
  GL_CALL(glClear, (int32_t)mask);
}

void Enable(Capability capability) {
  auto native_capability = std::to_underlying(capability);
  GL_CALL(glEnable, native_capability);
}

void Disable(Capability capability) {
  auto native_capability = std::to_underlying(capability);
  GL_CALL(glDisable, native_capability);
}

void SetBlendEquation(BlendEquationMode mode) {
  auto native_mode = std::to_underlying(mode);
  GL_CALL(glBlendEquation, native_mode);
}

void SetBlendFunctionSeparate(BlendFunction srgb, BlendFunction drgb, BlendFunction salpha, BlendFunction dalpha) {
  auto srgb_native = std::to_underlying(srgb);
  auto drgb_native = std::to_underlying(drgb);
  auto salpha_native = std::to_underlying(salpha);
  auto dalpha_native = std::to_underlying(dalpha);
  GL_CALL(glBlendFuncSeparate, srgb_native, drgb_native, salpha_native, dalpha_native);
}

void SetDebugMessageCallback(GLDEBUGPROC callback) {
  GL_CALL(glDebugMessageCallback, callback, nullptr);
}

// DRAW

void DrawArrays(int32_t first, int32_t count, PrimitiveKind primitive_kind) {
  auto kind = std::to_underlying(primitive_kind);
  GL_CALL(glDrawArrays, kind, first, count);
}

void DrawElementsBaseVertex(int32_t count, int32_t base, DrawElementType index_type, std::byte *indices, PrimitiveKind primitive_kind) {
  auto kind = std::to_underlying(primitive_kind);
  auto type = std::to_underlying(index_type);
  GL_CALL(glDrawElementsBaseVertex, kind, count, type, indices, base);
}

} // namespace Terabithia