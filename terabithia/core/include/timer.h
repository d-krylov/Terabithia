#ifndef TERABITHIA_TIMER_H
#define TERABITHIA_TIMER_H

#include <chrono>

namespace Terabithia {

class Timer {
public:
  using TimePoint = std::chrono::time_point<std::chrono::high_resolution_clock>;

  Timer();

  void Reset();

  static TimePoint Now();

  static int64_t DurationNanoseconds(TimePoint start, TimePoint end);

  float ElapsedSeconds();

private:
  TimePoint start_;
};

} // namespace Terabithia

#endif // TERABITHIA_TIMER_H