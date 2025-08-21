#ifndef TERABITHIA_PROGRAM_IPP
#define TERABITHIA_PROGRAM_IPP

namespace Terabithia {

// clang-format off
template <typename T> inline void Program::SetUniform(std::string_view name, int32_t location, const T &value, bool transpose) {
  if constexpr (std::same_as<T, int32_t>)       ProgramUniform(program_, location, value);
  else if constexpr (std::same_as<T, uint32_t>) ProgramUniform(program_, location, value);
  else if constexpr (std::same_as<T, bool>)     ProgramUniform(program_, location, value);
  else if constexpr (std::same_as<T, float>)    ProgramUniform(program_, location, value);
  else if constexpr (std::same_as<T, double>)   ProgramUniform(program_, location, value);
  else if constexpr (std::same_as<T, Vector2f>) ProgramUniformV2(program_, location, std::span(glm::value_ptr(value), 2));
  else if constexpr (std::same_as<T, Vector3f>) ProgramUniformV3(program_, location, std::span(glm::value_ptr(value), 3));
  else if constexpr (std::same_as<T, Vector4f>) ProgramUniformV4(program_, location, std::span(glm::value_ptr(value), 4));
  else if constexpr (std::same_as<T, Vector2i>) ProgramUniformV2(program_, location, std::span(glm::value_ptr(value), 2));
  else if constexpr (std::same_as<T, Vector3i>) ProgramUniformV3(program_, location, std::span(glm::value_ptr(value), 3));
  else if constexpr (std::same_as<T, Vector4i>) ProgramUniformV4(program_, location, std::span(glm::value_ptr(value), 4));
  else if constexpr (std::same_as<T, Vector2u>) ProgramUniformV2(program_, location, std::span(glm::value_ptr(value), 2));
  else if constexpr (std::same_as<T, Vector3u>) ProgramUniformV3(program_, location, std::span(glm::value_ptr(value), 3));
  else if constexpr (std::same_as<T, Vector4u>) ProgramUniformV4(program_, location, std::span(glm::value_ptr(value), 4));
  else if constexpr (std::same_as<T, Matrix4f>) ProgramUniformM4(program_, location, std::span(glm::value_ptr(value), 16), transpose);
  else { std::unreachable(); }
}
// clang-format on

template <typename T>
inline void Program::SetUniform(std::string_view name, const T &value, bool transpose) {
  auto location = GetUniformLocation(program_, name);
  SetUniform(name, location, value, transpose);
}

} // namespace Terabithia

#endif // TERABITHIA_PROGRAM_IPP