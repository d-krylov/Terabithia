#ifndef TERABITHIA_PROGRAM_IPP
#define TERABITHIA_PROGRAM_IPP

#include "core/include/tools.h"
#include <fstream>
#include <iostream>

namespace Terabithia {

inline Program::Shader::Shader(const ShaderInformation &shader_infofrmation, bool binary) {
  shader_ = GL::CreateShader(shader_infofrmation.second);
  binary ? LoadBinary(shader_infofrmation.first) : LoadSource(shader_infofrmation.first);
}

inline void Program::Shader::LoadSource(const std::filesystem::path &path) {
  std::ifstream file(path.c_str());
  std::string source{std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>()};
  GL::ShaderSource(shader_, source.c_str());
  GL::CompileShader(shader_);
  std::cout << GL::GetShaderLog(shader_) << std::endl;
}

inline void Program::Shader::LoadBinary(const std::filesystem::path &path) {
  auto binary = ReadBinaryFile(path);
  GL::ShaderBinary(shader_, binary);
  GL::SpecializeShader(shader_);
}

inline Program::Program(const std::filesystem::path &vertex, const std::filesystem::path &fragment, bool binary) {
  AddShaders({{vertex, ShaderType::VERTEX}, {fragment, ShaderType::FRAGMENT}}, binary);
}

inline Program::Program(const std::filesystem::path &compute, bool binary) { AddShaders({{compute, ShaderType::COMPUTE}}, binary); }

inline void Program ::AddShaders(const std::initializer_list<ShaderInformation> &shaders, bool binary) {
  program_ = GL::CreateProgram();
  for (const auto &shader_information : shaders) {
    Shader shader(shader_information, binary);
    GL::AttachShader(program_, shader);
  }
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