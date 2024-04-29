#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <filesystem>

namespace Terabithia {

[[nodiscard]] std::filesystem::path GetRoot();

} // namespace Terabithia

#endif // FILESYSTEM_H