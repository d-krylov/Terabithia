#include "terabithia/common/terabithia.h"

using namespace Terabithia;

class Compute : public Layer {
public:
  void OnImGui() override {
  }

  void OnUpdate() override {
    texture_->BindImage(0, BufferAccess::READ_WRITE);

    auto application = Application::Get();
    auto &window = application->GetWindow();
    auto size = window.GetSize();

    compute_program_->Use();
    compute_program_->SetUniform("iTime", timer.ElapsedSeconds());
    compute_program_->SetUniform("iResolution", Vector2i(size.width, size.height));

    DispatchCompute((size.width + 15) / 16, (size.height + 15) / 16, 1);

    MemoryBarrier(MemoryBarrierMaskBit::SHADER_IMAGE_ACCESS);

    vertex_array.Bind();
    texture_->Bind(0);

    canvas_program_->Use();
    canvas_program_->SetUniform("u_texture", 0);

    DrawArrays(0, 3);
  }

  void OnEvent(Event &event) override {
    EventDispatcher dispatcher(event);
    dispatcher.Dispatch<WindowResizeEvent>(BIND_FUNCTION(Compute::OnWindowResizeEvent));
  }

  bool OnWindowResizeEvent(WindowResizeEvent &event) {
    auto application = Application::Get();
    auto &window = application->GetWindow();
    auto size = window.GetSize();
    texture_ = std::make_unique<Texture>(TextureTarget::TEXTURE_2D, InternalFormat::RGBA32F, TextureInformation(size.width, size.height));
    return true;
  }

  void OnAttach() override {
    auto root = GetTerabithiaShaders();
    compute_program_ = std::make_unique<Program>(Program::CreateFromFiles(root / "gallery" / "terrain.comp"));
    canvas_program_ = std::make_unique<Program>(Program::CreateFromFiles(root / "test" / "square.vert", root / "test" / "square.frag"));
    texture_ = std::make_unique<Texture>(TextureTarget::TEXTURE_2D, InternalFormat::RGBA32F, TextureInformation(512, 512));
  }

private:
  Timer timer;
  VertexArray vertex_array;
  std::unique_ptr<Program> compute_program_;
  std::unique_ptr<Program> canvas_program_;
  std::unique_ptr<Texture> texture_;
};

int main(int argc, char **argv) {

  Application application(512, 512);

  Compute compute;

  application.AddLayer(&compute);

  application.Run();

  return 0;
}