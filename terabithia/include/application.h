#ifndef APPLICATION_H
#define APPLICATION_H

#include "editor.h"
#include "imgui_platform.h"
#include "scene_manager.h"

namespace Terabithia {

class Application {
public:
  Application();
  ~Application();

  [[nodiscard]] SceneManager &GetSceneManager() { return scene_manager_; }
  [[nodiscard]] const SceneManager &GetSceneManager() const {
    return scene_manager_;
  }

  [[nodiscard]] ImGuiPlatform &GetPlatform() { return imgui_platform_; }

  void Run();

  static Application &Get() { return *instance_; }

private:
  Window main_window_;
  ImGuiPlatform imgui_platform_;
  SceneManager scene_manager_;
  Editor editor_;

  static Application *instance_;
};

} // namespace Terabithia

#endif // APPLICATION_H