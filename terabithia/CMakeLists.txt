set(TERABITHIA_SOURCE_DIR ${PROJECT_SOURCE_DIR}/terabithia)

set(TERABITHIA_MESH_SOURCES
  ${TERABITHIA_SOURCE_DIR}/mesh/assimp_loader.cpp
  ${TERABITHIA_SOURCE_DIR}/mesh/wavefront_loader.cpp
  ${TERABITHIA_SOURCE_DIR}/mesh/shape.cpp
)

set(SCENE_SOURCES
  ${TERABITHIA_SOURCE_DIR}/scene/camera.cpp
)

set(TERABITHIA_CORE_SOURCES
  ${TERABITHIA_SOURCE_DIR}/core/image.cpp
  ${TERABITHIA_SOURCE_DIR}/core/tools.cpp
)

set(EXTERNAL_SOURCES
  ${imgui_SOURCE_DIR}/imgui_draw.cpp
  ${imgui_SOURCE_DIR}/imgui_tables.cpp
  ${imgui_SOURCE_DIR}/imgui_widgets.cpp
  ${imgui_SOURCE_DIR}/imgui.cpp
  ${PROJECT_SOURCE_DIR}/external/glad/glad.c
  ${PROJECT_SOURCE_DIR}/external/stb/stb.cpp
)

set(TERABITHIA_SOURCES
  ${TERABITHIA_MESH_SOURCES}
  ${TERABITHIA_GRAPHICS_SOURCES}
  ${TERABITHIA_GUI_SOURCES}
  ${TERABITHIA_CORE_SOURCES}
  ${EXTERNAL_SOURCES}
  ${SCENE_SOURCES}
  ${TERABITHIA_SOURCE_DIR}/gui/window.cpp
  ${TERABITHIA_SOURCE_DIR}/gui/imgui/imgui_renderer.cpp
  ${TERABITHIA_SOURCE_DIR}/gui/imgui/imgui_layer.cpp
  ${TERABITHIA_SOURCE_DIR}/graphics/graphics_types.cpp
  ${TERABITHIA_SOURCE_DIR}/application/application.cpp
  ${TERABITHIA_SOURCE_DIR}/mathematics/noise.cpp
)

add_library(${PROJECT_NAME} STATIC 
  ${TERABITHIA_SOURCES}
)

target_include_directories(${PROJECT_NAME} PUBLIC
  ${TERABITHIA_SOURCE_DIR}
  ${PROJECT_SOURCE_DIR}/external/
  ${PROJECT_SOURCE_DIR}/assets/meshes
  ${ASSIMP_INCLUDE_DIR}
  ${imgui_SOURCE_DIR}
  ${stb_SOURCE_DIR}
)

target_link_libraries(${PROJECT_NAME} PUBLIC 
  OpenGL::GL
  glfw
  glm::glm
  assimp
  tinyobjloader
)

target_compile_definitions(${PROJECT_NAME} PUBLIC TERABITHIA_PROJECT_SOURCE_DIR="${PROJECT_SOURCE_DIR}")