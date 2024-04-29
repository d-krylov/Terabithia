#include "hierarchy_window.h"
#include "gui.h"
#include "icons.h"
#include "imgui_helpers.h"

namespace Terabithia {

HierarchyWindow::HierarchyWindow() : ImGuiWindow("Hierarchy") {}

void HierarchyWindow::AddEntity() {
  if (ImGui::Selectable("Add Empty Entity")) {
  }
  if (ImGui::Selectable("Camera")) {
  }
  if (ImGui::Selectable("Light")) {
  }
  if (ImGui::BeginMenu("Primitive")) {

    if (ImGui::MenuItem("Plane")) {
    }

    if (ImGui::MenuItem("Box")) {
    }

    if (ImGui::MenuItem("Sphere")) {
    }

    if (ImGui::MenuItem("Cylinder")) {
    }

    if (ImGui::MenuItem("Cone")) {
    }

    if (ImGui::MenuItem("Torus")) {
    }

    if (ImGui::MenuItem("Capsule")) {
    }

    if (ImGui::MenuItem("Terrain")) {
    }

    ImGui::EndMenu();
  }
}

void HierarchyWindow::DrawEntityTree() {}

void HierarchyWindow::OnImGui() {
  if (PrimaryButton(ICON_FA_PLUS, Vector2i(80.0f, 30.0f))) {
    ImGui::OpenPopup("AddEntity");
  }

  if (ImGui::BeginPopup("AddEntity")) {
    AddEntity();
    ImGui::EndPopup();
  }
}

} // namespace Terabithia