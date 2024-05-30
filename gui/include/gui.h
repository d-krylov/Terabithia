#ifndef UI_H
#define UI_H

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "imgui_internal.h"
//#include "ImGuizmo.h"
#include "ImGuiFileDialog.h"

namespace Terabithia {

#define BASE_BUTTON_COLOR IM_COL32(100, 0, 255, 255)
#define BASE_BUTTON_HOVERED IM_COL32(100, 0, 255, 200)
#define BASE_BUTTON_ACTIVE IM_COL32(150, 0, 255, 255)

#define BASE_BUTTON_SIZE ImVec2(80.0, 30.0)

#define RED IM_COL32(255, 0, 0, 255)
#define GREEN IM_COL32(0, 255, 0, 255)
#define BLUE IM_COL32(0, 0, 255, 255)

} // namespace Terabithia

#endif // UI_H