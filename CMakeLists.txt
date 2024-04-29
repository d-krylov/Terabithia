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
  ${PROJECT_SOURCE_DIR}/core/filesystem.cpp
  #${PROJECT_SOURCE_DIR}/base/base_logger.cpp
)

set(PLATFORM_SOURCES
  ${PROJECT_SOURCE_DIR}/platform/shader.cpp
  ${PROJECT_SOURCE_DIR}/platform/debug.cpp
  ${PROJECT_SOURCE_DIR}/platform/buffer.cpp
  ${PROJECT_SOURCE_DIR}/platform/framebuffer.cpp
  ${PROJECT_SOURCE_DIR}/platform/texture.cpp
  ${PROJECT_SOURCE_DIR}/platform/vertex_array.cpp
  ${PROJECT_SOURCE_DIR}/platform/shader_pipeline.cpp
  ${PROJECT_SOURCE_DIR}/platform/generated_shader.cpp
  ${PROJECT_SOURCE_DIR}/platform/types/types.cpp
  ${PROJECT_SOURCE_DIR}/platform/types/texture_types.cpp
  ${PROJECT_SOURCE_DIR}/platform/vertex_format.cpp
  ${PROJECT_SOURCE_DIR}/platform/renderbuffer.cpp
  ${PROJECT_SOURCE_DIR}/platform/shader_information.cpp
)

set(EDITOR_SOURCES
  ${PROJECT_SOURCE_DIR}/editor/editor.cpp
  ${PROJECT_SOURCE_DIR}/editor/windows/viewport_window.cpp
  ${PROJECT_SOURCE_DIR}/editor/windows/component_window.cpp
  ${PROJECT_SOURCE_DIR}/editor/windows/hierarchy_window.cpp
  ${PROJECT_SOURCE_DIR}/editor/windows/main_menu.cpp
  ${PROJECT_SOURCE_DIR}/editor/windows/console_window.cpp
  ${PROJECT_SOURCE_DIR}/editor/windows/browser_window.cpp
  #${PROJECT_SOURCE_DIR}/editor/windows/shader_node_editor.cpp
  #${PROJECT_SOURCE_DIR}/editor/windows/shader_node_window.cpp
  #${PROJECT_SOURCE_DIR}/editor/windows/material_window.cpp
  #${PROJECT_SOURCE_DIR}/editor/windows/status_bar.cpp
  #${PROJECT_SOURCE_DIR}/editor/windows/camera_window.cpp
)

set(RENDERER_SOURCES
  ${PROJECT_SOURCE_DIR}/renderer/buffers/command_buffer.cpp
  ${PROJECT_SOURCE_DIR}/renderer/buffers/vertex_buffer.cpp
  ${PROJECT_SOURCE_DIR}/renderer/buffers/index_buffer.cpp
  ${PROJECT_SOURCE_DIR}/renderer/buffers/attached_buffer.cpp
  ${PROJECT_SOURCE_DIR}/renderer/buffers/hashed_buffer.cpp
  ${PROJECT_SOURCE_DIR}/renderer/renderer_common.cpp
  ${PROJECT_SOURCE_DIR}/renderer/scene_renderer.cpp
  ${PROJECT_SOURCE_DIR}/renderer/renderer.cpp
  ${PROJECT_SOURCE_DIR}/renderer/simple_renderer.cpp
  ${PROJECT_SOURCE_DIR}/renderer/shader_library.cpp
)

set(TERABITHIA_GUI_SOURCES
  ${PROJECT_SOURCE_DIR}/gui/window.cpp
  ${PROJECT_SOURCE_DIR}/gui/imgui/imgui_renderer.cpp
  ${PROJECT_SOURCE_DIR}/gui/imgui/imgui_platform.cpp
  ${PROJECT_SOURCE_DIR}/gui/imgui/imgui_window.cpp
  ${PROJECT_SOURCE_DIR}/gui/imgui/imgui_helpers.cpp
)

set(SCENE_SOURCES
  ${PROJECT_SOURCE_DIR}/scene/scene.cpp
  ${PROJECT_SOURCE_DIR}/scene/scene_manager.cpp
  #${PROJECT_SOURCE_DIR}/scene/light.cpp
  #${PROJECT_SOURCE_DIR}/scene/camera.cpp
  #${PROJECT_SOURCE_DIR}/scene/editor_camera.cpp
  #${PROJECT_SOURCE_DIR}/scene/material.cpp
)

