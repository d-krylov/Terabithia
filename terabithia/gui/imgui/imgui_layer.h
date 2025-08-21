#ifndef TERABITHIA_IMGUI_LAYER_H
#define TERABITHIA_IMGUI_LAYER_H

#include "terabithia/application/layer.h"

namespace Terabithia {

class Window;

class ImGuiLayer : public Layer {
public:
  ImGuiLayer(Window *window);

  void OnEvent(Event &event) override;

  void NewFrame();

protected:
  bool OnKeyEvent(const KeyEvent &event);
  bool OnMouseButtonEvent(const MouseButtonEvent &event);
  bool OnMouseScrollEvent(const MouseScrollEvent &event);
  bool OnMouseMoveEvent(const MouseMoveEvent &event);
  bool OnCharEvent(const CharEvent &event);

private:
  Window *window_;
};

} // namespace Terabithia

#endif // TERABITHIA_IMGUI_LAYER_H