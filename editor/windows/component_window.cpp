#include "component_window.h"
#include "application.h"
#include "components.h"
#include "editor_helpers.h"
#include "gui.h"

namespace Terabithia {

ComponentWindow::ComponentWindow(ImGuiWindowManager &imgui_window_manager)
  : ImGuiWindow(imgui_window_manager, "Components") {}

void ComponentWindow::DrawTransformComponent() {
  Vector3f data;
  if (ImGui::CollapsingHeader("Transform")) {
    ImGui::Text("Location");
    ImGui::SameLine();
    ImGui::InputFloat3("##Location", glm::value_ptr(data));
  }
}

void ComponentWindow::OnImGui() {

  auto &application = Application::Get();

  const auto &selected_entities =
    application.GetEditor().GetSelectionManager().GetSelectedEntities();

  if (selected_entities.size() != 1) {
    return;
  }

  auto &registry = application.GetScene().GetRegistry();

  auto *transform = registry.try_get<Transform>(selected_entities.front());

  if (transform != nullptr) {
  }
}

} // namespace Terabithia