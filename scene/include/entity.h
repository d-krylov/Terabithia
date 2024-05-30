#ifndef ENTITY_H
#define ENTITY_H

#include "scene.h"

namespace Terabithia {

class Entity {
public:
  Entity() = default;

  Entity(entt::entity entity, Scene *scene) : entity_(entity), scene_(scene) {}

  template <typename T, typename... Args> T &AddComponent(Args &&...args) {
    return scene_->GetRegistry().emplace<T>(entity_, std::forward<Args>(args)...);
  }

  template <typename T> T &GetComponent() { return scene_->GetRegistry().get<T>(entity_); }

  template <typename T> const T &GetComponent() const {
    return scene_->GetRegistry().get<T>(entity_);
  }

  template <typename T> void RemoveComponent() { scene_->GetRegistry().remove<T>(entity_); }

  template <typename T> bool HasComponent() {
    return scene_->GetRegistry().all_of<T>(entity_);
  }

  operator entt::entity() const { return entity_; }
  operator bool() const { return entity_ != entt::null; }
  operator uint32_t() const { return (uint32_t)entity_; }

private:
  entt::entity entity_{entt::null};
  Scene *scene_{nullptr};
};

} // namespace Terabithia

#endif // ENTITY_H