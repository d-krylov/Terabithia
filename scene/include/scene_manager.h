#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "asserts.h"
#include "scene.h"
#include <optional>

namespace Terabithia {

class SceneManager {
public:
  SceneManager();

  void AddScene(std::string_view name);

  [[nodiscard]] Scene *GetCurrentScene() const;

  [[nodiscard]] const std::vector<std::shared_ptr<Scene>> &GetScenes() const {
    return scenes_;
  }

private:
  std::optional<std::size_t> current_scene_index_;
  std::vector<std::shared_ptr<Scene>> scenes_;
};

} // namespace Terabithia

#endif // SCENE_MANAGER_H