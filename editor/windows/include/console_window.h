#ifndef CONSOLE_WINDOW_H
#define CONSOLE_WINDOW_H

#include "imgui_window.h"

namespace Terabithia {

class ConsoleWindow : public ImGuiWindow {
public:
  ConsoleWindow();

  void OnImGui() override;

private:
};

} // namespace Terabithia

#endif // CONSOLE_WINDOW_H