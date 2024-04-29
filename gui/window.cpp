#include "window.h"
#include "glad/glad.h"
#include <GLFW/glfw3.h>

namespace Terabithia {

void GLFWInitialize() {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

Window::Window(std::string_view name, int32_t width, int32_t height) {
  GLFWInitialize();
  window_ = glfwCreateWindow(width, height, name.data(), nullptr, nullptr);
  glfwMakeContextCurrent(window_);
  auto status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
}

bool Window::ShouldClose() { return glfwWindowShouldClose(window_); }

void Window::PollEvents() { glfwPollEvents(); }

void Window::Update() { glfwSwapBuffers(window_); }

} // namespace Terabithia