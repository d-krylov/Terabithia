#ifndef TERABITHIA_PROGRAM_H
#define TERABITHIA_PROGRAM_H

#include "graphics_types.h"
#include "terabithia/mathematics/include/mathematics_types.h"
#include "terabithia/graphics/include/graphics_wrappers.h"
#include <filesystem>

namespace Terabithia {

class Program {
public:
  Program(std::string_view vertex_shader, std::string_view fragment_shader, std::string_view tessellation_control_shader = "",
          std::string_view tessellation_evaluation_shader = "", std::string_view geometry_shader = "");

  Program(std::string_view compute_shader);

  Program(const Program &) = delete;

  Program &operator=(const Program &) = delete;

  Program(Program &&other) noexcept;

  Program &operator=(Program &&other) noexcept;

  ~Program();

  void Use();

  std::vector<AttributeType> GetInputs() const;

  Handle GetHandle() const;

  static Program CreateFromFiles(const std::filesystem::path &compute_path);

  static Program CreateFromFiles(const std::filesystem::path &vertex_path, const std::filesystem::path &fragment_path,
                                 const std::filesystem::path &tessellation_control_path = "",
                                 const std::filesystem::path &tessellation_evaluation_path = "",
                                 const std::filesystem::path &geometry_path = "");

  template <typename T>
  void SetUniform(std::string_view name, const T &value, bool transpose = false);

protected:
  void Link();

  void AddShader(std::string_view shader_source, ShaderType shader_type);

  template <typename T>
  void SetUniform(std::string_view name, int32_t location, const T &value, bool transpose);

private:
  Descriptor program_{0};
};

} // namespace Terabithia

#include "program.ipp"

#endif // TERABITHIA_PROGRAM_H