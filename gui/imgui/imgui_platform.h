#ifndef IMGUI_PLATFORM_H
#define IMGUI_PLATFORM_H

#include "window.h"

struct ImFont;

namespace Terabithia {

class ImGuiPlatform : public WindowEventHandler {
public:
  ImGuiPlatform(Window &window);
  ~ImGuiPlatform();

  void SetFonts();

  ImFont *GetPrimaryFont() const { return primary_font_; }
  ImFont *GetIconFont() const { return icon_font_; }

  void Begin();
  void End();

  void NewFrame();

  void OnWindowFocus(int focused) override;
  void OnWindowSize(int, int) override;
  void OnWindowPos(int, int) override;
  void OnMouseButton(int button, int action, int m) override;
  void OnScroll(double xoffset, double yoffset) override;
  void OnKey(int keycode, int scancode, int action, int m) override;
  void OnCursorPos(double x, double y) override;
  void OnCursorEnter(int entered) override;
  void OnChar(unsigned int c) override;

protected:
  void UpdateMouseData();

private:
  ImFont *primary_font_{nullptr};
  ImFont *icon_font_{nullptr};
  Window &window_;
};

} // namespace Terabithia

#endif // IMGUI_PLATFORM_H