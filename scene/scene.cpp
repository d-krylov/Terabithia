#include "scene.h"
#include "components.h"
#include "entity.h"

namespace Terabithia {

Scene::Scene(std::string_view name) : name_(name) {}

Entity Scene::CreateEntity(std::string_view name) {
  Entity entity = {registry_.create(), this};
  entity.AddComponent<IDComponent>(UUID());
  auto &name_component = entity.AddComponent<NameComponent>();
  name_component.name_ = name;
  return entity;
}

std::vector<Entity> Scene::GetAllEntities() {
  std::vector<Entity> ret;
  auto view = registry_.view<NameComponent>();
  for (auto &e : view) {
    Entity new_entity(e, this);
    if (new_entity.IsValid()) {
      ret.push_back(new_entity);
    }
  }
  return ret;
}

} // namespace Terabithia