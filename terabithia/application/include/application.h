#ifndef TERABITHIA_APPLICATION_H
#define TERABITHIA_APPLICATION_H

#include "gui/imgui/imgui_layer.h"
#include "gui/imgui/imgui_renderer.h"
#include "gui/include/window.h"

namespace Terabithia {

class Application {
public:
  Application(std::string_view name = "Application", uint32_t width = 1920, uint32_t height = 1080);

  void Run();
  void OnEvent(Event &event);
  void AddLayer(Layer *layer);

private:
  Window window_;
  ImGuiLayer imgui_layer_;
  ImGuiRenderer imgui_renderer_;
  std::vector<Layer *> layers_;
};

} // namespace Terabithia

#endif // TERABITHIA_APPLICATION_H