#ifndef BROWSER_WINDOW_H
#define BROWSER_WINDOW_H

#include "imgui_window.h"

namespace Terabithia {

class BrowserWindow : public ImGuiWindow {
public:
  BrowserWindow();

  void OnImGui() override;

private:
};

} // namespace Terabithia

#endif // BROWSER_WINDOW_H