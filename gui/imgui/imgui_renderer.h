#ifndef IMGUI_RENDERER_H
#define IMGUI_RENDERER_H

#include "core_types.h"

namespace Terabithia {

class ImGuiRenderer {
public:
  ImGuiRenderer();

  ~ImGuiRenderer();

  void Begin();
  void End();

  void RenderDrawData();

private:
  Handle vertex_array_{0};
  Handle vertex_buffer_{0};
  Handle index_buffer_{0};
  Handle font_texture_{0};
  Handle shader_pipeline_{0};
  Handle vertex_shader_{0};
  Handle fragment_shader_{0};
};

} // namespace Terabithia

#endif // IMGUI_RENDERER_H