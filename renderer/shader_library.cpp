#include "shader_library.h"
#include "tools.h"
// #define NDEBUG
#include <assert.h>

namespace Terabithia {

ShaderLibrary *ShaderLibrary::shader_libry_instance_ = nullptr;

ShaderLibrary &ShaderLibrary::Get() {
  assert(shader_libry_instance_ != nullptr);
  return *shader_libry_instance_;
}

ShaderLibrary::ShaderLibrary()
  : core_{GetRoot() / "shaders" / "mesh.vert", GetRoot() / "shaders" / "phong.frag"} {
  shader_libry_instance_ = this;
}

} // namespace Terabithia
