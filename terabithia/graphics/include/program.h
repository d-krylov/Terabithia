#ifndef TERABITHIA_PROGRAM_H
#define TERABITHIA_PROGRAM_H

#include "graphics_wrappers.h"
#include "mathematics/include/mathematical_types.h"
#include <filesystem>

namespace Terabithia {

class Program {
public:
  class Shader {
  public:
    Shader(const std::filesystem::path &path, ShaderType shader_type);

    ~Shader() { GL::DeleteShader(shader_); }

    operator GL::DescriptorType() const { return shader_; }

  private:
    GL::DescriptorType shader_;
  };

  Program(const std::filesystem::path &compute);

  Program(const std::filesystem::path &vertex, const std::filesystem::path &fragment);

  ~Program() { GL::DeleteProgram(program_); }

  template <typename T> void SetUniform(std::string_view name, const T &value);

  void Use() { GL::UseProgram(program_); }

private:
  GL::DescriptorType program_{0};
};

} // namespace Terabithia

#include "program.ipp"

#endif // TERABITHIA_PROGRAM_H