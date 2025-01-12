#include "core/include/tools.h"
#include <fstream>

namespace Terabithia {

std::vector<std::byte> ReadBinaryFile(const std::filesystem::path &path) {
  auto size = std::filesystem::file_size(path);
  std::vector<std::byte> buffer(size);
  std::ifstream input_file(path.string(), std::ios_base::binary);
  input_file.read(reinterpret_cast<char *>(buffer.data()), size);
  return buffer;
}

} // namespace Terabithia