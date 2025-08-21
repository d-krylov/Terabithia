cmake_minimum_required(VERSION 3.25)

project(Terabithia LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

set(CMAKE_BUILD_TYPE RelWithDebInfo)

include(cmake/libraries.cmake)
include(cmake/clang_format.cmake)

find_package(glfw3 REQUIRED)

FetchContent_MakeAvailable(
  imgui
  tinyobjloader
  glm
  stb
)

add_subdirectory(terabithia)

if(${PROJECT_IS_TOP_LEVEL})
  
  add_clang_format_target(format "build;external")

  add_subdirectory(examples)

endif()
