#ifndef APPLICATION_H
#define APPLICATION_H

#include "editor.h"
#include "imgui_platform.h"
#include "imgui_renderer.h"
#include "scene.h"

namespace Terabithia {

class Application {
public:
  NO_COPY_SEMANTIC(Application);
  NO_MOVE_SEMANTIC(Application);

  Application();

  ~Application();

  [[nodiscard]] ImGuiPlatform &GetPlatform() { return imgui_platform_; }

  void Run();

  [[nodiscard]] static Application &Get();

  [[nodiscard]] Scene &GetScene() { return scene_; }
  [[nodiscard]] const Scene &GetScene() const { return scene_; }

  [[nodiscard]] Editor &GetEditor() { return editor_; }
  [[nodiscard]] const Editor &GetEditor() const { return editor_; }

private:
  Window main_window_;
  ImGuiPlatform imgui_platform_;
  ImGuiRenderer imgui_renderer_;
  Scene scene_;
  Editor editor_;

  static Application *instance_;
};

} // namespace Terabithia

#endif // APPLICATION_H