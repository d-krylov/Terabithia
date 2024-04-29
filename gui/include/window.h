#ifndef WINDOW_H
#define WINDOW_H

#include <cstdint>
#include <string_view>

struct GLFWwindow;

namespace Terabithia {

class Window {
public:
  Window(std::string_view name, int32_t width, int32_t height);

  [[nodiscard]] bool ShouldClose();

  [[nodiscard]] uint32_t GetWidth() const { return width_; }
  [[nodiscard]] uint32_t GetHeight() const { return height_; }

  void PollEvents();
  void Update();

  [[nodiscard]] GLFWwindow *GetNativeWindow() { return window_; }
  [[nodiscard]] const GLFWwindow *GetNativeWindow() const { return window_; }

private:
  uint32_t width_{0};
  uint32_t height_{0};
  GLFWwindow *window_{nullptr};
};

} // namespace Terabithia

#endif // WINDOW_H