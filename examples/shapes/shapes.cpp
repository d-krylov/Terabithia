#include "terabithia/common/terabithia.h"

using namespace Terabithia;

int main() {

  Window window(800, 600);

  std::array attributes{AttributeType::FLOAT_VEC3, AttributeType::FLOAT_VEC3};

  auto hexahedron = MakeHexahedron(1.0f, 1.0f, 1.0f);

  auto program = Program::CreateFromFiles(GetTerabithiaShaders() / "test" / "shape.vert", GetTerabithiaShaders() / "test" / "shape.frag");

  VertexArray vertex_array;

  vertex_array.SetAttributes(attributes);

  Buffer buffer(10_KiB, BufferStorageMaskBit::MAP_WRITE);

  buffer.Map(MapBufferAccess::WRITE_ONLY);

  auto mapped_data = buffer.GetMappedBufferData<Vertex>();

  std::copy(hexahedron.begin(), hexahedron.end(), mapped_data.begin());

  buffer.Unmap();

  Timer timer;

  auto view_matrix = glm::lookAt(Vector3f(0.0f, 0.0f, 5.0f), Vector3f(0.0f, 0.0f, 0.0f), Vector3f(0.0f, 1.0f, 0.0f));

  auto projection_matrix = glm::perspective(1.0f, window.GetAspect(), 0.1f, -100.0f);

  VertexArrayVertexBuffer(vertex_array.GetHandle(), buffer.GetHandle(), 0, GetStride(attributes), 0);

  Enable(Capability::DEPTH_TEST);

  SetDepthFunction(DepthFunction::LESS);

  while (window.ShouldClose() == false) {

    window.PollEvents();

    Clear(ClearBufferMaskBit::COLOR | ClearBufferMaskBit::DEPTH);

    vertex_array.Bind();

    program.Use();

    auto model_matrix = glm::rotate(Matrix4f(1.0f), timer.ElapsedSeconds(), Vector3f(0.0f, 1.0f, 0.0f));

    program.SetUniform("u_view_matrix", view_matrix);

    program.SetUniform("u_projection_matrix", projection_matrix);

    program.SetUniform("u_model_matrix", model_matrix);

    DrawArrays(0, hexahedron.size(), PrimitiveKind::TRIANGLES);

    window.Update();
  }

  return 0;
}