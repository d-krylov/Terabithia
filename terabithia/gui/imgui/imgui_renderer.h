#ifndef TERABITHIA_IMGUI_RENDERER_H
#define TERABITHIA_IMGUI_RENDERER_H

#include <memory>
#include "graphics/include/program.h"
#include "graphics/buffer/buffer.h"
#include "graphics/include/vertex_array.h"
#include "graphics/texture/texture.h"

struct ImDrawData;
struct ImDrawList;

namespace Terabithia {

class ImGuiRenderer {
public:
  ImGuiRenderer();

  void Begin();
  void End();

  void Render();

private:
  void SetBuffers(const ImDrawList *commands);
  void CreateFontsTexture();

private:
  Program graphics_program_;
  VertexArray vertex_array_;
  Buffer<BufferStorage::DYNAMIC_STORAGE> vertex_buffer_;
  Buffer<BufferStorage::DYNAMIC_STORAGE> index_buffer_;
  std::unique_ptr<Texture> font_texture_;
};

} // namespace Terabithia

#endif // TERABITHIA_IMGUI_RENDERER_H