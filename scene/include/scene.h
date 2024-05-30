#ifndef SCENE_H
#define SCENE_H

#include "UUID.h"
#include "entt/entt.hpp"
#include "macros.h"

namespace Terabithia {

class Entity;

class Scene {
public:
  Scene(std::string_view name = "Scene");

  void Initialize();

  NO_COPY_SEMANTIC(Scene);

  [[nodiscard]] entt::registry &GetRegistry() { return registry_; }

  Entity CreateEntity();
  Entity CreateEntity(std::string_view name);

  [[nodiscard]] Entity GetEntityByName(std::string_view name);
  [[nodiscard]] Entity GetEntityByUUID(UUID uuid);
  [[nodiscard]] Entity DuplicateEntity(Entity entity);
  [[nodiscard]] std::vector<Entity> GetAllEntities();

  template <typename... Components> auto GetEntitiesWithTypes() {
    return registry_.group<Components...>();
  }

  void DestroyEntity(Entity entity);

private:
  std::string name_;
  entt::registry registry_;
};

} // namespace Terabithia

#endif // SCENE_H