#ifndef VIEWPORT_WINDOW_H
#define VIEWPORT_WINDOW_H

#include "imgui_window.h"

namespace Terabithia {

class ViewportWindow : public ImGuiWindow {
public:
  ViewportWindow();

  void OnImGui() override;

private:
};

} // namespace Terabithia

#endif // VIEWPORT_WINDOW_H