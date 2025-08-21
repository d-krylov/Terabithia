
#include "terabithia/common/terabithia.h"
#include <print>

using namespace Terabithia;

class MeshViewer : public Layer {
public:
  void OnImGui() override {
    ImGui::Begin("Hello");
    ImGui::End();
  }

  void OnUpdate() override {

  }

  void OnEvent(Event &event) override {
  }

  void OnAttach() override {
  }

private:
};

int main() {

  Terabithia::Application application;

  MeshViewer mesh_viewer;

  application.AddLayer(&mesh_viewer);

  application.Run();

  return 0;
}