#ifndef ASSERTS_H
#define ASSERTS_H

//#include <source_location>

#include <filesystem>
#include <iostream>
#include <signal.h>

namespace Terabithia {

#define DEBUGBREAK() raise(SIGTRAP)

#define ASSERT_FATAL(check, message)                                                \
  {                                                                                 \
    if (!(check)) {                                                                 \
      std::cerr << message << " in "                                                \
                << std::filesystem::path(__FILE__).filename().string() << ":"       \
                << __LINE__ << std::endl;                                           \
      DEBUGBREAK();                                                                 \
    }                                                                               \
  }

} // namespace Terabithia

#endif // ASSERTS_H