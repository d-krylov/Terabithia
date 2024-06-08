#include "settings_window.h"
#include "editor_helpers.h"
#include "graphics_types.h"
#include "gui.h"

namespace Terabithia {

SettingsWindow::SettingsWindow(ImGuiWindowManager &imgui_window_manager)
  : ImGuiWindow(imgui_window_manager, "Settings") {}

void SettingsWindow::OnImGui() {
  ImGui::Text("Bindless Texture");
  ImGui::SameLine();
  ShowCheckmark(GLAD_GL_ARB_bindless_texture);
}

} // namespace Terabithia