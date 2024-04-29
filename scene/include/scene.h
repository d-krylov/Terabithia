#ifndef SCENE_H
#define SCENE_H

#include "UUID.h"
#include "entt/entt.hpp"

namespace Terabithia {

class Entity;

class Scene {
public:
  Scene(std::string_view name = "Scene");

  void Initialize();

  [[nodiscard]] entt::registry &GetRegistry() { return registry_; }

  [[nodiscard]] Entity CreateEntity();
  [[nodiscard]] Entity CreateEntity(std::string_view name);

  [[nodiscard]] Entity GetEntityByName(std::string_view name);
  [[nodiscard]] Entity GetEntityByUUID(UUID uuid);
  [[nodiscard]] Entity DuplicateEntity(Entity entity);

  template <typename... Components> auto GetEntitiesWithTypes() {
    return registry_.group<Components...>();
  }

  void DestroyEntity(Entity entity);
  [[nodiscard]] std::vector<Entity> GetAllEntities();

private:
  std::string name_;
  entt::registry registry_;
};

} // namespace Terabithia

#endif // SCENE_H