#ifndef TERABITHIA_TOOLS_H
#define TERABITHIA_TOOLS_H

#include <filesystem>
#include <string>
#include <vector>

namespace Terabithia {

std::vector<std::byte> ReadBinaryFile(const std::filesystem::path &path);

inline const std::filesystem::path TERABITHIA_ROOT = TERABITHIA_PROJECT_SOURCE_DIR;
inline const std::filesystem::path ASSETS_DIR = TERABITHIA_ROOT / "assets";
inline const std::filesystem::path SHADERS_SOURCE_DIR = TERABITHIA_ROOT / "shaders" / "sources";
inline const std::filesystem::path SHADERS_BINARY_DIR = TERABITHIA_ROOT / "shaders" / "spirv";

constexpr inline std::size_t operator""_KiB(unsigned long long int x) { return 1024ULL * x; }
constexpr inline std::size_t operator""_MiB(unsigned long long int x) { return 1024_KiB * x; }

} // namespace Terabithia

#endif // TERABITHIA_TOOLS_H
