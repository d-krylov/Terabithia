#include "imgui_helpers.h"
#include "gui.h"

namespace Terabithia {

bool PrimaryButton(const std::string &name, const Vector2i &size) {
  ImGui::PushStyleColor(ImGuiCol_Button, BASE_BUTTON_COLOR);
  ImGui::PushStyleColor(ImGuiCol_ButtonHovered, BASE_BUTTON_HOVERED);
  ImGui::PushStyleColor(ImGuiCol_ButtonActive, BASE_BUTTON_ACTIVE);

  ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 4.0f);

  const bool buttonPressed = ImGui::Button(name.c_str(), ImVec2(size.x, size.y));

  ImGui::PopStyleColor(3);
  ImGui::PopStyleVar(1);

  return buttonPressed;
}

} // namespace Terabithia