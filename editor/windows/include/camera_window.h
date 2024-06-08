#ifndef CAMERA_WINDOW_H
#define CAMERA_WINDOW_H

#include "editor_camera.h"
#include "imgui_window.h"

namespace Terabithia {

class CameraWindow : public ImGuiWindow {
public:
  CameraWindow(ImGuiWindowManager &imgui_window_manager);

  void OnImGui() override;

private:
};

} // namespace Terabithia

#endif // CAMERA_WINDOW_H