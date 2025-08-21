#ifndef TERABITHIA_IMGUI_RENDERER_H
#define TERABITHIA_IMGUI_RENDERER_H

#include "terabithia/graphics/include/buffer.h"
#include "terabithia/graphics/include/program.h"
#include "terabithia/graphics/include/vertex_array.h"
#include "terabithia/graphics/include/texture.h"
#include <memory>

struct ImDrawList;

namespace Terabithia {

class ImGuiRenderer {
public:
  ImGuiRenderer();

  void Draw();

  void Begin();

  void End();

protected:
  void CreateFontsTexture();
  void SetRendererState();
  void RestoreRenderState();
  void SetBuffers(const ImDrawList *command_list);

private:
  VertexArray vertex_array_;
  Program graphics_program_;
  Buffer vertex_buffer_;
  Buffer index_buffer_;
  std::unique_ptr<Texture> font_texture_;
};

} // namespace Terabithia

#endif // TERABITHIA_IMGUI_RENDERER_H