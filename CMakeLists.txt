cmake_minimum_required(VERSION 3.25)

project(Terabithia)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

find_package(glfw3  REQUIRED)
find_package(OpenGL REQUIRED)
find_package(PkgConfig REQUIRED)

set(CMAKE_BUILD_TYPE Debug)

include(cmake/ClangFormat.cmake)
include(cmake/Libraries.cmake)

FetchContent_MakeAvailable(glm)

add_definitions(-DGLM_ENABLE_EXPERIMENTAL)

add_clang_format_target(format)

add_definitions(-DPROJECT_SOURCE_DIR="${PROJECT_SOURCE_DIR}")

set(IMGUI_BACKEND_SOURCES
  ${PROJECT_SOURCE_DIR}/external/imgui/backend/imgui_impl_glfw.cpp
  ${PROJECT_SOURCE_DIR}/external/imgui/backend/imgui_impl_opengl3.cpp
)

set(IMGUI_SOURCES
  ${PROJECT_SOURCE_DIR}/external/imgui/sources/imgui_draw.cpp
  ${PROJECT_SOURCE_DIR}/external/imgui/sources/imgui_tables.cpp
  ${PROJECT_SOURCE_DIR}/external/imgui/sources/imgui_widgets.cpp
  ${PROJECT_SOURCE_DIR}/external/imgui/sources/imgui.cpp
  ${IMGUI_BACKEND_SOURCES}
)

set(IMGUIZMO_SOURCES
  ${PROJECT_SOURCE_DIR}/third_party/imguizmo/sources/GraphEditor.cpp
  ${PROJECT_SOURCE_DIR}/third_party/imguizmo/sources/ImCurveEdit.cpp
  ${PROJECT_SOURCE_DIR}/third_party/imguizmo/sources/ImGradient.cpp
  ${PROJECT_SOURCE_DIR}/third_party/imguizmo/sources/ImGuizmo.cpp
  ${PROJECT_SOURCE_DIR}/third_party/imguizmo/sources/ImSequencer.cpp
)

set(CORE_SOURCES
  ${PROJECT_SOURCE_DIR}/core/UUID.cpp
  ${PROJECT_SOURCE_DIR}/core/tools.cpp
  ${PROJECT_SOURCE_DIR}/core/image.cpp
  #${PROJECT_SOURCE_DIR}/base/base_logger.cpp
)

set(GRAPHICS_SOURCES
  ${PROJECT_SOURCE_DIR}/graphics/debug.cpp
  ${PROJECT_SOURCE_DIR}/graphics/texture/sampler.cpp
  ${PROJECT_SOURCE_DIR}/graphics/buffer/buffer.cpp
  ${PROJECT_SOURCE_DIR}/graphics/texture/framebuffer.cpp
  ${PROJECT_SOURCE_DIR}/graphics/texture/renderbuffer.cpp
  ${PROJECT_SOURCE_DIR}/graphics/texture/texture.cpp
  ${PROJECT_SOURCE_DIR}/graphics/vertex/vertex_array.cpp
  ${PROJECT_SOURCE_DIR}/graphics/vertex/vertex_format.cpp
  ${PROJECT_SOURCE_DIR}/graphics/graphics_pipeline/graphics_pipeline.cpp
  ${PROJECT_SOURCE_DIR}/graphics/graphics_types.cpp
  ${PROJECT_SOURCE_DIR}/graphics/commands.cpp
  #${PROJECT_SOURCE_DIR}/platform/shader_information.cpp
)

set(EDITOR_SOURCES
  ${PROJECT_SOURCE_DIR}/editor/editor.cpp
  ${PROJECT_SOURCE_DIR}/editor/windows/viewport_window.cpp
  ${PROJECT_SOURCE_DIR}/editor/windows/component_window.cpp
  ${PROJECT_SOURCE_DIR}/editor/windows/hierarchy_window.cpp
  ${PROJECT_SOURCE_DIR}/editor/windows/main_menu.cpp
  ${PROJECT_SOURCE_DIR}/editor/windows/console_window.cpp
  ${PROJECT_SOURCE_DIR}/editor/windows/browser_window.cpp
  ${PROJECT_SOURCE_DIR}/editor/editor_helpers.cpp
  ${PROJECT_SOURCE_DIR}/editor/selection_manager.cpp
  #${PROJECT_SOURCE_DIR}/editor/windows/shader_node_window.cpp
  #${PROJECT_SOURCE_DIR}/editor/windows/material_window.cpp
  #${PROJECT_SOURCE_DIR}/editor/windows/status_bar.cpp
  #${PROJECT_SOURCE_DIR}/editor/windows/camera_window.cpp
)

