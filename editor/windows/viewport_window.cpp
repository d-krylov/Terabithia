#include "viewport_window.h"
#include "application.h"
#include "gui.h"
#include "image.h"
#include "tools.h"

namespace Terabithia {

ViewportWindow::ViewportWindow(ImGuiWindowManager &imgui_window_manager)
  : ImGuiWindow(imgui_window_manager, "Viewport") {}

void ViewportWindow::DrawGuizmo() {

  ImGuizmo::BeginFrame();
  ImGuizmo::SetOrthographic(false);
  ImGuizmo::SetDrawlist();

  auto region = ImGui::GetContentRegionAvail();
  auto pos = ImGui::GetWindowPos() + ImGui::GetCursorPos();

  ImGuizmo::SetRect(pos.x, pos.y, region.x, region.y);

  auto &camera = Application::Get().GetEditor().GetEditorCamera();

  auto eye = glm::value_ptr(camera.GetLookAtMatrix());
  auto projection = glm::value_ptr(camera.GetPerspectiveMatrix());

  Matrix4f model(1.0f);

  if (grid_) {
    ImGuizmo::DrawGrid(eye, projection, glm::value_ptr(model), 100.0f);
  }

  ImGuizmo::DrawCubes(eye, projection, glm::value_ptr(model), 1);
}

void ViewportWindow::OnImGui() {
  auto viewport_size = ImGui::GetContentRegionAvail();
  size_ = Vector2f(viewport_size.x, viewport_size.y);

  ImGui::Checkbox("Grid", &grid_);
  DrawGuizmo();
}

} // namespace Terabithia