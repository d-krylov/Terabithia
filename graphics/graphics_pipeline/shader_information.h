#ifndef SHADER_REFLECTION_H
#define SHADER_REFLECTION_H

#include "graphics_types.h"
#include "tools.h"

namespace Terabithia {

class ShaderInformation {
public:
  ShaderInformation(const std::filesystem::path &path);

private:
  ShaderKind kind_;
  std::string source_;
};

} // namespace Terabithia

#endif // SHADER_REFLECTION_H