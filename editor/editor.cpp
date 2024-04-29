#include "editor.h"
#include "editor_windows.h"

namespace Terabithia {

Editor::Editor() {
  editor_windows_.emplace_back(std::make_shared<ConsoleWindow>());
  editor_windows_.emplace_back(std::make_shared<HierarchyWindow>());
  editor_windows_.emplace_back(std::make_shared<ComponentWindow>());
  editor_windows_.emplace_back(std::make_shared<BrowserWindow>());
  editor_windows_.emplace_back(std::make_shared<ViewportWindow>());
}

void Editor::OnImGui() {
  DrawMainMenu();

  for (auto &window : editor_windows_) {
    if (window->IsVisible()) {
      window->Begin();
      window->OnImGui();
      window->End();
    }
  }
}

} // namespace Terabithia