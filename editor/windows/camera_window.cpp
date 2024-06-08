#include "camera_window.h"
#include "application.h"
#include "editor_helpers.h"
#include "gui.h"

namespace Terabithia {

CameraWindow::CameraWindow(ImGuiWindowManager &imgui_window_manager)
  : ImGuiWindow(imgui_window_manager, "Editor Camera") {}

void CameraWindow::OnImGui() {
  auto &camera = Application::Get().GetEditor().GetEditorCamera();

  auto position = camera.GetPosition();
  auto yaw = camera.GetYaw();

  InputVector3("Position", position);
  ImGui::SliderFloat("Yaw", &yaw, -PI_, PI_);

  camera.SetPosition(position);
  camera.SetYaw(yaw);
}

} // namespace Terabithia