#ifndef SHADER_LIBRARY_H
#define SHADER_LIBRARY_H

#include "graphics.h"

namespace Terabithia {

class ShaderLibrary {
public:
  ShaderLibrary();

  static ShaderLibrary &Get();

  GraphicsPipeline &GetCore() { return core_; }

private:
  GraphicsPipeline core_;

  static ShaderLibrary *shader_libry_instance_;
};

} // namespace Terabithia

#endif // SHADER_LIBRARY_H