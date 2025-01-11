#include "core/include/tools.h"
#include "mathematics/include/mathematical_types.h"
#include "imgui_renderer.h"
#include "imgui.h"

namespace Terabithia {

ImGuiRenderer::ImGuiRenderer()
  : graphics_program_(SHADERS_SOURCE_DIR / "gui" / "gui.vert", SHADERS_SOURCE_DIR / "gui" / "gui.frag"), vertex_array_(),
    vertex_buffer_(BufferTarget::ARRAY, 4_MiB), index_buffer_(BufferTarget::ELEMENT_ARRAY, 4_MiB) {
  std::array<Format, 3> vertex_format{Format::R32G32_FLOAT, Format::R32G32_FLOAT, Format::R8G8B8A8_UNORM};
  auto stride = vertex_array_.SetVertexFormat(vertex_format);
  vertex_array_.SetVertexBuffer(vertex_buffer_, stride);
  vertex_array_.SetIndexBuffer(index_buffer_);
  CreateFontsTexture();
}

void ImGuiRenderer::SetBuffers(const ImDrawList *commands) {
  vertex_buffer_.SetData(std::span(commands->VtxBuffer.Data, commands->VtxBuffer.Size));
  index_buffer_.SetData(std::span(commands->IdxBuffer.Data, commands->IdxBuffer.Size));
}

void ImGuiRenderer::Render() {
  auto draw_data = ImGui::GetDrawData();

  int32_t framebuffer_w = (int32_t)(draw_data->DisplaySize.x * draw_data->FramebufferScale.x);
  int32_t framebuffer_h = (int32_t)(draw_data->DisplaySize.y * draw_data->FramebufferScale.y);

  if (framebuffer_w <= 0 || framebuffer_h <= 0) {
    return;
  }

  auto clip_offset = draw_data->DisplayPos;
  auto clip_scale = draw_data->FramebufferScale;

  GL::SetViewport(0, 0, framebuffer_w, framebuffer_h);

  float L = draw_data->DisplayPos.x;
  float R = draw_data->DisplayPos.x + draw_data->DisplaySize.x;
  float T = draw_data->DisplayPos.y;
  float B = draw_data->DisplayPos.y + draw_data->DisplaySize.y;

  auto orthographic = glm::ortho(L, R, B, T);

  graphics_program_.SetUniform("u_projection_matrix", orthographic);
  graphics_program_.SetUniform("u_texture", 0);

  for (uint32_t n = 0; n < draw_data->CmdListsCount; n++) {
    const auto *commands = draw_data->CmdLists[n];

    SetBuffers(commands);

    for (uint32_t i = 0; i < commands->CmdBuffer.Size; i++) {
      const auto *command = &commands->CmdBuffer[i];

      Vector2f clip_min((command->ClipRect.x - clip_offset.x) * clip_scale.x, (command->ClipRect.y - clip_offset.y) * clip_scale.y);
      Vector2f clip_max((command->ClipRect.z - clip_offset.x) * clip_scale.x, (command->ClipRect.w - clip_offset.y) * clip_scale.y);

      if (clip_max.x <= clip_min.x || clip_max.y <= clip_min.y) {
        continue;
      }

      Vector4f v(command->ClipRect.x, command->ClipRect.y, command->ClipRect.z, command->ClipRect.w);

      auto texture_id = uint32_t(command->GetTexID());

      GL::BindTextureUnit(texture_id, 0);

      auto offset = command->IdxOffset * sizeof(ImDrawIdx);

      GL::DrawElementsBaseVertex(command->ElemCount, offset, command->VtxOffset, IndexType::UNSIGNED_SHORT);
    }
  }
}

void ImGuiRenderer::Begin() {
  ImGui::NewFrame();
  GL::Enable(Capabilities::BLEND, Capabilities::SCISSOR_TEST);
  GL::Disable(Capabilities::CULL_FACE, Capabilities::DEPTH_TEST, Capabilities::STENCIL_TEST);
  GL::SetBlendEquation(BlendEquation::FUNC_ADD);
  GL::SetBlendFunction(BlendFactor::SRC_ALPHA, BlendFactor::ONE_MINUS_SRC_ALPHA, BlendFactor::ONE, BlendFactor::ONE_MINUS_SRC_ALPHA);
  vertex_array_.Bind();
  graphics_program_.Use();
}

void ImGuiRenderer::End() {
  ImGuiIO &io = ImGui::GetIO();
  ImGui::Render();
  Render();
  GL::Disable(Capabilities::SCISSOR_TEST, Capabilities::BLEND);
}

void ImGuiRenderer::CreateFontsTexture() {
  auto &io = ImGui::GetIO();
  uint8_t *pixels{nullptr};
  int32_t w, h, channels;
  io.Fonts->GetTexDataAsRGBA32(&pixels, &w, &h, &channels);
  auto data = std::span(pixels, w * h * channels);
  font_texture_ = std::make_unique<Texture>(w, h, InternalFormat::RGBA8, data);
  io.Fonts->SetTexID(*font_texture_);
}

} // namespace Terabithia