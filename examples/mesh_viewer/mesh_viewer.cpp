
#include "terabithia/common/terabithia.h"
#include <print>

using namespace Terabithia;

class MeshViewer : public Layer {
public:
  void OnImGui() override {
    auto position = camera_.GetPosition();
    ImGui::Begin("Camera");
    ImGui::DragFloat3("Position", glm::value_ptr(position));
    ImGui::End();
    camera_.SetPosition(position);
  }

  void OnUpdate() override {
  }

  void OnEvent(Event &event) override {
  }

  void OnAttach() override {
  }

private:
  Camera camera_;
};

int main() {

  Terabithia::Application application;

  MeshViewer mesh_viewer;

  application.AddLayer(&mesh_viewer);

  application.Run();

  return 0;
}