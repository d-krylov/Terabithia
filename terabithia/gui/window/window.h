#ifndef TERABITHIA_WINDOW_H
#define TERABITHIA_WINDOW_H

#include <cstdint>
#include <string_view>
#include <functional>
#include "terabithia/core/include/core.h"

struct GLFWwindow;

namespace Terabithia {

class Event;

class Window {
public:
  using EventHandler = std::function<void(Event &)>;

  Window(int32_t width, int32_t height, std::string_view name = "Terabithia");

  GLFWwindow *GetNativeWindow() const;

  void PollEvents();

  void Update();

  bool ShouldClose() const;

  Extent2D GetFramebufferSize() const;

  Extent2D GetSize() const;

  int32_t GetWidth() const;

  int32_t GetHeight() const;

  int32_t GetKey(int32_t key) const;

  float GetAspect() const;

  void Invoke(Event &event);

  void SetEventHandler(const EventHandler &handler);

private:
  GLFWwindow *native_window_{nullptr};
  EventHandler event_handler_;
};

} // namespace Terabithia

#endif // TERABITHIA_WINDOW_H