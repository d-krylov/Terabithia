#include "gui/include/window.h"
#include "glad/glad.h"
#include "gui/include/event.h"

namespace Terabithia {

Window *GetWindow(GLFWwindow *native_window) { return reinterpret_cast<Window *>(glfwGetWindowUserPointer(native_window)); }

void KeyCallback(GLFWwindow *native_window, int32_t key, int32_t scan, int32_t action, int32_t m) {
  auto *window = GetWindow(native_window);
  auto &handler = window->GetEventCallback();
  KeyEvent event(Key(key), scan, Action(action));
  handler(event);
}

void CharCallback(GLFWwindow *native_window, uint32_t character) {
  auto *window = GetWindow(native_window);
  auto &handler = window->GetEventCallback();
  CharEvent event(character);
  handler(event);
}

void CursorPositionCallback(GLFWwindow *native_window, double x, double y) {
  auto *window = GetWindow(native_window);
  auto &handler = window->GetEventCallback();
  MouseMoveEvent event((float)x, (float)y);
  handler(event);
}

void ScrollCallback(GLFWwindow *native_window, double x, double y) {
  auto *window = GetWindow(native_window);
  auto &handler = window->GetEventCallback();
  MouseScrollEvent event((float)x, (float)y);
  handler(event);
}

void MouseButtonCallback(GLFWwindow *native_window, int32_t button, int32_t action, int32_t mods) {
  auto *window = GetWindow(native_window);
  auto &handler = window->GetEventCallback();
  auto event = MouseButtonEvent(MouseButton(button), Action(action));
  handler(event);
}

void WindowSizeCallback(GLFWwindow *native_window, int32_t width, int32_t height) {
  auto *window = GetWindow(native_window);
  auto &handler = window->GetEventCallback();
  WindowResizeEvent event(width, height);
  handler(event);
}

void WindowCloseCallback(GLFWwindow *native_window) {}

void WindowRefreshCallback(GLFWwindow *native_window) {}

void CursorEnterCallback(GLFWwindow *native_window, int32_t entered) {}

void WindowFocusCallback(GLFWwindow *native_window, int32_t focused) {}

void MonitorCallback(GLFWmonitor *, int32_t) {}

void WindowPosCallback(GLFWwindow *window, int32_t, int32_t) {}

void SetCallbacks(GLFWwindow *window) {
  glfwSetWindowPosCallback(window, WindowPosCallback);
  glfwSetWindowFocusCallback(window, WindowFocusCallback);
  glfwSetKeyCallback(window, KeyCallback);
  glfwSetWindowSizeCallback(window, WindowSizeCallback);
  glfwSetWindowCloseCallback(window, WindowCloseCallback);
  glfwSetWindowRefreshCallback(window, WindowRefreshCallback);
  glfwSetCursorPosCallback(window, CursorPositionCallback);
  glfwSetCursorEnterCallback(window, CursorEnterCallback);
  glfwSetMouseButtonCallback(window, MouseButtonCallback);
  glfwSetScrollCallback(window, ScrollCallback);
  glfwSetCharCallback(window, CharCallback);
  glfwSetMonitorCallback(MonitorCallback);
}

void DefaultEventCallback(Event &) {}

Window::Window(std::string_view name, int32_t w, int32_t h, int32_t samples) {
  auto status = glfwInit();

  if (status != GLFW_TRUE) {
  }

  glfwWindowHint(GLFW_SAMPLES, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  native_window_ = glfwCreateWindow(w, h, name.data(), nullptr, nullptr);

  if (native_window_ == nullptr) {
  }

  glfwMakeContextCurrent(native_window_);

  status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

  if (status == false) {
  }

  glfwSetWindowUserPointer(native_window_, this);
  SetCallbacks(native_window_);
  SetEventCallback(DefaultEventCallback);
}

Window::vector2i Window::GetSize() const {
  vector2i size;
  glfwGetWindowSize(native_window_, &size.first, &size.second);
  return size;
}

Window::vector2i Window::GetFramebufferSize() const {
  vector2i size;
  glfwGetFramebufferSize(native_window_, &size.first, &size.second);
  return size;
}

float Window::GetAspectRatio() const {
  auto size = GetSize();
  return static_cast<float>(size.first) / static_cast<float>(size.second);
}

Action Window::GetKey(Key key) const { return Action(glfwGetKey(native_window_, int32_t(key))); }

bool Window::ShouldClose() const { return glfwWindowShouldClose(native_window_); }

void Window::PollEvents() { glfwPollEvents(); }

void Window::Update() { glfwSwapBuffers(native_window_); }

} // namespace Terabithia