#include "imgui_renderer.h"
#include "imgui.h"

namespace Terabithia {

ImGuiRenderer::ImGuiRenderer()
  : vertex_array_(),
    graphics_program_(Program::CreateFromFiles(GetTerabithiaShaders() / "gui" / "gui.vert", GetTerabithiaShaders() / "gui" / "gui.frag")),
    vertex_buffer_(20_MiB, BufferStorageMaskBit::MAP_WRITE), index_buffer_(20_MiB, BufferStorageMaskBit::MAP_WRITE) {
  std::array vertex_attributes = {AttributeType::FLOAT_VEC2, AttributeType::FLOAT_VEC2, AttributeType::UNSIGNED_INT};
  vertex_array_.SetAttributes(vertex_attributes);
  auto stride = GetStride(vertex_attributes);
  VertexArrayVertexBuffer(vertex_array_.GetHandle(), vertex_buffer_.GetHandle(), 0, stride, 0);
  VertexArrayElementBuffer(vertex_array_.GetHandle(), index_buffer_.GetHandle());
  CreateFontsTexture();
}

void ImGuiRenderer::SetRendererState() {
  Enable(Capability::BLEND, Capability::SCISSOR_TEST);
  Disable(Capability::CULL_FACE, Capability::DEPTH_TEST, Capability::STENCIL_TEST);
  SetBlendEquation(BlendEquationMode::FUNC_ADD);
  SetBlendFunctionSeparate(BlendFunction::SRC_ALPHA, BlendFunction::ONE_MINUS_SRC_ALPHA, BlendFunction::ONE, BlendFunction::ONE_MINUS_SRC_ALPHA);
  graphics_program_.Use();
  vertex_array_.Bind();
}

void ImGuiRenderer::RestoreRenderState() {
  Disable(Capability::SCISSOR_TEST, Capability::BLEND);
}

void ImGuiRenderer::SetBuffers(const ImDrawList *command_list) {
  auto draw_data = ImGui::GetDrawData();
  vertex_buffer_.Map(MapBufferAccess::WRITE_ONLY);
  index_buffer_.Map(MapBufferAccess::WRITE_ONLY);
  auto vertices_mapped = vertex_buffer_.GetMappedBufferData<ImDrawVert>();
  auto indices_mapped = vertex_buffer_.GetMappedBufferData<ImDrawIdx>();
  std::span vertices(command_list->VtxBuffer.Data, command_list->VtxBuffer.Size);
  std::span indices(command_list->IdxBuffer.Data, command_list->IdxBuffer.Size);
  std::copy(vertices.begin(), vertices.end(), vertices_mapped.begin());
  std::copy(indices.begin(), indices.end(), indices_mapped.begin());
  vertex_buffer_.Unmap();
  index_buffer_.Unmap();
}

void ImGuiRenderer::Draw() {
  auto draw_data = ImGui::GetDrawData();

  auto framebuffer_w = static_cast<int32_t>(draw_data->DisplaySize.x * draw_data->FramebufferScale.x);
  auto framebuffer_h = static_cast<int32_t>(draw_data->DisplaySize.y * draw_data->FramebufferScale.y);

  if (framebuffer_w <= 0 || framebuffer_h <= 0) {
    return;
  }

  auto L = draw_data->DisplayPos.x;
  auto R = draw_data->DisplayPos.x + draw_data->DisplaySize.x;
  auto T = draw_data->DisplayPos.y;
  auto B = draw_data->DisplayPos.y + draw_data->DisplaySize.y;

  auto offset = draw_data->DisplayPos;
  auto scale = draw_data->FramebufferScale;

  auto orthographic = glm::ortho(L, R, B, T);

  Viewport(0, 0, framebuffer_w, framebuffer_h);

  graphics_program_.SetUniform("u_projection_matrix", orthographic);
  graphics_program_.SetUniform("u_texture", 0);

  for (const auto &command_list : draw_data->CmdLists) {

    SetBuffers(command_list);

    for (const auto &command : command_list->CmdBuffer) {

      Vector2f clip_min((command.ClipRect.x - offset.x) * scale.x, (command.ClipRect.y - offset.y) * scale.y);
      Vector2f clip_max((command.ClipRect.z - offset.x) * scale.x, (command.ClipRect.w - offset.y) * scale.y);

      if (clip_max.x <= clip_min.x || clip_max.y <= clip_min.y) {
        continue;
      }

      BindTextureUnit(command.GetTexID(), 0);

      Scissor(clip_min.x, framebuffer_h - clip_max.y, clip_max.x - clip_min.x, clip_max.y - clip_min.y);

      auto indices = reinterpret_cast<std::byte *>(command.IdxOffset * sizeof(ImDrawIdx));

      DrawElementsBaseVertex(command.ElemCount, command.VtxOffset, DrawElementType::UNSIGNED_SHORT, indices);
    }
  }
}

void ImGuiRenderer::Begin() {
  ImGui::NewFrame();
  SetRendererState();
}

void ImGuiRenderer::End() {
  ImGuiIO &io = ImGui::GetIO();
  ImGui::Render();
  Draw();
  RestoreRenderState();
}

void ImGuiRenderer::CreateFontsTexture() {
  auto &io = ImGui::GetIO();
  uint8_t *pixels{nullptr};
  int32_t width, height, channels;
  io.Fonts->GetTexDataAsRGBA32(&pixels, &width, &height, &channels);
  auto texture_data = std::span(pixels, width * height * channels);
  font_texture_ = std::make_unique<Texture>(TextureTarget::TEXTURE_2D, InternalFormat::RGBA8, TextureInformation(width, height));
  std::span<uint8_t> pixels_span(pixels, width * height * channels); 
  font_texture_->SetData(std::as_bytes(pixels_span));
  io.Fonts->SetTexID(font_texture_->GetHandle());
}

} // namespace Terabithia