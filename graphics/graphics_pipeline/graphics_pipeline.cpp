#include "graphics_pipeline.h"
#include "easyloggingpp/easylogging++.h"
#include "tools.h"

namespace Terabithia {

bool GetShaderLinkStatus(Handle shader_handle) {
  int32_t compiled = 0;
  glGetProgramiv(shader_handle, GL_LINK_STATUS, &compiled);
  return compiled == GL_TRUE;
}

std::string GetShaderLog(Handle shader_handle) {
  int message_size = 0;
  glGetProgramiv(shader_handle, GL_INFO_LOG_LENGTH, &message_size);
  std::string message(message_size, ' ');
  glGetProgramInfoLog(shader_handle, message_size, nullptr, message.data());
  return message;
}

GraphicsPipeline::GraphicsPipeline() { glCreateProgramPipelines(1, &graphics_pipeline_); }

GraphicsPipeline::GraphicsPipeline(const std::initializer_list<std::filesystem::path> &paths)
  : GraphicsPipeline() {
  for (const auto &path : paths) {
    auto shader_bin = ReadFile(path);
    auto shader_index = GetShaderIndex(path);
    CORE_VERIFY(shader_index.has_value());
    AddShader(shader_index.value(), shader_bin);
  }
}

GraphicsPipeline::~GraphicsPipeline() { glDeleteProgramPipelines(1, &graphics_pipeline_); }

void GraphicsPipeline::AddShader(ShaderIndex index, const std::string &source) {
  auto source_cstr = source.c_str();
  auto kind = static_cast<uint16_t>(GetShaderKind(index));
  shaders_[index] = glCreateShaderProgramv(kind, 1, &source_cstr);
  bool status = GetShaderLinkStatus(shaders_[index]);
  if (status == false) {
    LOG(FATAL) << GetShaderLog(shaders_[index]);
  }
  UseStage(index);
}

void GraphicsPipeline::UseStage(ShaderIndex index) {
  auto stage = static_cast<uint32_t>(GetShaderBit(index));
  glUseProgramStages(graphics_pipeline_, stage, shaders_[index]);
}

void GraphicsPipeline::Bind() const {
  CORE_VERIFY(graphics_pipeline_ != 0);
  glBindProgramPipeline(graphics_pipeline_);
}

} // namespace Terabithia