#include "imgui_window.h"
#include "gui.h"

namespace Terabithia {

ImGuiWindow::ImGuiWindow(ImGuiWindowManager &imgui_window_manager, std::string_view name)
  : imgui_window_manager_(imgui_window_manager), name_(name) {
  imgui_window_manager_.Register(this);
}

void ImGuiWindow::SetVisibility(bool visible) { visible_ = visible; }

void ImGuiWindow::Begin() {
  bool is_visible = true;

  OnBegin();

  ImGuiStyle &style = ImGui::GetStyle();
  style.WindowRounding = 5.0f;

  bool not_collapsed = ImGui::Begin(name_.c_str(), &is_visible, GetFlags());

  if (visible_ == false) {
    SetVisibility(false);
  }
}

void ImGuiWindow::End() { ImGui::End(); }

ImGuiWindowFlags ImGuiWindow::GetFlags() { return 0; }

Vector2i ImGuiWindow::GetMousePosition() const {
  const auto &io = ImGui::GetIO();
  return Vector2i(io.MousePos.x, io.MousePos.y);
}

void ImGuiWindow::SetWindowName(std::string_view name) { name_ = name; }

} // namespace Terabithia