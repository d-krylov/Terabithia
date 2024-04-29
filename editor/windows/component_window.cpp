#include "component_window.h"
#include "application.h"
#include "gui.h"

namespace Terabithia {

ComponentWindow::ComponentWindow() : ImGuiWindow("Components") {}

void ComponentWindow::DrawTransformComponent() {
  if (ImGui::CollapsingHeader("Transform")) {

    auto table_flags =
        ImGuiTableFlags_BordersInner | ImGuiTableFlags_SizingStretchProp;

    float x, y, z;

    if (ImGui::BeginTable("Transform table", 4, table_flags)) {

      if (ImGui::TableNextColumn()) {
        ImGui::PushFont(Application::Get().GetPlatform().GetPrimaryFont());
        ImGui::Text("Location");
        ImGui::Text("Rotation");
        ImGui::Text("Scale");
        ImGui::PopFont();
      }

      if (ImGui::TableNextColumn()) {
        ImGui::InputFloat("X##Location", &x);
        ImGui::InputFloat("X##Rotation", &x);
        ImGui::InputFloat("X##Scale", &x);
      }

      if (ImGui::TableNextColumn()) {
        ImGui::InputFloat("Y##Location", &y);
        ImGui::InputFloat("Y##Rotation", &y);
        ImGui::InputFloat("Y##Scale", &y);
      }

      if (ImGui::TableNextColumn()) {
        ImGui::InputFloat("Z##Location", &z);
        ImGui::InputFloat("Z##Rotation", &z);
        ImGui::InputFloat("Z##Scale", &z);
      }
      ImGui::EndTable();
    }
  }
}

void ComponentWindow::OnImGui() { DrawTransformComponent(); }

} // namespace Terabithia