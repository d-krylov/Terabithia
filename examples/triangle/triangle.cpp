#include "terabithia/common/terabithia.h"
#include <print>

using namespace Terabithia;

int main() {

  Window window(800, 600);
  std::array attributes{AttributeType::FLOAT_VEC2, AttributeType::FLOAT_VEC3};

  // clang-format off
  std::array data{
    -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
    +0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
    +0.0f, +0.5f, 0.0f, 0.0f, 1.0f};
  // clang-format on

  auto stride = GetStride(attributes);
  auto program = Program::CreateFromFiles("../shaders/test/2d.vert", "../shaders/test/2d.frag");
  VertexArray vertex_array;

  Buffer buffer(4096, BufferStorageMaskBit::MAP_WRITE);

  buffer.Map(MapBufferAccess::WRITE_ONLY);
  auto mapped_data = buffer.GetMappedBufferData<float>();
  std::copy(data.begin(), data.end(), mapped_data.begin());
  buffer.Unmap();

  vertex_array.SetAttributes(attributes);
  VertexArrayVertexBuffer(vertex_array.GetHandle(), buffer.GetHandle(), 0, stride, 0);

  while (window.ShouldClose() == false) {
    window.PollEvents();

    Clear(ClearBufferMaskBit::COLOR);

    vertex_array.Bind();
    program.Use();

    DrawArrays(0, 3, PrimitiveKind::TRIANGLES);

    window.Update();
  }

  return 0;
}