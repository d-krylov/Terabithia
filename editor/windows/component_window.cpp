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
    if (ImGui::CollapsingHeader("Transform")) {
      InputVector3("Location", transform->GetPosition());
      InputVector3("Rotation", transform->GetRotation());
      InputVector3("Scale   ", transform->GetScale());
    }
  }

  auto *model = registry.try_get<Model>(selected_entities.front());

  if (model != nullptr) {
    if (ImGui::CollapsingHeader("Model")) {
      ImGui::Text(model->GetPath().c_str());
    }
  }

  auto *light = registry.try_get<Light>(selected_entities.front());

  if (light != nullptr) {
    if (ImGui::CollapsingHeader("Light")) {
      InputVector3("Color", light->GetColor());
    }
  }
}

} // namespace Terabithia