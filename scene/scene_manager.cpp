#include "scene_manager.h"

namespace Terabithia {

SceneManager::SceneManager() {}

void SceneManager::AddScene(std::string_view name) {
  scenes_.emplace_back(std::make_shared<Scene>(name));
}

Scene *SceneManager::GetCurrentScene() const {
  if (current_scene_index_.has_value()) {
    return scenes_[current_scene_index_.value()].get();
  }
  return nullptr;
}

} // namespace Terabithia