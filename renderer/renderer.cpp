#include "renderer.h"
#include "components.h"
#include "entity.h"

namespace Terabithia {

Renderer::Renderer() {}

void Renderer::ProcessMesh(const Mesh &mesh) {
  if (mesh.HasIndices()) {
    DrawElementsIndirectCommand command{};
    {
      command.base_vertex_ = 0;
      command.base_instance_ = 0;
      command.first_index_ = 0;
      command.instance_count_ = 0;
      command.count_ = 0;
    }
  } else {

    DrawArraysIndirectCommand command{};
    {
      command.instance_count_ = 0;
      command.base_instance_ = 0;
      command.count_ = 0;
      command.first_vertex_ = 0;
    }
  }
}

void Renderer::Begin(Scene &scene) {
  auto entities = scene.GetAllEntities();
  for (auto &entity : entities) {
    if (entity.HasComponent<Model>()) {
      auto &model = entity.GetComponent<Model>();
      ProcessMesh(*model.GetMesh());
    }
  }
}

void Renderer::Draw() {}

void Renderer::End() {}

} // namespace Terabithia