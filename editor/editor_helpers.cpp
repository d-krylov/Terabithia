#include "editor_helpers.h"
#include "gui.h"
#include "icons.h"

namespace Terabithia {

std::array<std::string_view, 3> axis_name = {"X", "Y", "Z"};
std::array<std::string_view, 3> axis_hidden_name = {"##X", "##Y", "##Z"};
std::array<uint32_t, 3> axis_color = {RED, GREEN, BLUE};

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

bool ColorButton(std::string_view name, uint32_t color) {
  ImGui::PushStyleColor(ImGuiCol_Button, color);
  ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 4.0f);
  const bool button_pressed = ImGui::Button(name.data());
  ImGui::PopStyleColor(1);
  ImGui::PopStyleVar(1);
  return button_pressed;
}

ImVec2 GetTextSize(std::string_view s) {
  auto &style = ImGui::GetStyle();
  auto text_size = ImGui::CalcTextSize(s.begin(), s.end());
  auto size = ImVec2(text_size.x + style.FramePadding.x * 2.0f,
                     text_size.y + style.FramePadding.y * 2.0f);
  return size;
}

void InputVector3(std::string_view item_name, Vector3f &value) {
  ImGui::PushID(item_name.data());
  float size = ImGui::GetContentRegionAvail().x - GetTextSize(item_name).x;
  auto button_size = GetTextSize("X");
  auto item_width = size / 3.0f - button_size.x - 2.0f * ImGui::GetStyle().ItemSpacing.x;
  ImGui::Text(item_name.data());
  for (uint32_t i = 0; i < 3; i++) {
    ImGui::SameLine();
    ImGui::PushItemWidth(item_width);
    ImGui::InputFloat(axis_hidden_name[i].data(), &value[i]);
    ImGui::PopItemWidth();
    ImGui::SameLine();
    if (ColorButton(axis_name[i].data(), axis_color[i])) {
      value[i] -= 1.0;
    }
  }
  ImGui::PopID();
}

void ShowCheckmark(bool f) {
  if (f) {
    ImGui::PushStyleColor(ImGuiCol_Text, GREEN);
    ImGui::Text(ICON_FA_CHECK);
    ImGui::PopStyleColor();
  } else {
    ImGui::PushStyleColor(ImGuiCol_Text, RED);
    ImGui::Text(ICON_FA_TIMES);
    ImGui::PopStyleColor();
  }
}

} // namespace Terabithia