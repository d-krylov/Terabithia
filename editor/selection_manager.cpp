#include "selection_manager.h"
#include "application.h"

namespace Terabithia {

bool SelectionManager::IsSelected(entt::entity entity) const {
  auto it = std::find(selected_entities_.begin(), selected_entities_.end(), entity);
  return (it != selected_entities_.end());
}

void SelectionManager::Select(entt::entity entity) {
  auto &registry = Application::Get().GetScene().GetRegistry();

  if (registry.valid(entity) == false) {
    return;
  }

  if (IsSelected(entity) == true) {
    return;
  }

  selected_entities_.push_back(entity);
}

void SelectionManager::Deselect(entt::entity entity) {
  const auto it = std::remove(selected_entities_.begin(), selected_entities_.end(), entity);
  if (it != selected_entities_.end()) {
    selected_entities_.erase(it, selected_entities_.end());
  }
}

void SelectionManager::ClearSelected() { selected_entities_.clear(); }

} // namespace Terabithia