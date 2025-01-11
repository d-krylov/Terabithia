#include "imgui_layer.h"
#include "imgui.h"
#include "gui/include/event.h"
#include "gui/include/window.h"
#include "core/include/macros.h"
#include <unordered_map>

namespace Terabithia {

ImGuiKey ToImGuiKey(Key key) {
  static std::unordered_map<Key, ImGuiKey> keys{
#define KEY(X, Y) {Key::K_##X, ImGuiKey::ImGuiKey_##Y},
#include "gui/include/key.def"
  };
  return keys[key];
}

// clang-format off
void UpdateKeyModifiers(const Window *window) {
  auto& io = ImGui::GetIO();
  io.AddKeyEvent(ImGuiMod_Ctrl,  (window->GetKey(Key::K_LEFT_CONTROL) == Action::PRESS) || (window->GetKey(Key::K_RIGHT_CONTROL) == Action::PRESS));
  io.AddKeyEvent(ImGuiMod_Shift, (window->GetKey(Key::K_LEFT_SHIFT) == Action::PRESS) || (window->GetKey(Key::K_RIGHT_SHIFT) == Action::PRESS));
  io.AddKeyEvent(ImGuiMod_Alt,   (window->GetKey(Key::K_LEFT_ALT) == Action::PRESS) || (window->GetKey(Key::K_RIGHT_ALT) == Action::PRESS));
  io.AddKeyEvent(ImGuiMod_Super, (window->GetKey(Key::K_LEFT_SUPER) == Action::PRESS) || (window->GetKey(Key::K_RIGHT_SUPER) == Action::PRESS));
}
// clang-format on

bool ImGuiLayer::OnCharEvent(const CharEvent &event) {
  auto &io = ImGui::GetIO();
  io.AddInputCharacter(event.GetCharacter());
  return true;
}

bool ImGuiLayer::OnMouseMoveEvent(const MouseMoveEvent &event) {
  auto &io = ImGui::GetIO();
  io.AddMousePosEvent(event.GetX(), event.GetY());
  return true;
}

bool ImGuiLayer::OnMouseScrollEvent(const MouseScrollEvent &event) {
  auto &io = ImGui::GetIO();
  io.AddMouseWheelEvent(event.GetX(), event.GetY());
  return true;
}

bool ImGuiLayer::OnMouseButtonEvent(const MouseButtonEvent &event) {
  auto &io = ImGui::GetIO();
  UpdateKeyModifiers(window_);
  io.AddMouseButtonEvent(int32_t(event.GetMouseButton()), event.GetAction() == Action::PRESS);
  return true;
}

bool ImGuiLayer::OnKeyEvent(const KeyEvent &event) {
  auto action = event.GetAction();
  if (action != Action::PRESS && action != Action::RELEASE) {
    return true;
  }
  auto &io = ImGui::GetIO();
  auto key = ToImGuiKey(event.GetKey());
  UpdateKeyModifiers(window_);
  io.AddKeyEvent(key, (action == Action::PRESS));
  io.SetKeyEventNativeData(key, uint32_t(event.GetKey()), event.GetScanCode());
  return true;
}

void ImGuiLayer::OnEvent(Event &event) {
  EventDispatcher dispatcher(event);
  dispatcher.Dispatch<MouseMoveEvent>(BIND_FUNCTION(ImGuiLayer::OnMouseMoveEvent));
  dispatcher.Dispatch<MouseButtonEvent>(BIND_FUNCTION(ImGuiLayer::OnMouseButtonEvent));
  dispatcher.Dispatch<MouseScrollEvent>(BIND_FUNCTION(ImGuiLayer::OnMouseScrollEvent));
  dispatcher.Dispatch<CharEvent>(BIND_FUNCTION(ImGuiLayer::OnCharEvent));
  dispatcher.Dispatch<KeyEvent>(BIND_FUNCTION(ImGuiLayer::OnKeyEvent));
}

ImGuiLayer::ImGuiLayer(Window *window) : window_(window) { ImGui::CreateContext(); }

void ImGuiLayer::NewFrame() {
  auto &io = ImGui::GetIO();

  auto wsize = window_->GetSize();
  auto fsize = window_->GetFramebufferSize();

  io.DisplaySize = ImVec2(wsize.first, wsize.second);

  if (wsize.first > 0 && wsize.first > 0) {
    io.DisplayFramebufferScale = ImVec2((float)fsize.first / wsize.first, (float)fsize.second / wsize.second);
  }
}

} // namespace Terabithia