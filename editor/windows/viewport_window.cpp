#include "viewport_window.h"

namespace Terabithia {

ViewportWindow::ViewportWindow(ImGuiWindowManager &imgui_window_manager)
  : ImGuiWindow(imgui_window_manager, "Viewport") {}

void ViewportWindow::OnImGui() {}

} // namespace Terabithia