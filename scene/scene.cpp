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



} // namespace Terabithia