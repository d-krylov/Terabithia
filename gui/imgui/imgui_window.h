#ifndef IMGUI_WINDOW_H
#define IMGUI_WINDOW_H

#include "core_types.h"
#include "imgui_windows_manager.h"
#include <string>

namespace Terabithia {

class ImGuiWindow {
public:
  ImGuiWindow(ImGuiWindowManager &imgui_window_manager, std::string_view name);

  void Begin();
  void End();

  void SetVisibility(bool visible);

  void SetWindowName(std::string_view name);

  Vector2i GetMousePosition() const;

  bool IsVisible() const { return visible_; }

  virtual void OnBegin() {}
  virtual void OnEnd() {}
  virtual void OnImGui() = 0;

  virtual int32_t GetFlags();

private:
  ImGuiWindowManager &imgui_window_manager_;
  std::string name_;
  bool visible_{true};
};

} // namespace Terabithia

#endif // IMGUI_WINDOW_H