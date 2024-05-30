#ifndef HIERARCHY_WINDOW_H
#define HIERARCHY_WINDOW_H

#include "imgui_window.h"

namespace Terabithia {

class HierarchyWindow : public ImGuiWindow {
public:
  HierarchyWindow(ImGuiWindowManager &imgui_window_manager);

  void OnImGui() override;

protected:
  void AddEntity();
  void DrawEntityTree();

private:
};

} // namespace Terabithia

#endif // HIERARCHY_WINDOW_H