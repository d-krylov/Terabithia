#ifndef TERABITHIA_TIMER_H
#define TERABITHIA_TIMER_H

#include <chrono>

namespace Terabithia {

class Timer {
public:
  using TimePoint = std::chrono::time_point<std::chrono::high_resolution_clock>;

  Timer() : start_(Now()) {}

  static TimePoint Now() { return std::chrono::high_resolution_clock::now(); }

  template <typename T> T static Duration(TimePoint start, TimePoint end, T time_resolution) {
    auto duration = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
    return static_cast<T>(duration.count()) * time_resolution;
  }

  float GetElapsed(float time_resolution) const { return Duration(start_, Now(), time_resolution); }

private:
  TimePoint start_;
};

} // namespace Terabithia

#endif // TERABITHIA_TIMER_H