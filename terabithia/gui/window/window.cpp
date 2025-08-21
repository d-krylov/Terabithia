#include "window.h"
#include "key_event.h"
#include "mouse_event.h"
#include "window_event.h"
#include "glad/glad.h"
#include <GLFW/glfw3.h>

namespace Terabithia {

Window *GetWindow(GLFWwindow *native_window) {
  return reinterpret_cast<Window *>(glfwGetWindowUserPointer(native_window));
}

void KeyCallback(GLFWwindow *native_window, int32_t key, int32_t scan, int32_t action, int32_t m) {
  auto *window = GetWindow(native_window);
  auto event = KeyEvent(Key(key), scan, Action(action));
  window->Invoke(event);
}

void CharCallback(GLFWwindow *native_window, uint32_t character) {
  auto *window = GetWindow(native_window);
  auto event = CharEvent(character);
  window->Invoke(event);
}

void CursorPositionCallback(GLFWwindow *native_window, double x, double y) {
  auto *window = GetWindow(native_window);
  auto event = MouseMoveEvent((float)x, (float)y);
  window->Invoke(event);
}

void ScrollCallback(GLFWwindow *native_window, double x, double y) {
  auto *window = GetWindow(native_window);
  auto event = MouseScrollEvent((float)x, (float)y);
  window->Invoke(event);
}

void MouseButtonCallback(GLFWwindow *native_window, int32_t button, int32_t action, int32_t mods) {
  auto *window = GetWindow(native_window);
  auto event = MouseButtonEvent(MouseButton(button), Action(action));
  window->Invoke(event);
}

void WindowSizeCallback(GLFWwindow *native_window, int32_t width, int32_t height) {
  auto *window = GetWindow(native_window);
  auto event = WindowResizeEvent(width, height);
  window->Invoke(event);
}

void WindowCloseCallback(GLFWwindow *native_window) {
}

void WindowRefreshCallback(GLFWwindow *native_window) {
}

void CursorEnterCallback(GLFWwindow *native_window, int32_t entered) {
}

void WindowFocusCallback(GLFWwindow *native_window, int32_t focused) {
}

void MonitorCallback(GLFWmonitor *, int32_t) {
}

void WindowPosCallback(GLFWwindow *window, int32_t, int32_t) {
}

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

void InitializeGLFW() {
  auto status = glfwInit();
  CORE_ASSERT(status = GLFW_TRUE, "Can't initialize GLFW");
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

Window::Window(int32_t width, int32_t height, std::string_view name) {
  InitializeGLFW();
  native_window_ = glfwCreateWindow(width, height, name.data(), nullptr, nullptr);
  CORE_ASSERT(native_window_ != nullptr, "Can't create window");
  glfwMakeContextCurrent(native_window_);
  auto status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
  CORE_ASSERT(status == true, "Can't load GL functions");
  glfwSetWindowUserPointer(native_window_, this);
  SetCallbacks(GetNativeWindow());
}

GLFWwindow *Window::GetNativeWindow() const {
  return native_window_;
}

bool Window::ShouldClose() const {
  return glfwWindowShouldClose(native_window_);
}

void Window::PollEvents() {
  glfwPollEvents();
}

void Window::Update() {
  glfwSwapBuffers(native_window_);
}

Extent2D Window::GetFramebufferSize() const {
  Extent2D size;
  glfwGetFramebufferSize(native_window_, &size.width, &size.height);
  return size;
}

Extent2D Window::GetSize() const {
  Extent2D window_size;
  glfwGetWindowSize(native_window_, &window_size.width, &window_size.height);
  return window_size;
}

int32_t Window::GetWidth() const {
  auto size = GetSize();
  return size.width;
}

int32_t Window::GetHeight() const {
  auto size = GetSize();
  return size.height;
}

int32_t Window::GetKey(int32_t key) const {
  return glfwGetKey(native_window_, key);
}

void Window::Invoke(Event &event) {
  if (event_handler_) {
    event_handler_(event);
  }
}

void Window::SetEventHandler(const EventHandler &handler) {
  event_handler_ = handler;
}

} // namespace Terabithia