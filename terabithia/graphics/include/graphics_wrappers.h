#ifndef TERABITHIA_GRAPHICS_WRAPPERS_H
#define TERABITHIA_GRAPHICS_WRAPPERS_H

#include "graphics_types.h"
#include <type_traits>
#include <utility>
#include <vector>
#include <string>

namespace Terabithia {

ErrorCode GetError();

// PROGRAM
Handle CreateProgram();
Handle CreateShader(ShaderType shader_type);

void CompileShader(Handle shader);
void ShaderSource(Handle shader, const char *sources);
void AttachShader(Handle program, Handle shader);
void DeleteShader(Handle shader);
void DeleteProgram(Handle program);
void UseProgram(Handle program);
void LinkProgram(Handle program);
void ProgramUniform(Handle program, int32_t location, int32_t value);
void ProgramUniform(Handle program, int32_t location, uint32_t value);
void ProgramUniform(Handle program, int32_t location, float value);
void ProgramUniform(Handle program, int32_t location, double value);
void ProgramUniformV2(Handle program, int32_t location, std::span<const float> value);
void ProgramUniformV2(Handle program, int32_t location, std::span<const int32_t> value);
void ProgramUniformV2(Handle program, int32_t location, std::span<const uint32_t> value);
void ProgramUniformV3(Handle program, int32_t location, std::span<const float> value);
void ProgramUniformV3(Handle program, int32_t location, std::span<const int32_t> value);
void ProgramUniformV3(Handle program, int32_t location, std::span<const uint32_t> value);
void ProgramUniformV4(Handle program, int32_t location, std::span<const float> value);
void ProgramUniformV4(Handle program, int32_t location, std::span<const int32_t> value);
void ProgramUniformV4(Handle program, int32_t location, std::span<const uint32_t> value);
void ProgramUniformM4(Handle program, int32_t location, std::span<const float> value, bool transpose);
void GetShaderParameter(Handle shader, ShaderParameterName parameter, int32_t &result);
void GetProgramParameter(Handle program, ProgramParameterName parameter, int32_t &result);
void DispatchCompute(uint32_t num_groups_x, uint32_t num_groups_y, uint32_t num_groups_z);

std::string GetShaderInfoLog(Handle shader, uint32_t length);
std::string GetProgramInfoLog(Handle program, uint32_t length);

int32_t GetUniformLocation(Handle program, std::string_view name);

// PROGRAM INTROSPECTION

void GetProgramInterface(Handle program, ProgramInterface program_interface, ProgramInterfaceParameterName name, int32_t &result);
std::string GetProgramResourceName(Handle program, ProgramInterface interface, uint32_t index, uint32_t name_size);
std::vector<int32_t> GetProgramResource(Handle program, ProgramInterface interface, uint32_t index,
                                        std::span<const ProgramResourceProperty> properties);

// VERTEX ARRAY
void CreateVertexArray(Handle &vertex_array);
void DeleteVertexArray(Handle &vertex_array);
void BindVertexArray(Handle vertex_array);
void EnableVertexArrayAttribute(Handle vertex_array, uint32_t index);
void VertexArrayBindingDivisor(Handle vertex_array, uint32_t binding_index, uint32_t divisor);
void VertexArrayVertexBuffer(Handle vertex_array, Handle vertex_buffer, uint32_t binding, int32_t stride, int64_t offset);
void VertexArrayElementBuffer(Handle vertex_array, Handle element_buffer);
void VertexArrayAttributeBinding(Handle vertex_array, uint32_t attribute_index, uint32_t binding_index);
void VertexArrayAttributeFormat(Handle vertex_array, uint32_t index, int32_t size, VertexAttributeType type, uint32_t offset, bool normalized);
void VertexArrayAttributeLFormat(Handle vertex_array, uint32_t index, int32_t size, VertexAttributeType type, uint32_t offset);
void VertexArrayAttributeIFormat(Handle vertex_array, uint32_t index, int32_t size, VertexAttributeType type, uint32_t offset);

// BUFFER

void CreateBuffer(Handle &buffer);
void DeleteBuffer(Handle &buffer);
void CreateBufferStorage(Handle buffer, BufferStorageMask storage_mask, int64_t size);
bool UnmapBuffer(Handle buffer);
void *MapBufferRange(Handle buffer, int64_t offset, int64_t size, MapBufferAccessMask map_access);
void *MapBuffer(Handle buffer, MapBufferAccess buffer_access);

// TEXTURE

void CreateTexture(Handle &texture, TextureTarget texture_target);
void DeleteTexture(Handle &texture);
void BindTextureUnit(Handle texture, uint32_t unit);
void CreateTextureStorage(Handle texture, int32_t levels, int32_t width, InternalFormat sized_format);
void CreateTextureStorage(Handle texture, int32_t levels, const Extent2D &extent, InternalFormat sized_format);
void CreateTextureStorage(Handle texture, int32_t levels, const Extent3D &extent, InternalFormat sized_format);
void BindImageTexture(Handle texture, uint32_t unit, BufferAccess access, InternalFormat format, int32_t level, int32_t layer);
// clang-format off
void TextureSubImage(Handle texture, int32_t width, const Pixel &pixel, std::span<const std::byte> data, int32_t xoffset = 0, int32_t level = 0);
void TextureSubImage(Handle texture, const Extent2D &extent, const Pixel &pixel, std::span<const std::byte> data, const Offset2D offset = {}, int32_t level = 0);
void TextureSubImage(Handle texture, const Extent3D &extent, const Pixel &pixel, std::span<const std::byte> data, const Offset3D offset = {}, int32_t level = 0);
// clang-format on

// OPTIONS
void Enable(Capability capability);
void Disable(Capability capability);
void Viewport(int32_t x, int32_t y, int32_t width, int32_t height);
void Scissor(int32_t x, int32_t y, int32_t w, int32_t h);
void ClearColor(float red, float green, float blue, float alpha);
void Clear(ClearBufferMask mask);
void SetBlendEquation(BlendEquationMode mode);
void SetBlendFunctionSeparate(BlendFunction srgb, BlendFunction drgb, BlendFunction salpha, BlendFunction dalpha);
void SetDebugMessageCallback(GLDEBUGPROC callback);
void SetDepthFunction(DepthFunction depth_function);
void CullFace(TriangleFace triangle_face);
void FrontFace(FrontFaceDirection direction);

// FRAMEBUFFER
void CreateFramebuffer(Handle &framebuffer);
void DeleteFramebuffer(Handle &framebuffer);
void UnbindFramebuffer(FramebufferTarget framebuffer_target);
void BindFramebuffer(Handle framebuffer, FramebufferTarget framebuffer_target);
void FramebufferAttach(Handle framebuffer, Handle texture, FramebufferAttachment point, int32_t level);
void FramebufferRenderbuffer(Handle framebuffer, Handle renderbuffer, FramebufferAttachment point);
void FramebufferTextureLayer(Handle framebuffer, Handle texture, FramebufferAttachment point, int32_t level, int32_t layer);
FramebufferStatus CheckFramebufferStatus(Descriptor &framebuffer, FramebufferTarget framebuffer_target);

// BARRIER
void MemoryBarrier(MemoryBarrierMask barrier_mask);
void MemoryBarrierByRegion(MemoryBarrierRegionMask barrier_mask);

// DRAW

void DrawArrays(int32_t first, int32_t count, PrimitiveKind primitive_kind = PrimitiveKind::TRIANGLES);
void DrawElementsBaseVertex(int32_t count, int32_t base, DrawElementType index_type, std::byte *indices,
                            PrimitiveKind primitive_kind = PrimitiveKind::TRIANGLES);

} // namespace Terabithia

#include "graphics_wrappers.ipp"

#endif // TERABITHIA_GRAPHICS_WRAPPERS_H