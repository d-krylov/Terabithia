set(TERABITHIA_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

set(IMGUI_SOURCES
  ${imgui_SOURCE_DIR}/imgui_draw.cpp
  ${imgui_SOURCE_DIR}/imgui_tables.cpp
  ${imgui_SOURCE_DIR}/imgui_widgets.cpp
  ${imgui_SOURCE_DIR}/imgui.cpp
)

set(TERABITHIA_SOURCES
  ${TERABITHIA_SOURCE_DIR}/application/application.cpp
  ${TERABITHIA_SOURCE_DIR}/core/core.cpp
  ${TERABITHIA_SOURCE_DIR}/core/timer.cpp
  ${TERABITHIA_SOURCE_DIR}/core/image.cpp
  ${TERABITHIA_SOURCE_DIR}/core/descriptor.cpp
  ${TERABITHIA_SOURCE_DIR}/mesh/shapes/shapes.cpp
  ${TERABITHIA_SOURCE_DIR}/mesh/model/wavefront_loader.cpp
  ${TERABITHIA_SOURCE_DIR}/scene/camera/camera.cpp
  ${TERABITHIA_SOURCE_DIR}/graphics/graphics_types.cpp
  ${TERABITHIA_SOURCE_DIR}/graphics/graphics_wrappers.cpp
  ${TERABITHIA_SOURCE_DIR}/graphics/vertex_array.cpp
  ${TERABITHIA_SOURCE_DIR}/graphics/framebuffer.cpp
  ${TERABITHIA_SOURCE_DIR}/graphics/buffer.cpp
  ${TERABITHIA_SOURCE_DIR}/graphics/texture.cpp
  ${TERABITHIA_SOURCE_DIR}/graphics/program.cpp
  ${TERABITHIA_SOURCE_DIR}/gui/window/window.cpp
  ${TERABITHIA_SOURCE_DIR}/gui/window/key.cpp
  ${TERABITHIA_SOURCE_DIR}/gui/imgui/imgui_layer.cpp
  ${TERABITHIA_SOURCE_DIR}/gui/imgui/imgui_renderer.cpp
)

configure_file(
  ${TERABITHIA_SOURCE_DIR}/common/config.h.in
  ${CMAKE_BINARY_DIR}/config/config.h
)

# GLAD

add_library(glad STATIC ${PROJECT_SOURCE_DIR}/external/glad/glad.c)

target_include_directories(glad PUBLIC ${PROJECT_SOURCE_DIR}/external)

# STB

add_library(stb_image  ${PROJECT_SOURCE_DIR}/external/stb/stb_image.cpp)

target_include_directories(stb_image PUBLIC ${stb_SOURCE_DIR})

# IMGUI

add_library(imgui STATIC ${IMGUI_SOURCES})

target_include_directories(imgui PUBLIC ${imgui_SOURCE_DIR})

# TERABITHIA

add_library(${PROJECT_NAME} STATIC 
  ${TERABITHIA_SOURCES}
)

target_include_directories(${PROJECT_NAME} PUBLIC
  ${PROJECT_SOURCE_DIR}
  ${CMAKE_BINARY_DIR}
)

target_link_libraries(${PROJECT_NAME} 
  glfw  
  glad
  imgui
  tinyobjloader
  glm::glm
  stb_image
)

target_compile_definitions(${PROJECT_NAME} PUBLIC
  GLM_ENABLE_EXPERIMENTAL
)