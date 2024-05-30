#ifndef ASSERTS_H
#define ASSERTS_H

//#include <source_location>

#include <filesystem>
#include <iostream>
#include <signal.h>

namespace Terabithia {

#define DEBUG_BREAK() raise(SIGTRAP)

#define CORE_ASSERT_FATAL(format, ...)                                                        \
  do {                                                                                        \
    printf("%s:%u " format "\n", __FILE__, __LINE__, ##__VA_ARGS__);                          \
    DEBUG_BREAK();                                                                            \
    abort();                                                                                  \
  } while (1)

#define CORE_VERIFY(expression)                                                               \
  do {                                                                                        \
    if (!(expression)) {                                                                      \
      CORE_ASSERT_FATAL("assert %s failed in %s", #expression, __func__);                     \
    }                                                                                         \
  } while (0)

#define CORE_UNREACHABLE() __builtin_unreachable()

} // namespace Terabithia

#endif // ASSERTS_H