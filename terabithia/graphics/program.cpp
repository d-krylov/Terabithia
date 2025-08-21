#include "terabithia/graphics/include/program.h"
#include "terabithia/core/include/core.h"
#include <fstream>

namespace Terabithia {

std::string ReadFile(const std::filesystem::path &path) {
  CORE_ASSERT(std::filesystem::exists(path), "No such path");
  std::ifstream file(path.c_str());
  std::string source = std::string(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());
  return source;
}

Program::Program(std::string_view vertex_shader, std::string_view fragment_shader) {
  program_ = CreateProgram();
  CORE_ASSERT(program_.IsValid(), "Invalid Program");
  AddShader(vertex_shader, ShaderType::VERTEX);
  AddShader(fragment_shader, ShaderType::FRAGMENT);
  LinkProgram(program_);
}

Program::~Program() {
  DeleteProgram(program_);
}

void Program::Use() {
  CORE_ASSERT(program_.IsValid(), "Invalid Program");
  UseProgram(program_);
}

void Program::AddShader(std::string_view shader_source, ShaderType shader_type) {
  Descriptor shader = CreateShader(shader_type);
  int32_t result = 0, length = 0;
  CORE_ASSERT(shader.IsValid(), "Invalid Shader");
  ShaderSource(shader, shader_source.data());
  CompileShader(shader);
  GetShaderParameter(shader, ShaderParameterName::COMPILE_STATUS, result);
  GetShaderParameter(shader, ShaderParameterName::INFO_LOG_LENGTH, length);
  auto error_information = GetShaderInfoLog(shader, length);
  CORE_ASSERT(result == true, std::format("Shader compilation error: {}", error_information));
  AttachShader(program_, shader);
  DeleteShader(shader);
}

Program Program::CreateFromFiles(const std::filesystem::path &vertex_path, const std::filesystem::path &fragment_path) {
  auto vertex = ReadFile(vertex_path);
  auto fragment = ReadFile(fragment_path);
  return Program(vertex, fragment);
}

Handle Program::GetHandle() const {
  return program_;
}

std::vector<AttributeType> Program::GetInputs() const {
}

} // namespace Terabithia