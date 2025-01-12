#include "application/include/terabithia.h"
#include "core/include/timer.h"
#include <iostream>

using namespace Terabithia;

int main() {

  Window window("Example", 800, 600);

  Program program(SHADERS_SOURCE_DIR / "pulling" / "plain_mesh.vert", SHADERS_SOURCE_DIR / "common" / "plain_mesh.frag");

  Camera camera;

  Timer timer;

  camera.SetPosition(Vector3f(0.0f, 0.0f, 5.0f));

  VertexArray vao;

  Buffer<BufferStorage::MAP_WRITE | BufferStorage::DYNAMIC_STORAGE> buffer(BufferTarget::SHADER_STORAGE, 20_MiB);

  auto mesh = LoadWavefront(ASSETS_DIR / "meshes" / "icosahedron.obj");

  buffer.SetData(mesh);

  GL::Enable(Capabilities::DEPTH_TEST);

  while (window.ShouldClose() == false) {
    window.PollEvents();

    GL::Clear(BufferBit::COLOR | BufferBit::DEPTH);

    auto rotate = glm::rotate(Matrix4f(1.0f), timer.GetElapsed(1.0f), Y_);

    buffer.Bind(0);
    vao.Bind();
    program.Use();
    program.SetUniform("u_view_matrix", camera.GetLookAtMatrix());
    program.SetUniform("u_projection_matrix", camera.GetProjectionMatrix());
    program.SetUniform("u_model_matrix", rotate);

    GL::DrawArrays(0, mesh.size());

    window.Update();
  }

  return 0;
}
