#ifndef TERABITHIA_WINDOW_H
#define TERABITHIA_WINDOW_H

#include <string_view>
#include <functional>

struct GLFWwindow;

namespace Terabithia {

struct Event;
enum class Action;
enum class Key;

class Window {
public:
  using vector2i = std::pair<int32_t, int32_t>;
  using EventCallback = std::function<void(Event &)>;

  Window(std::string_view name, int32_t width, int32_t height, int32_t samples = 0);

  float GetAspectRatio() const;
  vector2i GetSize() const;
  vector2i GetFramebufferSize() const;
  uint32_t GetWidth() const { return GetSize().first; }
  uint32_t GetHeight() const { return GetSize().second; };
  GLFWwindow *GetNativeWindow() const { return native_window_; }

  Action GetKey(Key key) const;

  bool ShouldClose() const;

  const EventCallback &GetEventCallback() const { return event_callback_; }

  void SetEventCallback(const EventCallback &callback) { event_callback_ = callback; }

  void PollEvents();
  void Update();

private:
  GLFWwindow *native_window_{nullptr};
  EventCallback event_callback_;
};

} // namespace Terabithia

#endif // TERABITHIA_WINDOW_H