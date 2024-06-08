#ifndef SETTINGS_WINDOW_H
#define SETTINGS_WINDOW_H

#include "imgui_window.h"

namespace Terabithia {

class SettingsWindow : public ImGuiWindow {
public:
  SettingsWindow(ImGuiWindowManager &imgui_window_manager);

  void OnImGui() override;

private:
};

} // namespace Terabithia

#endif // SETTINGS_WINDOW_H