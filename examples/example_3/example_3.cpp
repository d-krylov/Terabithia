#include "application/include/terabithia.h"
#include "core/include/timer.h"
#include <iostream>

using namespace Terabithia;

struct Vertex {
  Vector3f position;
  Vector3f normal;
  uint32_t color;
  Vector2f uv;
};

int main() {

  Window window("Example", 800, 600);

  Image image(TERABITHIA_ROOT / "assets" / "images" / "container.png");

  std::cout << image.GetWidth() << " " << image.GetHeight() << std::endl;

  // Texture texture(image.GetWidth(), image.GetHeight(), 1, TextureTarget::TEXTURE_2D, InternalFormat::RGBA8, false, MinFilter::LINEAR,
  //                 MagFilter::LINEAR, WrapMode::CLAMP_TO_EDGE);

  // texture.SetData(image.GetData());

  // texture.Bind(0);

  Program program(SHADERS_SOURCE_DIR / "common" / "mesh.vert", SHADERS_SOURCE_DIR / "common" / "mesh.frag");

  VertexArray vao;

  Timer timer;

  Buffer<BufferStorage::DYNAMIC_STORAGE> buffer(BufferTarget::SHADER_STORAGE, 4_KiB);

  std::vector<Vertex> v{{{-0.5f, -0.5f, 0.0f}, {0.0f, 0.0f, 0.0f}, 0x000000ff, {0.0f, 0.0f}},
                        {{+0.5f, -0.5f, 0.0f}, {0.0f, 0.0f, 0.0f}, 0x0000ff00, {1.0f, 0.0f}},
                        {{+0.5f, +0.5f, 0.0f}, {0.0f, 0.0f, 0.0f}, 0x00ff0000, {1.0f, 1.0f}},
                        {{+0.5f, +0.5f, 0.0f}, {0.0f, 0.0f, 0.0f}, 0x00ff0000, {1.0f, 1.0f}},
                        {{-0.5f, +0.5f, 0.0f}, {0.0f, 0.0f, 0.0f}, 0xffffffff, {0.0f, 1.0f}},
                        {{-0.5f, -0.5f, 0.0f}, {0.0f, 0.0f, 0.0f}, 0xff0000ff, {0.0f, 0.0f}}};

  std::array<Format, 4> format{Format::R32G32B32_FLOAT, Format::R32G32B32_FLOAT, Format::R8G8B8A8_UNORM, Format::R32G32_FLOAT};

  auto stride = vao.SetVertexFormat(format);
  vao.SetVertexBuffer(buffer, stride);

  // buffer.Map(0, 4_KiB);
  buffer.SetData(v);
  // buffer.Unmap();

  while (window.ShouldClose() == false) {
    window.PollEvents();

    GL::Clear();

    vao.Bind();
    program.Use();

    auto rotate = glm::rotate(Matrix4f(1.0f), timer.GetElapsed(1.0f), Y_);

    program.SetUniform("u_model_matrix", rotate);

    GL::DrawArrays(0, 6);

    window.Update();
  }

  return 0;
}
