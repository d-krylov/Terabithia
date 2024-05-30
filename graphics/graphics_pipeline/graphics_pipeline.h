#ifndef SHADER_PIPELINE_H
#define SHADER_PIPELINE_H

#include "graphics_types.h"
#include "shader_uniform.h"
#include <array>
#include <filesystem>
#include <string>

namespace Terabithia {

class GraphicsPipeline {
public:
  GraphicsPipeline();
  GraphicsPipeline(const std::initializer_list<std::filesystem::path> &paths);

  ~GraphicsPipeline();

  operator Handle() const { return graphics_pipeline_; }

  template <typename T>
  void SetUniform(ShaderIndex index, std::string_view name, T value, bool transpose = false) {
    auto location = glGetUniformLocation(shaders_[index], name.data());
    SetUniformInternal(shaders_[index], location, value, transpose);
  }

  void AddShader(ShaderIndex index, const std::string &source);
  void UseStage(ShaderIndex index);

  void Bind() const;

private:
  Handle graphics_pipeline_{0};
  std::array<Handle, SHADER_STAGES_COUNT> shaders_;
};

} // namespace Terabithia

#endif // SHADER_PIPELINE_H