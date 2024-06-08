#include "application.h"
// #define NDEBUG
#include <assert.h>

namespace Terabithia {

Application *Application::instance_ = nullptr;

Application &Application::Get() {
  assert(instance_ != nullptr);
  return *instance_;
}

// clang-format off
Application::Application()
  : main_window_("Terabithia", 1920, 1080), 
    imgui_platform_(main_window_),
    scene_(), 
    editor_(),
    shader_library_(),
    renderer_() {
  instance_ = this;
}
// clang-format on

Application::~Application() {}

void Application::Run() {

  EnableDebug();

  while (main_window_.ShouldClose() == false) {
    main_window_.PollEvents();

    Clear();

    imgui_platform_.NewFrame();
    imgui_renderer_.Begin();

    editor_.OnImGui();

    imgui_renderer_.End();

    main_window_.Update();
  }
}

} // namespace Terabithia