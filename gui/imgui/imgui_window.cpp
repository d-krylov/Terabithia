#include "imgui_window.h"
#include "gui.h"

namespace Terabithia {

ImGuiWindow::ImGuiWindow(std::string_view name) : name_(name) {}

void ImGuiWindow::SetVisibility(bool visible) { is_visible_ = visible; }

void ImGuiWindow::Begin() {
  bool is_visible = true;

  OnBegin();

  ImGuiStyle &style = ImGui::GetStyle();
  style.WindowRounding = 5.0f;

  bool not_collapsed = ImGui::Begin(name_.c_str(), &is_visible, GetFlags());

  if (is_visible == false) {
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