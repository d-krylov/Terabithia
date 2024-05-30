#ifndef VIEWPORT_WINDOW_H
#define VIEWPORT_WINDOW_H

#include "imgui_window.h"

namespace Terabithia {

class ViewportWindow : public ImGuiWindow {
public:
  ViewportWindow(ImGuiWindowManager &imgui_window_manager);

  void OnImGui() override;

private:
};

} // namespace Terabithia

#endif // VIEWPORT_WINDOW_H