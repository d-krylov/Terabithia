#ifndef COMMANDS_H
#define COMMANDS_H

#include "graphics_types.h"

namespace Terabithia {

struct BlendInformation {
  BlendEquation equation_;
  BlendFunctionSeparate source_rgb_;
  BlendFunctionSeparate destination_rgb_;
  BlendFunctionSeparate source_alpha_;
  BlendFunctionSeparate destination_alpha_;
};

struct StencilInformation {
  StencilFunction funtion_;
  StencilOption fail_;
  StencilOption zfail_;
  StencilOption zpass_;
  int32_t reference_;
  uint32_t mask_;
};

// clang-format off
void SetStencilTesting(bool b, const StencilInformation &stencil_information = {});
void SetBlending(bool b, const BlendInformation &blend_information = {});
void SetPolygonMode(PolygonMode polygon_mode = PolygonMode::FILL);
void SetPrimitiveRestart(bool b);
void DrawArrays(int32_t first, uint32_t count, PrimitiveKind kind = PrimitiveKind::TRIANGLES);
void DrawArraysInstanced(int32_t first, uint32_t count, uint32_t i_count, PrimitiveKind kind = PrimitiveKind::TRIANGLES);
void DrawArraysIndirect(uint32_t count, PrimitiveKind kind = PrimitiveKind::TRIANGLES, uint32_t stride = 0);
void DrawElements(uint32_t count, CoreType i_type = CoreType::UNSIGNED_INTEGER, PrimitiveKind kind = PrimitiveKind::TRIANGLES);
void DrawElementsBaseVertex(uint32_t count, uint64_t offset, int32_t base_vertex, 
                            CoreType index_type = CoreType::UNSIGNED_INTEGER, PrimitiveKind kind = PrimitiveKind::TRIANGLES);
                            
void Clear(ClearType clear_type = ClearType::COLOR);

uint32_t GetClipOrigin();

void SetFaceCulling(bool b);
void SetDepthTesting(bool b);
void SetViewport(int32_t x, int32_t y, uint32_t width, uint32_t height);
void SetScissor(bool b, const Vector4i &scissor = {});
// clang-format on

} // namespace Terabithia

#endif // COMMANDS_H