#ifndef TERABITHIA_EVENT_H
#define TERABITHIA_EVENT_H

#include "key.h"
#include <string_view>

namespace Terabithia {

#define BIND_FUNCTION(function) [this](auto &&...args) -> decltype(auto) { return this->function(std::forward<decltype(args)>(args)...); }

class Event {
public:
  virtual ~Event() = default;

  virtual EventKind GetEventKind() = 0;

public:
  bool handled{false};
};

class EventDispatcher {
public:
  EventDispatcher(Event &event) : event_(event) {
  }

  template <typename T, typename F>
  bool Dispatch(const F &function) {
    if (event_.GetEventKind() == T::event_kind) {
      event_.handled |= function(static_cast<T &>(event_));
      return true;
    }
    return false;
  }

private:
  Event &event_;
};

} // namespace Terabithia

#endif // TERABITHIA_EVENT_H