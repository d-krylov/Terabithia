#include "application/include/application.h"
#include "imgui.h"
#include <iostream>

class MyApp : public Terabithia::Layer {
public:
  void OnImGui() override {
    ImGui::SetWindowSize(ImVec2{200.0f, 200.0f});
    ImGui::Begin("Hello");
    ImGui::End();
  }

  void OnUpdate() override { Terabithia::GL::Clear(); }

  void OnAttach() override {}
};

int main() {
  Terabithia::Application app;
  MyApp my_app;

  app.AddLayer(&my_app);
  app.Run();

  return 0;
}