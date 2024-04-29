#include "filesystem.h"

namespace Terabithia {

std::filesystem::path GetRoot() { return std::filesystem::path(PROJECT_SOURCE_DIR); }

} // namespace Terabithia