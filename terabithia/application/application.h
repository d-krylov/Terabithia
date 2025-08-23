#ifndef TERABITHIA_APPLICATION_H
#define TERABITHIA_APPLICATION_H

#include <string_view>
#include <cstdint>
#include "terabithia/gui/imgui/imgui_layer.h"
#include "terabithia/gui/imgui/imgui_renderer.h"
#include "terabithia/gui/window/window.h"

namespace Terabithia {

class Application {
public:
  Application(uint32_t width = 1920, uint32_t height = 1080, std::string_view name = "Application");

  void Run();

  static Application *Get();

  void AddLayer(Layer *layer);

  void OnEvent(Event &event);

  const Window &GetWindow() const;

private:
  Window main_window_;
  ImGuiLayer imgui_layer_;
  ImGuiRenderer imgui_renderer_;

  std::vector<Layer *> layers_;

  static Application *application_instance_;
};

} // namespace Terabithia

#endif // TERABITHIA_APPLICATION_H