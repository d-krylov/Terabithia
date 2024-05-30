#include "imgui_windows_manager.h"
#include "imgui_window.h"

namespace Terabithia {

void ImGuiWindowManager::Register(ImGuiWindow *window) { imgui_windows_.emplace_back(window); }

void ImGuiWindowManager::Unregister(ImGuiWindow *window) {}

void ImGuiWindowManager::OnImGui() {
  for (auto window : imgui_windows_) {
    if (window->IsVisible()) {
      window->Begin();
      window->OnImGui();
      window->End();
    }
  }
}

} // namespace Terabithia