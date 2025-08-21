#ifndef TERABITHIA_CORE_H
#define TERABITHIA_CORE_H

#include <filesystem>
#include <source_location>
#include <string_view>
#include <cstdint>

namespace Terabithia {

void CORE_ASSERT(bool status, std::string_view message, std::source_location location = std::source_location::current());

std::filesystem::path GetTerabithiaRoot();
std::filesystem::path GetTerabithiaShaders();

struct Extent2D {
  int32_t width{0};
  int32_t height{0};
};

struct Extent3D {
  int32_t width{0};
  int32_t height{0};
  int32_t depth{0};
};

struct Offset2D {
  int32_t x{0};
  int32_t y{0};
};

struct Offset3D {
  int32_t x{0};
  int32_t y{0};
  int32_t z{0};
};

constexpr inline std::size_t operator""_KiB(unsigned long long int x) {
  return 1024ULL * x;
}

constexpr inline std::size_t operator""_MiB(unsigned long long int x) {
  return 1024_KiB * x;
}

} // namespace Terabithia

#endif // TERABITHIA_CORE_H