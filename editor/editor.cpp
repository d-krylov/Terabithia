#include "editor.h"
#include "application.h"
#include "components.h"
#include "editor_windows.h"
#include "entity.h"
#include "gui.h"

namespace Terabithia {

// clang-format off
Editor::Editor():
  editor_camera_(),
  imgui_window_manager_(),
  selection_manager_(), 
  browser_window_(imgui_window_manager_),
  component_window_(imgui_window_manager_),
  console_window_(imgui_window_manager_),
  viewport_window_(imgui_window_manager_),
  hierarchy_window_(imgui_window_manager_),
  camera_window_(imgui_window_manager_),
  settings_window_(imgui_window_manager_) {}
// clang-format on

void Editor::OnImGui() {
  DrawMainMenu();
  imgui_window_manager_.OnImGui();
  if (ImGuiFileDialog::Instance()->Display("Model")) {
    if (ImGuiFileDialog::Instance()->IsOk()) {
      auto &scene = Application::Get().GetScene();
      std::string file = ImGuiFileDialog::Instance()->GetFilePathName();
      std::string path = ImGuiFileDialog::Instance()->GetCurrentPath();
      auto entity = scene.CreateEntity("Model");
      auto &model = entity.AddComponent<Model>(file);
    }
    ImGuiFileDialog::Instance()->Close();
  }
}

} // namespace Terabithia