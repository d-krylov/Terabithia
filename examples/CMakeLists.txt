set(EXECUTABLES
  mesh_viewer
  program_introspection
  triangle
  texture
  shapes
  compute
)

foreach(exe ${EXECUTABLES})
  add_executable(${exe} ${EXAMPLES_TOOLS} ${CMAKE_CURRENT_SOURCE_DIR}/${exe}/${exe}.cpp)
  target_link_libraries(${exe} PRIVATE Terabithia)
endforeach()