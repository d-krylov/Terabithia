#include "application/include/application.h"
#include "gui/include/event.h"

namespace Terabithia {

Application::Application(std::string_view name, uint32_t width, uint32_t height)
  : window_(name, width, height), imgui_layer_(&window_), imgui_renderer_() {
  AddLayer(&imgui_layer_);
  window_.SetEventCallback(BIND_FUNCTION(Application::OnEvent));
}

void Application::AddLayer(Layer *layer) {
  auto new_layer = layers_.emplace_back(layer);
  new_layer->OnAttach();
}

void Application::OnEvent(Event &event) {
  for (auto &layer : layers_) {
    layer->OnEvent(event);
  }
}

void Application::Run() {

  while (window_.ShouldClose() == false) {
    window_.PollEvents();

    for (auto layer : layers_) {
      layer->OnUpdate();
    }

    imgui_layer_.NewFrame();
    imgui_renderer_.Begin();

    for (auto layer : layers_) {
      layer->OnImGui();
    }

    imgui_renderer_.End();
    window_.Update();
  }
}

} // namespace Terabithia