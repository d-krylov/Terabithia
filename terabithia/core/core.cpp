#include "terabithia/core/include/core.h"
#include "config/config.h"
#include <print>

namespace Terabithia {

void CORE_ASSERT(bool status, std::string_view message, std::source_location location) {
  if (status == false) {
    std::println("ERROR: {0} in {1}:{2}", message, location.file_name(), location.line());
    std::abort();
  }
}

std::filesystem::path GetTerabithiaRoot() {
  return TERABITHIA_PROJECT_ROOT_DIR;
}

std::filesystem::path GetTerabithiaShaders() {
  return GetTerabithiaRoot() / "shaders";
}

} // namespace Terabithia