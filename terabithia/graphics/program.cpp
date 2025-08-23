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

struct ShaderInformation {
  std::string_view source;
  ShaderType type;
};

void Program::Link() {
  int32_t result = 0, length = 0;
  LinkProgram(program_);
  GetProgramParameter(program_, ProgramParameterName::LINK_STATUS, result);
  GetProgramParameter(program_, ProgramParameterName::INFO_LOG_LENGTH, length);
  auto error_information = GetProgramInfoLog(program_, length);
  CORE_ASSERT(result == true, std::format("Program linking error: {}", error_information));
}

Program::Program(std::string_view vertex, std::string_view fragment, std::string_view tessellation_control,
                 std::string_view tessellation_evaluation, std::string_view geometry) {
  program_ = CreateProgram();

  CORE_ASSERT(program_.IsValid(), "Invalid Program");

  // clang-format off
  auto shaders = {
    ShaderInformation{vertex, ShaderType::VERTEX},
    ShaderInformation{tessellation_control, ShaderType::TESSELLATION_CONTROL},
    ShaderInformation{tessellation_evaluation, ShaderType::TESSELLATION_EVALUATION},
    ShaderInformation{geometry, ShaderType::GEOMETRY},
    ShaderInformation{fragment, ShaderType::FRAGMENT}
  };
  // clang-format on

  for (const auto &shader : shaders) {
    if (shader.source.empty() == false) {
      AddShader(shader.source, shader.type);
    }
  }

  Link();
}

Program::Program(std::string_view compute_shader) {
  program_ = CreateProgram();
  CORE_ASSERT(program_.IsValid(), "Invalid Program");
  AddShader(compute_shader, ShaderType::COMPUTE);
  Link();
}

Program::Program(Program &&other) noexcept {
  program_ = std::move(other.program_);
}

Program &Program::operator=(Program &&other) noexcept {
  program_ = std::move(other.program_);
  return *this;
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

auto Load = [](const std::filesystem::path &path) { return path.empty() ? std::string() : ReadFile(path); };

Program Program::CreateFromFiles(const std::filesystem::path &vertex, const std::filesystem::path &fragment,
                                 const std::filesystem::path &tessellation_control, const std::filesystem::path &tessellation_evaluation,
                                 const std::filesystem::path &geometry) {
  return Program(Load(vertex), Load(fragment), Load(tessellation_control), Load(tessellation_evaluation), Load(geometry));
}

Program Program::CreateFromFiles(const std::filesystem::path &compute_path) {
  return Program(ReadFile(compute_path));
}

Handle Program::GetHandle() const {
  return program_;
}

std::vector<AttributeType> Program::GetInputs() const {
}

} // namespace Terabithia