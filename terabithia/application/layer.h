#ifndef TERABITHIA_LAYER_H
#define TERABITHIA_LAYER_H

#include "terabithia/gui/window/key_event.h"
#include "terabithia/gui/window/mouse_event.h"
#include "terabithia/gui/window/window_event.h"

namespace Terabithia {

class Layer {
public:
  virtual ~Layer() = default;

  virtual void OnImGui() {
  }

  virtual void OnUpdate() {
  }

  virtual void OnAttach() {
  }

  virtual void OnEvent(Event &event) {
  }
};

} // namespace Terabithia

#endif // TERABITHIA_LAYER_H