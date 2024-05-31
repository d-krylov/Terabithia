#include "viewport_window.h"
#include "gui.h"

namespace Terabithia {

ViewportWindow::ViewportWindow(ImGuiWindowManager &imgui_window_manager)
  : ImGuiWindow(imgui_window_manager, "Viewport") {}

void ViewportWindow::DrawGuizmo() { ImGuizmo::BeginFrame(); }

void ViewportWindow::OnImGui() {}

} // namespace Terabithia