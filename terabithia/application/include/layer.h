#ifndef TERABITHIA_LAYER_H
#define TERABITHIA_LAYER_H

namespace Terabithia {

class Event;

class Layer {
public:
  virtual ~Layer() = default;

  virtual void OnImGui() {}
  virtual void OnUpdate() {}
  virtual void OnAttach() {}
  virtual void OnEvent(Event &event) {}
};

} // namespace Terabithia

#endif // TERABITHIA_LAYER_H