#ifndef COMPONENT_WINDOW_H
#define COMPONENT_WINDOW_H

#include "imgui_window.h"

namespace Terabithia {

class ComponentWindow : public ImGuiWindow {
public:
  ComponentWindow(ImGuiWindowManager &imgui_window_manager);

  void OnImGui() override;

protected:
  void DrawTransformComponent();

private:
};

} // namespace Terabithia

#endif // COMPONENT_WINDOW_H