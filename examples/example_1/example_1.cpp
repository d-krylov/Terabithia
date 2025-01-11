#include "application/include/terabithia.h"
#include <iostream>
#include "mesh/include/shape.h"

using namespace Terabithia;

struct Vertex {
  Vector3f position;
  Vector3f normal;
  Vector2f uv;
};

int main() {

  Window window("Example", 800, 600);

  Image image(TERABITHIA_ROOT / "assets" / "images" / "container.png");

  std::cout << image.GetWidth() << " " << image.GetHeight() << std::endl;

  Texture texture(image.GetWidth(), image.GetHeight(), 1, TextureTarget::TEXTURE_2D, InternalFormat::RGBA8, false, MinFilter::LINEAR,
                  MagFilter::LINEAR, WrapMode::CLAMP_TO_EDGE);

  texture.SetData(image.GetData());

  texture.Bind(0);

  Program program(SHADERS_SOURCE_DIR / "pulling" / "textured_mesh.vert", SHADERS_SOURCE_DIR / "common" / "textured_mesh.frag");

  Camera camera;

  Timer timer;

  camera.SetPosition(Vector3f(0.0f, 0.0f, 5.0f));

  VertexArray vao;

  Buffer<BufferStorage::MAP_WRITE | BufferStorage::DYNAMIC_STORAGE> buffer(BufferTarget::SHADER_STORAGE, 4_KiB);

  // buffer.Map(0, 4_KiB);
  buffer.SetData(MakeBox());
  // buffer.Unmap();

  GL::Enable(Capabilities::DEPTH_TEST);

  while (window.ShouldClose() == false) {
    window.PollEvents();

    GL::Clear(BufferBit::COLOR | BufferBit::DEPTH);

    auto rotate = glm::rotate(Matrix4f(1.0f), timer.GetElapsed(1.0f), Y_);

    buffer.Bind(0);
    vao.Bind();
    program.Use();
    program.SetUniform("u_diffuse", 0);
    program.SetUniform("u_view_matrix", camera.GetLookAtMatrix());
    program.SetUniform("u_projection_matrix", camera.GetProjectionMatrix());
    program.SetUniform("u_model_matrix", rotate);

    GL::DrawArrays(0, 36);

    window.Update();
  }

  return 0;
}