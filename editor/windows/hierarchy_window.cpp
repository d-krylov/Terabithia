#include "hierarchy_window.h"
#include "application.h"
#include "components.h"
#include "easyloggingpp/easylogging++.h"
#include "editor_helpers.h"
#include "entity.h"
#include "gui.h"
#include "icons.h"
#include <iostream>

namespace Terabithia {

HierarchyWindow::HierarchyWindow(ImGuiWindowManager &imgui_window_manager)
  : ImGuiWindow(imgui_window_manager, "Hierarchy") {}

void HierarchyWindow::AddEntity() {

  auto &scene = Application::Get().GetScene();

  if (ImGui::Selectable("Add Empty Entity")) {
    scene.CreateEntity("Empty entity");
  }

  if (ImGui::Selectable("Camera")) {
    auto camera = scene.CreateEntity("Camera");
    camera.AddComponent<Transform>();
  }

  if (ImGui::Selectable("Light")) {
    auto light = scene.CreateEntity("Light");
    light.AddComponent<Light>();
  }

  if (ImGui::Selectable("Mesh")) {
    IGFD::FileDialogConfig config;
    config.path = ".";
    ImGuiFileDialog::Instance()->OpenDialog("Model", "Select Model", ".obj", config);
  }

  if (ImGui::Selectable("Lua Script")) {
    auto script = scene.CreateEntity("LuaScript");
  }

  if (ImGui::BeginMenu("Primitive")) {

    if (ImGui::MenuItem("Plane")) {
      auto primitive = scene.CreateEntity("Plane");
      primitive.AddComponent<Model>(PrimitiveMeshType::PLANE);
      primitive.AddComponent<Transform>();
    }

    if (ImGui::MenuItem("Box")) {
      auto primitive = scene.CreateEntity("Box");
      primitive.AddComponent<Model>(PrimitiveMeshType::BOX);
      primitive.AddComponent<Transform>();
    }

    if (ImGui::MenuItem("Sphere")) {
      auto primitive = scene.CreateEntity("Sphere");
      primitive.AddComponent<Model>(PrimitiveMeshType::SPHERE);
      primitive.AddComponent<Transform>();
    }

    if (ImGui::MenuItem("Cylinder")) {
      auto primitive = scene.CreateEntity("Cylinder");
      primitive.AddComponent<Model>(PrimitiveMeshType::CYLINDER);
      primitive.AddComponent<Transform>();
    }

    if (ImGui::MenuItem("Cone")) {
      auto primitive = scene.CreateEntity("Cone");
      primitive.AddComponent<Model>(PrimitiveMeshType::CONE);
      primitive.AddComponent<Transform>();
    }

    if (ImGui::MenuItem("Torus")) {
      auto primitive = scene.CreateEntity("Torus");
      primitive.AddComponent<Model>(PrimitiveMeshType::TORUS);
      primitive.AddComponent<Transform>();
    }

    if (ImGui::MenuItem("Capsule")) {
      auto primitive = scene.CreateEntity("Capsule");
      primitive.AddComponent<Model>(PrimitiveMeshType::CAPSULE);
      primitive.AddComponent<Transform>();
    }

    if (ImGui::MenuItem("Terrain")) {
      auto primitive = scene.CreateEntity("Terrain");
      primitive.AddComponent<Model>(PrimitiveMeshType::TERRAIN);
      primitive.AddComponent<Transform>();
    }

    ImGui::EndMenu();
  }
}

void HierarchyWindow::DrawEntityTree() {
  auto &registry = Application::Get().GetScene().GetRegistry();

  auto &selection_manager = Application::Get().GetEditor().GetSelectionManager();

  for (auto [entity] : registry.storage<entt::entity>().each()) {
    if (registry.valid(entity)) {

      bool selected = selection_manager.IsSelected(entity);

      const auto *name_component = registry.try_get<NameComponent>(entity);
      const auto *uuid_component = registry.try_get<IDComponent>(entity);

      ImGuiTreeNodeFlags node_flags = selected ? ImGuiTreeNodeFlags_Selected : 0;

      if (ImGui::TreeNodeEx(name_component->name_.c_str(), node_flags)) {
        ImGui::TreePop();
      }

      bool shift = ImGui::IsKeyDown(ImGuiKey_LeftShift);

      if (ImGui::IsItemClicked()) {
        if (shift == false) {
          selection_manager.ClearSelected();
        }
        if (selected == false) {
          selection_manager.Select(entity);
        } else {
          selection_manager.Deselect(entity);
        }
      }

      ImGui::SameLine();
      std::string id = std::to_string(uuid_component->id_);
      ImGui::Text(id.c_str());
    }
  }
}

void HierarchyWindow::OnImGui() {
  if (PrimaryButton(ICON_FA_PLUS, Vector2i(80.0f, 30.0f))) {
    ImGui::OpenPopup("AddEntity");
  }

  ImGui::Separator();

  if (ImGui::BeginPopup("AddEntity")) {
    AddEntity();
    ImGui::EndPopup();
  }

  DrawEntityTree();
}

} // namespace Terabithia