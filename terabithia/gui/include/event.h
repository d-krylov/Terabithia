#ifndef TERABITHIA_EVENT_H
#define TERABITHIA_EVENT_H

#include "key.h"
#include <string_view>

namespace Terabithia {

enum class EventKind {
  NONE = 0,
  WINDOW_CLOSE,
  WINDOW_RESIZE,
  WINDOW_FOCUS,
  WINDOW_MOVE,
  KEY_EVENT,
  CHAR_EVENT,
  MOUSE_BUTTON_EVENT,
  MOUSE_MOVE,
  MOUSE_SCROLL
};

#define EVENT_CLASS_KIND(kind)                                                                                                             \
  static EventKind GetStaticKind() { return EventKind::kind; }                                                                             \
  EventKind GetEventKind() const override { return GetStaticKind(); }                                                                      \
  std::string_view GetName() const override { return #kind; }

#define BIND_FUNCTION(function) [this](auto &&...args) -> decltype(auto) { return this->function(std::forward<decltype(args)>(args)...); }

class Event {
public:
  virtual ~Event() = default;

  virtual EventKind GetEventKind() const = 0;
  virtual std::string_view GetName() const = 0;

public:
  bool handled_{false};
};

class EventDispatcher {
public:
  EventDispatcher(Event &event) : event_(event) {}

  template <typename T, typename F> bool Dispatch(const F &function) {
    if (event_.GetEventKind() == T::GetStaticKind()) {
      event_.handled_ |= function(static_cast<T &>(event_));
      return true;
    }
    return false;
  }

private:
  Event &event_;
};

class KeyEvent : public Event {
public:
  KeyEvent(Key key, int32_t scancode, Action action) : key_(key), scancode_(scancode), action_(action) {}

  Key GetKey() const { return key_; }
  int32_t GetScanCode() const { return scancode_; }
  Action GetAction() const { return action_; }

  EVENT_CLASS_KIND(KEY_EVENT);

private:
  Key key_;
  Action action_;
  int32_t scancode_;
};

class CharEvent : public Event {
public:
  CharEvent(uint32_t character) : character_(character) {}

  uint32_t GetCharacter() const { return character_; }

  EVENT_CLASS_KIND(CHAR_EVENT);

private:
  uint32_t character_;
};

class MouseMoveEvent : public Event {
public:
  float GetX() const { return x_; }
  float GetY() const { return y_; }

  EVENT_CLASS_KIND(MOUSE_MOVE);

  MouseMoveEvent(float x, float y) : x_(x), y_(y) {}

private:
  float x_;
  float y_;
};

class MouseScrollEvent : public Event {
public:
  MouseScrollEvent(float x, float y) : x_(x), y_(y) {}

  float GetX() const { return x_; }
  float GetY() const { return y_; }

  EVENT_CLASS_KIND(MOUSE_SCROLL);

private:
  float x_;
  float y_;
};

class MouseButtonEvent : public Event {
public:
  MouseButton GetMouseButton() const { return button_; }
  Action GetAction() const { return action_; }

  MouseButtonEvent(MouseButton button, Action action) : button_(button), action_(action) {}

  EVENT_CLASS_KIND(MOUSE_BUTTON_EVENT);

private:
  MouseButton button_;
  Action action_;
};

class WindowResizeEvent : public Event {
public:
  WindowResizeEvent(int32_t width, int32_t height) : width_(width), height_(height) {}

  int32_t GetWidth() const { return width_; }
  int32_t GetHeight() const { return height_; }

  EVENT_CLASS_KIND(WINDOW_RESIZE);

private:
  int32_t width_;
  int32_t height_;
};

} // namespace Terabithia

#endif // TERABITHIA_EVENT_H