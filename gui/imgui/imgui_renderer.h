#ifndef IMGUI_RENDERER_H
#define IMGUI_RENDERER_H

#include "graphics.h"

struct ImDrawData;

namespace Terabithia {

class ImGuiRenderer {
public:
  ImGuiRenderer();

  ~ImGuiRenderer();

  void Begin();
  void End();

  void RenderDrawData(ImDrawData *draw_data);

protected:
  void SetupRenderState(ImDrawData *draw_data, int32_t framebuffer_w, int32_t framebuffer_h);
  void CreateFontsTexture();

private:
  VertexArray vertex_array_;
  VertexBuffer vertex_buffer_;
  Buffer index_buffer_;
  GraphicsPipeline graphics_pipeline_;
  std::unique_ptr<Texture> font_texture_;
};

} // namespace Terabithia

#endif // IMGUI_RENDERER_H