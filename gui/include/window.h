#ifndef WINDOW_H
#define WINDOW_H

#include "core_types.h"
#include "window_event_handler.h"
#include <string_view>

struct GLFWwindow;
struct GLFWcursor;

namespace Terabithia {

enum MouseCursor {
  ARROW = 0,
  TEXT_INPUT = 1,
  RESIZE_ALL = 2,
  RESIZE_NS = 3,
  RESIZE_EW = 4,
  RESIZE_NESW = 5,
  RESIZE_NWSE = 6,
  HAND = 7,
  NOT_ALLOWED = 8,
  CROSSHAIR = 9
};

constexpr uint32_t GLFW_CURSOR_COUNT = MouseCursor::CROSSHAIR + 1;

class Window {
public:
  Window(std::string_view name, int32_t width, int32_t height);

  [[nodiscard]] bool ShouldClose();

  void PollEvents();
  void Update();
  void SetUserPointer();
  void Show();

  [[nodiscard]] GLFWwindow *GetNativeWindow() { return native_window_; }
  [[nodiscard]] const GLFWwindow *GetNativeWindow() const { return native_window_; }

  [[nodiscard]] uint32_t GetWidth() const;
  [[nodiscard]] uint32_t GetHeight() const;
  [[nodiscard]] Vector2u GetSize() const;
  [[nodiscard]] Vector2i GetPosition() const;
  [[nodiscard]] Vector2f GetCursorPosition() const;
  [[nodiscard]] Vector2u GetFramebufferSize() const;
  [[nodiscard]] float GetAspectRatio() const;
  [[nodiscard]] WindowEventHandler *GetEventHandler() const { return window_event_handler_; }

  [[nodiscard]] bool IsFocused() const;

  void SetCursorPosition(const Vector2d &position);
  void SetWindowEventHandler(WindowEventHandler *handler);
  void SetCursor(int32_t index);

protected:
  void SetCursors();
  void SetCallbacks();

private:
  GLFWwindow *native_window_{nullptr};
  GLFWcursor *mouse_cursors_[GLFW_CURSOR_COUNT];
  WindowEventHandler *window_event_handler_{nullptr};
};

} // namespace Terabithia

#endif // WINDOW_H