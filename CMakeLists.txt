cmake_minimum_required(VERSION 3.25)

project(Terabithia LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

set(CMAKE_BUILD_TYPE RelWithDebInfo)

find_package(glfw3  REQUIRED)
find_package(OpenGL REQUIRED)
find_package(assimp REQUIRED)
find_package(Vulkan REQUIRED)

include(cmake/libraries.cmake)

FetchContent_MakeAvailable(
  glm
  imgui
  tinyobjloader
  stb
)

add_definitions(-DGLM_ENABLE_EXPERIMENTAL)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-volatile")

add_subdirectory(terabithia)

file(GLOB SHADER_FILES 
  ".vert" ".frag"
)

set(SHADER_OUTPUT_DIR ${PROJECT_SOURCE_DIR}/shaders/spirv)

foreach(SHADER ${SHADER_FILES})
  get_filename_component(SHADER_NAME ${SHADER} NAME)

  set(SHADER_OUTPUT "${SHADER_OUTPUT_DIR}/${SHADER_NAME}.spv")

  add_custom_command(
    OUTPUT ${SHADER_OUTPUT}
    COMMAND ${Vulkan_GLSLC_EXECUTABLE} -c --target-env=opengl ${SHADER} -o ${SHADER_OUTPUT}
    DEPENDS ${SHADER}
    COMMENT "Compiling ${SHADER} to ${SHADER_OUTPUT}"
  )

  list(APPEND SPIRV_FILES ${SHADER_OUTPUT})
endforeach()

add_custom_target(shaders ALL DEPENDS ${SPIRV_FILES})

if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
  
  include(cmake/clang_format.cmake)

  add_clang_format_target(format "build;external")

  add_subdirectory(examples)

endif()

