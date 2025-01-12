#ifndef TERABITHIA_GRAPHICS_WRAPPERS_H
#define TERABITHIA_GRAPHICS_WRAPPERS_H

#include "graphics_types.h"
#include <string>
#include <iostream>

namespace Terabithia ::GL {

using DescriptorType = uint32_t;

inline Error GetError() { return Error(glGetError()); }

inline void ErrorHandler() {
  auto error = GetError();
  if (error != Error::NO_ERROR) {
    std::cout << uint32_t(error) << std::endl;
    std::abort();
  }
}

template <typename F, typename... ARGS>
  requires CallableWithExactArgs<F, ARGS...> decltype(auto)
GL_CALL(F &&function, ARGS &&...arguments) {
  if constexpr (std::is_void_v<std::invoke_result_t<F, ARGS...>>) {
    std::forward<F>(function)(std::forward<ARGS>(arguments)...);
    ErrorHandler();
  } else {
    auto result = std::forward<F>(function)(std::forward<ARGS>(arguments)...);
    ErrorHandler();
    return result;
  }
}

// Vertex Array
inline void CreateVertexArray(DescriptorType &vao) { GL_CALL(glCreateVertexArrays, 1, &vao); }
inline void DeleteVertexArray(const DescriptorType &vao) { GL_CALL(glDeleteVertexArrays, 1, &vao); }
inline void BindVertexArray(DescriptorType &vao) { GL_CALL(glBindVertexArray, vao); }
inline void EnableAttribute(DescriptorType &vao, uint32_t index) { GL_CALL(glEnableVertexArrayAttrib, vao, index); }
inline void SetElementBuffer(const DescriptorType &vao, const DescriptorType &ebo) { GL_CALL(glVertexArrayElementBuffer, vao, ebo); }

inline void SetAttributeBinding(DescriptorType &vao, uint32_t attribute_index, uint32_t binding_index) {
  GL_CALL(glVertexArrayAttribBinding, vao, attribute_index, binding_index);
}

inline void SetBindingDivisor(DescriptorType &vao, uint32_t binding_index, uint32_t divisor) {
  GL_CALL(glVertexArrayBindingDivisor, vao, binding_index, divisor);
}

inline void SetVertexBuffer(const DescriptorType &vao, const DescriptorType &vbo, uint32_t binding, int32_t stride, int64_t offset = 0) {
  GL_CALL(glVertexArrayVertexBuffer, vao, binding, vbo, offset, stride);
}

inline void SetAttributeFormat(const DescriptorType &vao, uint32_t index, int32_t count, PrimitiveFormat f, uint32_t offset, bool n) {
  GL_CALL(glVertexArrayAttribFormat, vao, index, count, Cast(f), uint8_t(n), offset);
}

inline void SetAttributeFormat(const DescriptorType &vao, uint32_t index, int32_t count, PrimitiveFormat f, uint32_t offset) {
  GL_CALL((f == PrimitiveFormat::DOUBLE) ? glVertexArrayAttribLFormat : glVertexArrayAttribIFormat, vao, index, count, Cast(f), offset);
}

// Program
inline DescriptorType CreateProgram() { return GL_CALL(glCreateProgram); }
inline void UseProgram(const DescriptorType &program) { GL_CALL(glUseProgram, program); }
inline void LinkProgram(const DescriptorType &program) { GL_CALL(glLinkProgram, program); }
inline void DeleteProgram(DescriptorType program) { GL_CALL(glDeleteProgram, program); }

inline int32_t GetProgramParameter(DescriptorType program, ProgramParameter parameter) {
  auto result{0};
  GL_CALL(glGetProgramiv, program, Cast(parameter), &result);
  return result;
}

inline std::string GetProgramLog(const DescriptorType &program) {
  auto size = GetProgramParameter(program, ProgramParameter::INFO_LOG_LENGTH);
  std::string message(size, ' ');
  GL_CALL(glGetProgramInfoLog, program, size, (int32_t *)nullptr, message.data());
  return message;
}

// Shader
inline DescriptorType CreateShader(ShaderType shader_type) { return GL_CALL(glCreateShader, Cast(shader_type)); }
inline void CompileShader(const DescriptorType &shader) { GL_CALL(glCompileShader, shader); }
inline void DeleteShader(const DescriptorType &shader) { GL_CALL(glDeleteShader, shader); }
inline void AttachShader(DescriptorType program, DescriptorType shader) { GL_CALL(glAttachShader, program, shader); }

inline void ShaderSource(DescriptorType &shader, const char *const &sources) {
  GL_CALL(glShaderSource, shader, 1, &sources, (const int *)nullptr);
}

template <ContiguousSizedRangeT<std::byte> R> inline void ShaderBinary(const DescriptorType &shader, R &&binary_data) {
  GL_CALL(glShaderBinary, 1, &shader, uint32_t(GL_SHADER_BINARY_FORMAT_SPIR_V), (const void *)std::ranges::data(binary_data),
          (int32_t)std::ranges::size(binary_data));
}

inline void SpecializeShader(const DescriptorType &shader, const char *entrypoint = "main") {
  GL_CALL(glSpecializeShader, shader, entrypoint, 0u, (const uint32_t *)nullptr, (const uint32_t *)nullptr);
}

inline int32_t GetShaderParameter(DescriptorType shader, ShaderParameter parameter) {
  auto result{0};
  GL_CALL(glGetShaderiv, shader, Cast(parameter), &result);
  return result;
}

inline std::string GetShaderLog(const DescriptorType &shader) {
  auto size = GetShaderParameter(shader, ShaderParameter::INFO_LOG_LENGTH);
  std::string message(size, ' ');
  GL_CALL(glGetShaderInfoLog, shader, size, (int32_t *)nullptr, message.data());
  return message;
}

// Uniform
inline uint32_t GetUniformLocation(DescriptorType program, std::string_view name) {
  return GL_CALL(glGetUniformLocation, program, name.data());
}

inline void SetUniform(int32_t location, float value) { GL_CALL(glUniform1f, location, value); }
inline void SetUniform(int32_t location, int32_t value) { GL_CALL(glUniform1i, location, value); }
inline void SetUniform(int32_t location, uint32_t value) { GL_CALL(glUniform1ui, location, value); }
inline void SetUniform(int32_t location, float v0, float v1) { GL_CALL(glUniform2f, location, v0, v1); }
inline void SetUniform(int32_t location, float v0, float v1, float v2) { GL_CALL(glUniform3f, location, v0, v1, v2); }
inline void SetUniform(int32_t location, float v0, float v1, float v2, float v3) { GL_CALL(glUniform4f, location, v0, v1, v2, v3); }
inline void SetUniform(int32_t location, int32_t v0, int32_t v1) { GL_CALL(glUniform2i, location, v0, v1); }
inline void SetUniform(int32_t location, int32_t v0, int32_t v1, int32_t v2) { GL_CALL(glUniform3i, location, v0, v1, v2); }
inline void SetUniform(int32_t location, int32_t v0, int32_t v1, int32_t v2, int32_t v3) { GL_CALL(glUniform4i, location, v0, v1, v2, v3); }
inline void SetUniform(int32_t location, uint32_t v0, uint32_t v1) { GL_CALL(glUniform2ui, location, v0, v1); }
inline void SetUniform(int32_t location, uint32_t v0, uint32_t v1, uint32_t v2) { GL_CALL(glUniform3ui, location, v0, v1, v2); }
inline void SetUniform(int32_t location, uint32_t v0, uint32_t v1, uint32_t v2, uint32_t v3) {
  GL_CALL(glUniform4ui, location, v0, v1, v2, v3);
}

// clang-format off
template <typename T, int32_t N> inline void SetUniform(int32_t location, int32_t count, const T *value) {
  if constexpr (std::same_as<T, float>         && N == 2)  GL_CALL(glUniform2fv, location, count, value);
  else if constexpr (std::same_as<T, float>    && N == 3)  GL_CALL(glUniform3fv, location, count, value);
  else if constexpr (std::same_as<T, float>    && N == 4)  GL_CALL(glUniform4fv, location, count, value);
  else if constexpr (std::same_as<T, int32_t>  && N == 2)  GL_CALL(glUniform2iv, location, count, value);
  else if constexpr (std::same_as<T, int32_t>  && N == 3)  GL_CALL(glUniform3iv, location, count, value);
  else if constexpr (std::same_as<T, int32_t>  && N == 4)  GL_CALL(glUniform4iv, location, count, value);
  else if constexpr (std::same_as<T, uint32_t> && N == 2)  GL_CALL(glUniform2uiv, location, count, value);
  else if constexpr (std::same_as<T, uint32_t> && N == 3)  GL_CALL(glUniform3uiv, location, count, value);
  else if constexpr (std::same_as<T, uint32_t> && N == 4)  GL_CALL(glUniform4uiv, location, count, value);
  else if constexpr (std::same_as<T, float>    && N == 16) GL_CALL(glUniformMatrix4fv, location, count, uint8_t(0), value);
}
// clang-format on

// Buffer

inline void CreateBuffer(DescriptorType &buffer) { GL_CALL(glCreateBuffers, 1, &buffer); }
inline void DeleteBuffer(const DescriptorType &buffer) { GL_CALL(glDeleteBuffers, 1, &buffer); }
inline void BindBuffer(DescriptorType &buffer, BufferTarget target) { GL_CALL(glBindBuffer, Cast(target), buffer); }

[[nodiscard]] inline bool UnmapBuffer(DescriptorType &buffer) { return static_cast<bool>(GL_CALL(glUnmapNamedBuffer, buffer)); }

template <typename T = std::byte> inline T *MapBuffer(DescriptorType &buffer, int64_t offset, int64_t size, MapAccess map_access) {
  return reinterpret_cast<T *>(GL_CALL(glMapNamedBufferRange, buffer, offset, size, Cast(map_access)));
}

inline void BindBufferBase(DescriptorType &buffer, BufferTarget target, uint32_t index) {
  GL_CALL(glBindBufferBase, Cast(target), index, buffer);
}

inline void CreateBufferStorage(DescriptorType &buffer, BufferStorage storage, int64_t size) {
  GL_CALL(glNamedBufferStorage, buffer, size, (const void *)(nullptr), Cast(storage));
}

template <PodType T, ContiguousSizedRangeT<T> R> inline void SetBufferData(DescriptorType &buffer, int64_t offset, R &&buffer_data) {
  int64_t size = std::ranges::size(buffer_data) * sizeof(T);
  GL_CALL(glNamedBufferSubData, buffer, offset, size, (const void *)std::ranges::data(buffer_data));
}

// Framebuffer
inline void CreateFramebuffer(DescriptorType &framebuffer) { GL_CALL(glCreateFramebuffers, 1, &framebuffer); }
inline void DeleteFramebuffer(const DescriptorType &framebuffer) { GL_CALL(glDeleteFramebuffers, 1, &framebuffer); }
inline void BindFramebuffer(DescriptorType &framebuffer) { GL_CALL(glBindFramebuffer, uint32_t(GL_FRAMEBUFFER), framebuffer); }
inline void UnbindFramebuffer() { GL_CALL(glBindFramebuffer, uint32_t(GL_FRAMEBUFFER), 0u); }

inline FramebufferStatus CheckFramebufferStatus(DescriptorType &framebuffer) {
  return FramebufferStatus(GL_CALL(glCheckNamedFramebufferStatus, framebuffer, uint32_t(GL_FRAMEBUFFER)));
}

inline void FramebufferTexture(DescriptorType &framebuffer, DescriptorType &texture, AttachmentPoint point, int32_t level) {
  GL_CALL(glNamedFramebufferTexture, framebuffer, Cast(point), texture, level);
}

inline void FramebufferRenderbuffer(DescriptorType &framebuffer, DescriptorType &renderbuffer, AttachmentPoint point) {
  GL_CALL(glNamedFramebufferRenderbuffer, framebuffer, Cast(point), uint32_t(GL_RENDERBUFFER), renderbuffer);
}

inline void FramebufferTextureLayer(DescriptorType &framebuffer, DescriptorType &texture, AttachmentPoint point, int32_t level,
                                    int32_t layer) {
  GL_CALL(glNamedFramebufferTextureLayer, framebuffer, Cast(point), texture, level, layer);
}

// Renderbuffer
inline void CreateRenderbuffer(DescriptorType &renderbuffer) { GL_CALL(glCreateRenderbuffers, 1, &renderbuffer); }
inline void DeleteRenderbuffer(const DescriptorType &renderbuffer) { GL_CALL(glDeleteRenderbuffers, 1, &renderbuffer); }
inline void BindRenderbuffer(const DescriptorType &renderbuffer) { GL_CALL(glBindRenderbuffer, uint32_t(GL_RENDERBUFFER), renderbuffer); }

inline void CreateRenderbufferStorage(DescriptorType &renderbuffer, InternalFormat format, int32_t w, int32_t h, int32_t samples = 1) {
  GL_CALL(glNamedRenderbufferStorageMultisample, renderbuffer, samples, Cast(format), w, h);
}

// Texture

inline void CreateTexture(DescriptorType &texture, TextureTarget target) { GL_CALL(glCreateTextures, Cast(target), 1, &texture); }

inline void DeleteTexture(const DescriptorType &texture) { GL_CALL(glDeleteTextures, 1, &texture); }

inline void BindTextureUnit(DescriptorType &texture, uint32_t unit) { GL_CALL(glBindTextureUnit, unit, texture); }

inline void GenerateTextureMipmap(const DescriptorType &texture) { GL_CALL(glGenerateTextureMipmap, texture); }

inline DescriptorType GetTextureHandle(DescriptorType &texture) { return GL_CALL(glGetTextureHandleARB, texture); }

inline void CreateTextureStorage(DescriptorType &texture, int32_t levels, InternalFormat format, int32_t w) {
  GL_CALL(glTextureStorage1D, texture, levels, Cast(format), w);
}

inline void CreateTextureStorage(DescriptorType &texture, int32_t levels, InternalFormat format, int32_t w, int32_t h) {
  GL_CALL(glTextureStorage2D, texture, levels, Cast(format), w, h);
}

inline void CreateTextureStorage(DescriptorType &texture, int32_t levels, InternalFormat format, int32_t w, int32_t h, int32_t d) {
  GL_CALL(glTextureStorage3D, texture, levels, Cast(format), w, h, d);
}

template <ContiguousSizedRange R>
inline void TextureSubImage(DescriptorType &texture, int32_t width, PixelFormat format, PixelType type, R &&data, int32_t x,
                            int32_t level) {
  GL_CALL(glTextureSubImage1D, texture, level, x, width, Cast(format), Cast(type), (const void *)std::ranges::data(data));
}

template <ContiguousSizedRange R>
inline void TextureSubImage(DescriptorType &texture, int32_t width, int32_t height, PixelFormat format, PixelType type, R &&data, int32_t x,
                            int32_t y, int32_t level) {
  GL_CALL(glTextureSubImage2D, texture, level, x, y, width, height, Cast(format), Cast(type), (const void *)std::ranges::data(data));
}

template <ContiguousSizedRange R>
inline void TextureSubImage(DescriptorType &texture, int32_t width, int32_t height, int32_t depth, PixelFormat format, PixelType type,
                            R &&data, int32_t x, int32_t y, int32_t z, int32_t level) {
  GL_CALL(glTextureSubImage3D, texture, level, x, y, z, width, height, depth, Cast(format), Cast(type),
          (const void *)std::ranges::data(data));
}

inline void SetTextureParameter(DescriptorType &texture, TextureParameter parameter, int32_t value) {
  GL_CALL(glTextureParameteri, texture, Cast(parameter), value);
}

// Draw
inline void DrawArrays(int32_t first, int32_t count, PrimitiveKind kind = PrimitiveKind::TRIANGLES) {
  GL_CALL(glDrawArrays, Cast(kind), first, count);
}

inline void DrawArraysInstanced(int32_t indices, int32_t instances, int32_t first = 0, PrimitiveKind kind = PrimitiveKind::TRIANGLES) {
  GL_CALL(glDrawArraysInstanced, Cast(kind), first, indices, instances);
}

inline void DrawElementsBaseVertex(int32_t count, int64_t indices, int32_t base_vertex, IndexType index = IndexType::UNSIGNED_INT,
                                   PrimitiveKind kind = PrimitiveKind::TRIANGLES) {
  GL_CALL(glDrawElementsBaseVertex, Cast(kind), count, Cast(index), (const void *)indices, base_vertex);
}

// Options
inline void SetClearColor(float r, float g, float b, float a) { GL_CALL(glClearColor, r, g, b, a); }
inline void Clear(BufferBit bit = BufferBit::COLOR) { GL_CALL(glClear, Cast(bit)); }
inline void Enable(Capabilities capabilities) { GL_CALL(glEnable, Cast(capabilities)); }
inline void Disable(Capabilities capabilities) { GL_CALL(glDisable, Cast(capabilities)); }
inline void SetViewport(int32_t x, int32_t y, int32_t width, int32_t height) { GL_CALL(glViewport, x, y, width, height); }
inline void SetScissor(int32_t x, int32_t y, int32_t w, int32_t h) { GL_CALL(glScissor, x, y, w, h); }
inline void SetBlendEquation(BlendEquation operation) { GL_CALL(glBlendEquation, Cast(operation)); }

inline void SetBlendFunction(BlendFactor from_rgb, BlendFactor to_rgb, BlendFactor from_alpha, BlendFactor to_alpha) {
  GL_CALL(glBlendFuncSeparate, Cast(from_rgb), Cast(to_rgb), Cast(from_alpha), Cast(to_alpha));
}

inline void SetStencilOperation(StencilOperation fail, StencilOperation zfail, StencilOperation zpass) {
  GL_CALL(glStencilOp, Cast(fail), Cast(zfail), Cast(zpass));
}

inline void SetStencilFunction(ComparasionFunction function, int32_t reference, uint32_t mask) {
  GL_CALL(glStencilFunc, Cast(function), reference, mask);
}

template <typename... T> inline void Enable(T... capabilities) { (Enable(capabilities), ...); }
template <typename... T> inline void Disable(T... capabilities) { (Disable(capabilities), ...); }

// Debug

inline void SetDebugMessageCallback(GLDEBUGPROC callback) { GL_CALL(glDebugMessageCallback, callback, (const void *)nullptr); }

} // namespace Terabithia::GL

#endif // TERABITHIA_GRAPHICS_WRAPPERS_H