set(GEOMETRY_SOURCES
  ${PROJECT_SOURCE_DIR}/geometry/triangle.cpp
  ${PROJECT_SOURCE_DIR}/geometry/geometry_core.cpp
  ${PROJECT_SOURCE_DIR}/geometry/he/he_geometry.cpp
  ${PROJECT_SOURCE_DIR}/geometry/he/he_edge.cpp
)

set(MESH_SOURCES 
  ${PROJECT_SOURCE_DIR}/mesh/mesh.cpp
  ${PROJECT_SOURCE_DIR}/mesh/mesh_tools.cpp
  ${PROJECT_SOURCE_DIR}/mesh/model/tinyobj_model_loader.cpp
  ${PROJECT_SOURCE_DIR}/mesh/simple_mesh.cpp
  ${PROJECT_SOURCE_DIR}/mesh/mesh_builder.cpp
  ${PROJECT_SOURCE_DIR}/mesh/primitives/box.cpp
  ${PROJECT_SOURCE_DIR}/mesh/primitives/plane.cpp
  ${PROJECT_SOURCE_DIR}/mesh/primitives/cylinder.cpp
  ${PROJECT_SOURCE_DIR}/mesh/primitives/sphere.cpp
)

set(TERABITHIA_SOURCES
  #${MESH_SOURCES}

  #${IMGUIZMO_SOURCES}
  #${PLATFORM_SOURCES}
  #${GEOMETRY_SOURCES}
  #${RENDERER_SOURCES}
  ${PROJECT_SOURCE_DIR}/external/imguifiledialog/ImGuiFileDialog.cpp
  ${CORE_SOURCES}
  ${SCENE_SOURCES}
  ${EDITOR_SOURCES}
  ${IMGUI_SOURCES}
  ${TERABITHIA_GUI_SOURCES}
  ${PROJECT_SOURCE_DIR}/terabithia/terabithia.cpp
  ${PROJECT_SOURCE_DIR}/terabithia/application.cpp
  ${PROJECT_SOURCE_DIR}/external/glad/glad.c
)

set(TERABITHIA_INCLUDE_DIR
  ${PROJECT_SOURCE_DIR}/core/include
  ${PROJECT_SOURCE_DIR}/gui/include/
  ${PROJECT_SOURCE_DIR}/editor/include/
  ${PROJECT_SOURCE_DIR}/gui/imgui/
  ${PROJECT_SOURCE_DIR}/editor/windows/include
  ${PROJECT_SOURCE_DIR}/scene/include
  ${PROJECT_SOURCE_DIR}/terabithia/include
  ${PROJECT_SOURCE_DIR}/scene/components
  ${PROJECT_SOURCE_DIR}/scene/light
  ${PROJECT_SOURCE_DIR}/scene/material
  ${PROJECT_SOURCE_DIR}/scene/camera
  #${PROJECT_SOURCE_DIR}/mesh/include
  #${PROJECT_SOURCE_DIR}/mesh/model/include
  #${PROJECT_SOURCE_DIR}/mesh/primitives/include
  #${PROJECT_SOURCE_DIR}/renderer/include
  #${PROJECT_SOURCE_DIR}/renderer/buffers/include
  #${PROJECT_SOURCE_DIR}/geometry/include
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
 #${PROJECT_SOURCE_DIR}/third_party/


 #${PROJECT_SOURCE_DIR}/third_party/hopscotch/include/tsl/
  #${PROJECT_SOURCE_DIR}/third_party/xxHash/
  #${PROJECT_SOURCE_DIR}/external/signals/
  #${PROJECT_SOURCE_DIR}/external/spdlog/include
  #${JoltPhysics_SOURCE_DIR}
  #${assimp_SOURCE_DIR}
  #${OPENGL_INCLUDE_DIR}
  ${IMGUI_INCLUDE_DIR}
  ${PROJECT_SOURCE_DIR}/external/
  ${TERABITHIA_INCLUDE_DIR}
)

target_link_libraries(${PROJECT_NAME}
  glfw 
  OpenGL::GL 
)