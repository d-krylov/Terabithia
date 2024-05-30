#include "editor.h"
#include "editor_windows.h"

namespace Terabithia {

// clang-format off
Editor::Editor():
  imgui_window_manager_(),
  selection_manager_(), 
  browser_window_(imgui_window_manager_),
  component_window_(imgui_window_manager_),
  console_window_(imgui_window_manager_),
  viewport_window_(imgui_window_manager_),
  hierarchy_window_(imgui_window_manager_) {}
// clang-format on

void Editor::OnImGui() {
  DrawMainMenu();
  imgui_window_manager_.OnImGui();
}

} // namespace Terabithia