set(RENDERER_SOURCES
  ${PROJECT_SOURCE_DIR}/renderer/renderer.cpp
  ${PROJECT_SOURCE_DIR}/renderer/shader_library.cpp
)

set(GUI_SOURCES
  ${PROJECT_SOURCE_DIR}/gui/window.cpp
  ${PROJECT_SOURCE_DIR}/gui/window_callback.cpp
  ${PROJECT_SOURCE_DIR}/gui/imgui/imgui_renderer.cpp
  ${PROJECT_SOURCE_DIR}/gui/imgui/imgui_platform.cpp
  ${PROJECT_SOURCE_DIR}/gui/imgui/imgui_window.cpp
  ${PROJECT_SOURCE_DIR}/gui/imgui/imgui_windows_manager.cpp
)

set(SCENE_SOURCES
  ${PROJECT_SOURCE_DIR}/scene/scene.cpp
  ${PROJECT_SOURCE_DIR}/scene/camera/camera.cpp
  #${PROJECT_SOURCE_DIR}/scene/light.cpp

  #${PROJECT_SOURCE_DIR}/scene/editor_camera.cpp
  ${PROJECT_SOURCE_DIR}/scene/components/transform.cpp
)

set(MESH_SOURCES 
  ${PROJECT_SOURCE_DIR}/mesh/mesh.cpp
  ${PROJECT_SOURCE_DIR}/mesh/mesh_factory.cpp
)

set(TERABITHIA_SOURCES
  ${MESH_SOURCES}
  #${IMGUIZMO_SOURCES}
  ${RENDERER_SOURCES}
  ${PROJECT_SOURCE_DIR}/external/imguifiledialog/ImGuiFileDialog.cpp
  ${GRAPHICS_SOURCES}
  ${CORE_SOURCES}
  ${SCENE_SOURCES}
  ${EDITOR_SOURCES}
  ${IMGUI_SOURCES}
  ${GUI_SOURCES}
  ${PROJECT_SOURCE_DIR}/terabithia/terabithia.cpp
  ${PROJECT_SOURCE_DIR}/terabithia/application.cpp
  ${PROJECT_SOURCE_DIR}/external/glad/glad.c
  ${PROJECT_SOURCE_DIR}/external/tinyobjloader/tiny_obj_loader.cc
  ${PROJECT_SOURCE_DIR}/external/easyloggingpp/easylogging++.cc
)

set(TERABITHIA_INCLUDE_DIR
  ${PROJECT_SOURCE_DIR}/core/include
  ${PROJECT_SOURCE_DIR}/gui/include/
  ${PROJECT_SOURCE_DIR}/gui/imgui/
  ${PROJECT_SOURCE_DIR}/editor/include/
  ${PROJECT_SOURCE_DIR}/editor/windows/include
  ${PROJECT_SOURCE_DIR}/scene/include
  ${PROJECT_SOURCE_DIR}/terabithia/include
  ${PROJECT_SOURCE_DIR}/scene/components
  ${PROJECT_SOURCE_DIR}/scene/light
  ${PROJECT_SOURCE_DIR}/scene/camera
  ${PROJECT_SOURCE_DIR}/graphics/include
  ${PROJECT_SOURCE_DIR}/graphics/texture
  ${PROJECT_SOURCE_DIR}/graphics/graphics_pipeline
  ${PROJECT_SOURCE_DIR}/graphics/vertex
  ${PROJECT_SOURCE_DIR}/graphics/buffer
  ${PROJECT_SOURCE_DIR}/mesh/include
  ${PROJECT_SOURCE_DIR}/mesh/material
  ${PROJECT_SOURCE_DIR}/renderer/include
)

set(IMGUI_INCLUDE_DIR
  ${PROJECT_SOURCE_DIR}/external/imgui/include
  ${PROJECT_SOURCE_DIR}/external/imgui/backend/
  ${PROJECT_SOURCE_DIR}/external/imguifiledialog/include
  #${PROJECT_SOURCE_DIR}/external/imguizmo/include
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-volatile")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer")

add_executable(${PROJECT_NAME} ${TERABITHIA_SOURCES})

#target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror)

target_include_directories(${PROJECT_NAME} PUBLIC

  #${PROJECT_SOURCE_DIR}/third_party/hopscotch/include/tsl/
  #${PROJECT_SOURCE_DIR}/third_party/xxHash/
  #${PROJECT_SOURCE_DIR}/external/signals/
  #${JoltPhysics_SOURCE_DIR}
  ${IMGUI_INCLUDE_DIR}
  ${PROJECT_SOURCE_DIR}/external/
  ${TERABITHIA_INCLUDE_DIR}
)

target_link_libraries(${PROJECT_NAME} PRIVATE
  glfw 
  OpenGL::GL
  glm::glm
)