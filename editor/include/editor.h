#ifndef EDITOR_H
#define EDITOR_H

#include "editor_windows.h"
#include "macros.h"
#include "selection_manager.h"
#include <memory>
#include <vector>

namespace Terabithia {

class Editor {
public:
  Editor();

  NO_COPY_SEMANTIC(Editor);

  void OnImGui();

  [[nodiscard]] SelectionManager &GetSelectionManager() { return selection_manager_; }
  [[nodiscard]] const SelectionManager &GetSelectionManager() const {
    return selection_manager_;
  }

  [[nodiscard]] EditorCamera &GetEditorCamera() { return editor_camera_; }
  [[nodiscard]] const EditorCamera &GetEditorCamera() const { return editor_camera_; }

protected:
  void DrawMainMenu();

private:
  EditorCamera editor_camera_;
  ImGuiWindowManager imgui_window_manager_;
  SelectionManager selection_manager_;
  BrowserWindow browser_window_;
  ComponentWindow component_window_;
  ConsoleWindow console_window_;
  ViewportWindow viewport_window_;
  HierarchyWindow hierarchy_window_;
  CameraWindow camera_window_;
  SettingsWindow settings_window_;
};

} // namespace Terabithia

#endif // EDITOR_H