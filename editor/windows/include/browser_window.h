#ifndef BROWSER_WINDOW_H
#define BROWSER_WINDOW_H

#include "imgui_window.h"

namespace Terabithia {

class BrowserWindow : public ImGuiWindow {
public:
  BrowserWindow(ImGuiWindowManager &imgui_window_manager);

  void OnImGui() override;

private:
};

} // namespace Terabithia

#endif // BROWSER_WINDOW_H