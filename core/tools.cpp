#include "tools.h"
#include <fstream>

namespace Terabithia {

std::filesystem::path GetRoot() { return std::filesystem::path(PROJECT_SOURCE_DIR); }

std::string ReadFile(const std::filesystem::path &path) {
  std::ifstream file(path.c_str());
  std::string data{std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>()};
  return data;
}

int32_t GetBinaryLogarithm(int32_t value) {
  int32_t ret{0};
  while (value > 1) {
    value >>= 1;
    ret++;
  }
  return ret;
}

} // namespace Terabithia