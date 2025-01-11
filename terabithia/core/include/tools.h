#ifndef TERABITHIA_TOOLS_H
#define TERABITHIA_TOOLS_H

#include <filesystem>
#include <fstream>
#include <string>

namespace Terabithia {

inline std::string ReadFile(const std::filesystem::path &path) {
  std::ifstream file(path.c_str());
  std::string ret{std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>()};
  return ret;
}

inline const std::filesystem::path TERABITHIA_ROOT = TERABITHIA_PROJECT_SOURCE_DIR;
inline const std::filesystem::path SHADERS_SOURCE_DIR = TERABITHIA_ROOT / "shaders" / "sources";

constexpr inline std::size_t operator""_KiB(unsigned long long int x) { return 1024ULL * x; }
constexpr inline std::size_t operator""_MiB(unsigned long long int x) { return 1024_KiB * x; }

} // namespace Terabithia

#endif // TERABITHIA_TOOLS_H
