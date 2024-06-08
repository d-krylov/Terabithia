#include "editor.h"
#include "gui.h"

namespace Terabithia {

void Editor::DrawMainMenu() {

  if (ImGui::BeginMainMenuBar()) {

    if (ImGui::BeginMenu("File")) {

      if (ImGui::BeginMenu("New")) {
        if (ImGui::MenuItem("Scene")) {
          IGFD::FileDialogConfig config;
          config.path = ".";
          ImGuiFileDialog::Instance()->OpenDialog("Model", "Select Model", ".obj", config);
        }
        ImGui::EndMenu();
      }

      if (ImGui::MenuItem("Open project", "Ctrl+O")) {
      }

      ImGui::EndMenu();
    }

    if (ImGui::BeginMenu("Edit")) {
      ImGui::EndMenu();
    }

    if (ImGui::BeginMenu("Windows")) {

      if (ImGui::MenuItem("Save window settings")) {
        ImGui::SaveIniSettingsToDisk("windows.ini");
      }

      ImGui::EndMenu();
    }

    if (ImGui::BeginMenu("About")) {
      ImGui::EndMenu();
    }

    ImGui::EndMainMenuBar();
  }
}

} // namespace Terabithia