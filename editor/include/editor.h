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

protected:
  void DrawMainMenu();

private:
  ImGuiWindowManager imgui_window_manager_;
  SelectionManager selection_manager_;
  BrowserWindow browser_window_;
  ComponentWindow component_window_;
  ConsoleWindow console_window_;
  ViewportWindow viewport_window_;
  HierarchyWindow hierarchy_window_;
};

} // namespace Terabithia

#endif // EDITOR_H