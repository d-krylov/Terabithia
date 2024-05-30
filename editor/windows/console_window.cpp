#include "console_window.h"

namespace Terabithia {

ConsoleWindow::ConsoleWindow(ImGuiWindowManager &imgui_window_manager)
  : ImGuiWindow(imgui_window_manager, "Console") {}

void ConsoleWindow::OnImGui() {}

} // namespace Terabithia