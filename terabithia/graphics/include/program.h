#ifndef TERABITHIA_PROGRAM_H
#define TERABITHIA_PROGRAM_H

#include "graphics_wrappers.h"
#include "mathematics/include/mathematical_types.h"
#include "core/include/tools.h"

namespace Terabithia {

class Program {
public:
  using ShaderInformation = std::pair<std::filesystem::path, ShaderType>;

  class Shader {
  public:
    Shader(const ShaderInformation &shader_infofrmation, bool binary);

    ~Shader() { GL::DeleteShader(shader_); }

    operator GL::DescriptorType() const { return shader_; }

  protected:
    void LoadSource(const std::filesystem::path &path);
    void LoadBinary(const std::filesystem::path &path);

  private:
    GL::DescriptorType shader_{0};
  };

  Program(const std::filesystem::path &compute, bool binary = false);
  Program(const std::filesystem::path &vertex, const std::filesystem::path &fragment, bool binary = false);

  ~Program() { GL::DeleteProgram(program_); }

  template <typename T> void SetUniform(std::string_view name, const T &value);

  void Use() { GL::UseProgram(program_); }

protected:
  void AddShaders(const std::initializer_list<ShaderInformation> &shaders, bool binary);

private:
  GL::DescriptorType program_{0};
};

} // namespace Terabithia

#include "program.ipp"

#endif // TERABITHIA_PROGRAM_H