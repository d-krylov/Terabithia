#ifndef IMGUI_WINDOW_MANAGER_H
#define IMGUI_WINDOW_MANAGER_H

#include <vector>

namespace Terabithia {

class ImGuiWindow;

class ImGuiWindowManager {
public:
  void Register(ImGuiWindow *window);
  void Unregister(ImGuiWindow *window);

  void OnImGui();

private:
  std::vector<ImGuiWindow *> imgui_windows_;
};

} // namespace Terabithia

#endif // IMGUI_WINDOW_MANAGER_H