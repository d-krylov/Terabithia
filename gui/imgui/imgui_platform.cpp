#include "imgui_platform.h"
#include "filesystem.h"
#include "gui.h"
#include "icons.h"
#include <GLFW/glfw3.h>

namespace Terabithia {

ImGuiPlatform::ImGuiPlatform(Window &window) {
  ImGui::CreateContext();
  ImGuiIO &io = ImGui::GetIO();
  io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
  io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

  SetFonts();

  ImGui_ImplGlfw_InitForOpenGL(window.GetNativeWindow(), true);
  ImGui_ImplOpenGL3_Init("#version 450");
}

ImGuiPlatform::~ImGuiPlatform() {}

void ImGuiPlatform::SetFonts() {
  ImGuiIO &io = ImGui::GetIO();
  io.Fonts->AddFontDefault();
  float base_size = 18.0f;
  float icon_size = base_size * 2.0f / 3.0f;

  static const ImWchar icon_ranges[] = {ICON_MIN_FA, ICON_MAX_16_FA, 0};
  ImFontConfig font_config;
  font_config.MergeMode = true;
  font_config.PixelSnapH = true;
  font_config.GlyphMinAdvanceX = icon_size;

  auto ifont = GetRoot() / "assets/fonts" / FONT_ICON_FILE_NAME_FAS;
  icon_font_ = io.Fonts->AddFontFromFileTTF(ifont.c_str(), icon_size, &font_config,
                                            icon_ranges);

  auto font = GetRoot() / "assets/fonts/OpenSans-Regular.ttf";

  primary_font_ = io.Fonts->AddFontFromFileTTF(font.c_str(), base_size);

  font = GetRoot() / "assets/fonts/OpenSans-SemiBold.ttf";

  primary_font_ = io.Fonts->AddFontFromFileTTF(font.c_str(), base_size);
}

void ImGuiPlatform::Begin() {
  ImGui_ImplOpenGL3_NewFrame();
  ImGui_ImplGlfw_NewFrame();
  ImGui::NewFrame();
}

void ImGuiPlatform::End() {
  ImGuiIO &io = ImGui::GetIO();
  ImGui::Render();

  glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
  glClear(GL_COLOR_BUFFER_BIT);

  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

  if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
    GLFWwindow *backup_current_context = glfwGetCurrentContext();
    ImGui::UpdatePlatformWindows();
    ImGui::RenderPlatformWindowsDefault();
    glfwMakeContextCurrent(backup_current_context);
  }
}

} // namespace Terabithia