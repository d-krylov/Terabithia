#include "application.h"
#include <print>

namespace Terabithia {

Application *Application::application_instance_ = nullptr;

Application *Application::Get() {
  return application_instance_;
}

void MessageCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, GLchar const *message, void const *user_param) {
  std::println("{}", message);
}

Application::Application(uint32_t width, uint32_t height, std::string_view name)
  : main_window_(width, height, name), imgui_layer_(&main_window_), imgui_renderer_() {
  main_window_.SetEventHandler(BIND_FUNCTION(Application::OnEvent));
  AddLayer(&imgui_layer_);
  application_instance_ = this;
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

const Window &Application::GetWindow() const {
  return main_window_;
}

void Application::Run() {
  while (main_window_.ShouldClose() == false) {
    main_window_.PollEvents();

    for (auto layer : layers_) {
      layer->OnUpdate();
    }

    imgui_layer_.NewFrame();
    imgui_renderer_.Begin();

    for (auto layer : layers_) {
      layer->OnImGui();
    }

    imgui_renderer_.End();

    main_window_.Update();
  }
}

} // namespace Terabithia