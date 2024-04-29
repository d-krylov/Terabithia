#ifndef IMGUI_PLATFORM_H
#define IMGUI_PLATFORM_H

#include "window.h"

struct ImFont;

namespace Terabithia {

class ImGuiPlatform {
public:
  ImGuiPlatform(Window &window);
  ~ImGuiPlatform();

  void SetFonts();

  ImFont *GetPrimaryFont() const { return primary_font_; }
  ImFont *GetIconFont() const { return icon_font_; }

  void Begin();
  void End();

private:
  ImFont *primary_font_{nullptr};
  ImFont *icon_font_{nullptr};
};

} // namespace Terabithia

#endif // IMGUI_PLATFORM_H