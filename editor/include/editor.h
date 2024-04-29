#ifndef EDITOR_H
#define EDITOR_H

#include "imgui_window.h"
#include <memory>
#include <vector>

namespace Terabithia {

class Editor {
public:
  Editor();

  void OnImGui();

protected:
  void DrawMainMenu();

private:
  std::vector<std::shared_ptr<ImGuiWindow>> editor_windows_;
};

} // namespace Terabithia

#endif // EDITOR_H