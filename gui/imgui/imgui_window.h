#ifndef IMGUI_WINDOW_H
#define IMGUI_WINDOW_H

#include "core_types.h"
#include <string>

namespace Terabithia {

class ImGuiWindow {
public:
  ImGuiWindow(std::string_view name);

  void Begin();
  void End();

  void SetVisibility(bool visible);

  void SetWindowName(std::string_view name);

  Vector2i GetMousePosition() const;

  bool IsVisible() const { return is_visible_; }

  virtual void OnBegin() {}
  virtual void OnEnd() {}
  virtual void OnImGui() = 0;

  virtual int32_t GetFlags();

private:
  std::string name_;
  bool is_visible_{false};
};

} // namespace Terabithia

#endif // IMGUI_WINDOW_H