#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <filesystem>

namespace Terabithia {

[[nodiscard]] std::filesystem::path GetRoot();

[[nodiscard]] std::string ReadFile(const std::filesystem::path &path);
[[nodiscard]] int32_t GetBinaryLogarithm(int32_t value);

template <typename T> [[nodiscard]] std::byte *ToBytePointer(T *data) {
  return reinterpret_cast<std::byte *>(data);
}

} // namespace Terabithia

#endif // FILESYSTEM_H