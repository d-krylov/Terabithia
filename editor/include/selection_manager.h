#ifndef SELECTION_MANAGER_H
#define SELECTION_MANAGER_H

#include "entt/entt.hpp"
#include "macros.h"
#include <vector>

namespace Terabithia {

class SelectionManager {
public:
  SelectionManager() = default;

  [[nodiscard]] bool IsSelected(entt::entity entity) const;

  NO_COPY_SEMANTIC(SelectionManager);

  [[nodiscard]] const std::vector<entt::entity> &GetSelectedEntities() const {
    return selected_entities_;
  }

  void Select(entt::entity entity);
  void Deselect(entt::entity entity);

private:
  std::vector<entt::entity> selected_entities_;
};

} // namespace Terabithia

#endif // SELECTION_MANAGER_H