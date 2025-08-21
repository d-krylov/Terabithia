#include "terabithia/core/include/timer.h"

namespace Terabithia {

Timer::Timer() {
  Reset();
}

Timer::TimePoint Timer::Now() {
  return std::chrono::high_resolution_clock::now();
}

int64_t Timer::DurationNanoseconds(TimePoint start, TimePoint end) {
  return std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
}

float Timer::ElapsedSeconds() {
  auto duration = DurationNanoseconds(start_, Now());
  return duration * 0.001 * 0.001 * 0.001;
}

void Timer::Reset() {
  start_ = Now();
}

} // namespace Terabithia