#include "application.h"

namespace Terabithia {

Application *Application::instance_ = nullptr;

Application::Application()
    : main_window_("Terabithia", 1920, 1080), imgui_platform_(main_window_) {
  instance_ = this;
}

Application::~Application() {}

void Application::Run() {

  while (main_window_.ShouldClose() == false) {
    main_window_.PollEvents();

    imgui_platform_.Begin();

    editor_.OnImGui();

    imgui_platform_.End();

    main_window_.Update();
  }
}

} // namespace Terabithia