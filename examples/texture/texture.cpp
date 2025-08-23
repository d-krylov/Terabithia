#include "terabithia/common/terabithia.h"
#include <print>

using namespace Terabithia;

std::vector<int32_t> MakeTexture(uint32_t width, uint32_t height) {
  std::vector<int32_t> ret(width * height);
  for (auto x = 0; x < width; x++) {
    for (auto y = 0; y < height; y++) {
      ret[y * width + x] = 0x7f7f7f7f;
    }
  }
  return ret;
}

int main() {
  Window window(800, 600);

  auto program = Terabithia::Program::CreateFromFiles("../shaders/test/square.vert", "../shaders/test/square.frag");

  Terabithia::VertexArray vertex_array;
  Terabithia::Texture texture(TextureTarget::TEXTURE_2D, InternalFormat::RGBA8, TextureInformation(800, 600));

  auto texture_data = MakeTexture(800, 600);

  texture.SetData<int32_t>(texture_data);

  while (window.ShouldClose() == false) {
    window.PollEvents();

    Viewport(0, 0, window.GetWidth(), window.GetHeight());

    Clear(ClearBufferMaskBit::COLOR);

    vertex_array.Bind();
    texture.Bind(0);
    program.Use();
    program.SetUniform("u_texture", 0);

    DrawArrays(0, 3, PrimitiveKind::TRIANGLES);

    window.Update();
  }

  return 0;
}