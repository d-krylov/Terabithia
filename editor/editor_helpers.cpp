#include "editor_helpers.h"
#include "gui.h"

namespace Terabithia {

bool PrimaryButton(const std::string &name, const Vector2i &size) {
  ImGui::PushStyleColor(ImGuiCol_Button, BASE_BUTTON_COLOR);
  ImGui::PushStyleColor(ImGuiCol_ButtonHovered, BASE_BUTTON_HOVERED);
  ImGui::PushStyleColor(ImGuiCol_ButtonActive, BASE_BUTTON_ACTIVE);
  ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 4.0f);
  const bool button_pressed = ImGui::Button(name.c_str(), ImVec2(size.x, size.y));
  ImGui::PopStyleColor(3);
  ImGui::PopStyleVar(1);
  return button_pressed;
}

bool VectorButton(const char *id) {
  ImGui::PushID(id);
  ImGui::PushStyleColor(ImGuiCol_Button, RED);
  ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 4.0f);
  const bool button_pressed = ImGui::Button("X");
  ImGui::PopStyleColor(1);
  ImGui::PopStyleVar(1);
  ImGui::PopID();
  return button_pressed;
}

} // namespace Terabithia