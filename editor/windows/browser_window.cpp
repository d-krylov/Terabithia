#include "browser_window.h"

namespace Terabithia {

BrowserWindow::BrowserWindow(ImGuiWindowManager &imgui_window_manager)
  : ImGuiWindow(imgui_window_manager, "Browser") {}

void BrowserWindow::OnImGui() {}

} // namespace Terabithia