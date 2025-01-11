#ifndef TERABITHIA_PROGRAM_IPP
#define TERABITHIA_PROGRAM_IPP

#include "core/include/tools.h"
#include <fstream>
#include <iostream>

namespace Terabithia {

inline Program::Shader::Shader(const std::filesystem::path &path, ShaderType shader_type) {
  shader_ = GL::CreateShader(shader_type);
  std::ifstream file(path.c_str());
  std::string source{std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>()};
  GL::ShaderSource(shader_, source.c_str());
  GL::CompileShader(shader_);
  std::cout << GL::GetShaderLog(shader_) << std::endl;
}

inline Program::Program(const std::filesystem::path &vertex, const std::filesystem::path &fragment) {
  program_ = GL::CreateProgram();
  Shader vertex_shader(vertex, ShaderType::VERTEX);
  Shader fragment_shader(fragment, ShaderType::FRAGMENT);
  GL::AttachShader(program_, vertex_shader);
  GL::AttachShader(program_, fragment_shader);
  GL::LinkProgram(program_);
}

inline Program::Program(const std::filesystem::path &compute) {
  program_ = GL::CreateProgram();
  Shader compute_shader(compute, ShaderType::COMPUTE);
  GL::AttachShader(program_, compute_shader);
  GL::LinkProgram(program_);
}

template <typename T> inline void Program::SetUniform(std::string_view name, const T &value) {
  auto location = GL::GetUniformLocation(program_, name);
  if constexpr (std::is_arithmetic_v<T> == true) {
    GL::SetUniform(location, value);
  } else {
    using R = typename T::value_type;
    constexpr int32_t N = sizeof(T) / sizeof(R);
    GL::SetUniform<R, N>(location, 1, CastToPointer(value));
  }
}

} // namespace Terabithia

#endif // TERABITHIA_PROGRAM_IPP