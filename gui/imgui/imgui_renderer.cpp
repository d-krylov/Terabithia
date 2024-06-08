#include "imgui_renderer.h"
#include "gui.h"
#include "tools.h"

namespace Terabithia {

VertexFormat GetImGuiVertexFormat() {
  return VertexFormat{DataType::VECTOR2, DataType::VECTOR2, {DataType::PACKED_RGBA, true}};
}

// clang-format off
BlendInformation GetBlendInformation() {
  return BlendInformation{
    BlendEquation::ADD, 
    BlendFunctionSeparate::SRC_ALPHA,
    BlendFunctionSeparate::ONE_MINUS_SRC_ALPHA, 
    BlendFunctionSeparate::ONE,
    BlendFunctionSeparate::ONE_MINUS_SRC_ALPHA};
}
// clang-format on

ImGuiRenderer::ImGuiRenderer()
  : vertex_array_(), vertex_buffer_(20_MiB, GetImGuiVertexFormat()),
    index_buffer_(BufferTarget::ELEMENT_ARRAY_BUFFER, 20_MiB),
    graphics_pipeline_{GetRoot() / "shaders/gui.vert", GetRoot() / "shaders/gui.frag"} {
  CreateFontsTexture();
  vertex_array_.AddVertexBuffer(vertex_buffer_);
  vertex_array_.SetIndexBuffer(index_buffer_);
}

ImGuiRenderer::~ImGuiRenderer() {}

void ImGuiRenderer::Begin() {
  ImGui::NewFrame();
  vertex_array_.Bind();
  graphics_pipeline_.Bind();
}

void ImGuiRenderer::End() {
  ImGuiIO &io = ImGui::GetIO();
  ImGui::Render();
  SetViewport(0, 0, int(io.DisplaySize.x), int(io.DisplaySize.y));
  RenderDrawData(ImGui::GetDrawData());
}

void ImGuiRenderer::SetBuffers(const ImDrawList *commands) {
  vertex_buffer_.Reset();
  index_buffer_.Reset();
  vertex_buffer_.PushData(std::span(commands->VtxBuffer.Data, commands->VtxBuffer.Size));
  index_buffer_.PushData(std::span(commands->IdxBuffer.Data, commands->IdxBuffer.Size));
}

void ImGuiRenderer::RenderDrawData(ImDrawData *draw_data) {
  int framebuffer_w = (int)(draw_data->DisplaySize.x * draw_data->FramebufferScale.x);
  int framebuffer_h = (int)(draw_data->DisplaySize.y * draw_data->FramebufferScale.y);
  if (framebuffer_w <= 0 || framebuffer_h <= 0) {
    return;
  }
  auto clip_offset = draw_data->DisplayPos;
  auto clip_scale = draw_data->FramebufferScale;

  SetupRenderState(draw_data, framebuffer_w, framebuffer_h);

  for (uint32_t n = 0; n < draw_data->CmdListsCount; n++) {
    const auto *commands = draw_data->CmdLists[n];
    SetBuffers(commands);
    for (uint32_t i = 0; i < commands->CmdBuffer.Size; i++) {
      const auto *command = &commands->CmdBuffer[i];
      if (command->UserCallback != nullptr) {
        if (command->UserCallback == ImDrawCallback_ResetRenderState) {
          SetupRenderState(draw_data, framebuffer_w, framebuffer_h);
        } else {
          command->UserCallback(commands, command);
        }
      } else {
        Vector2f clip_min((command->ClipRect.x - clip_offset.x) * clip_scale.x,
                          (command->ClipRect.y - clip_offset.y) * clip_scale.y);
        Vector2f clip_max((command->ClipRect.z - clip_offset.x) * clip_scale.x,
                          (command->ClipRect.w - clip_offset.y) * clip_scale.y);

        if (clip_max.x <= clip_min.x || clip_max.y <= clip_min.y) {
          continue;
        }

        Vector4i scissor{clip_min.x, float(framebuffer_h) - clip_max.y, clip_max - clip_min};

        SetScissor(true, scissor);

        glBindTextureUnit(0, (GLuint)(intptr_t)command->GetTexID());

        DrawElementsBaseVertex(command->ElemCount, command->IdxOffset * sizeof(ImDrawIdx),
                               command->VtxOffset, CoreType::UNSIGNED_SHORT);
      }
    }
  }

  SetScissor(false);
  SetBlending(false);
  SetDepthTesting(true);
}

void ImGuiRenderer::SetupRenderState(ImDrawData *draw_data, int32_t fbw, int32_t fbh) {
  SetBlending(true, GetBlendInformation());
  SetFaceCulling(false);
  SetDepthTesting(false);
  SetStencilTesting(false);
  SetPrimitiveRestart(false);
  SetPolygonMode();

  SetViewport(0, 0, fbw, fbh);

  float L = draw_data->DisplayPos.x;
  float R = draw_data->DisplayPos.x + draw_data->DisplaySize.x;
  float T = draw_data->DisplayPos.y;
  float B = draw_data->DisplayPos.y + draw_data->DisplaySize.y;

  if (GetClipOrigin() == GL_UPPER_LEFT) {
    std::swap(T, B);
  }

  auto orthographic = glm::ortho(L, R, B, T);
  graphics_pipeline_.SetUniform(ShaderIndex::VERTEX, "u_projection_matrix", orthographic);
  graphics_pipeline_.SetUniform(ShaderIndex::FRAGMENT, "u_texture", 0);
}

void ImGuiRenderer::CreateFontsTexture() {
  auto &io = ImGui::GetIO();
  uint8_t *pixels{nullptr};
  int32_t w, h;
  io.Fonts->GetTexDataAsRGBA32(&pixels, &w, &h);
  font_texture_ = std::make_unique<Texture>(w, h);
  glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
  auto *byte_pixels = ToBytePointer(pixels);
  std::span<const std::byte> span_pixels(byte_pixels, w * h * 4);
  font_texture_->SetData(span_pixels);
  io.Fonts->SetTexID((ImTextureID)(intptr_t)(*font_texture_));
}

} // namespace Terabithia