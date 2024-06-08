#ifndef RENDERER_H
#define RENDERER_H

#include "mesh_allocator.h"
#include "scene.h"

namespace Terabithia {

class Renderer {
public:
  Renderer();

  NO_COPY_SEMANTIC(Renderer);
  NO_MOVE_SEMANTIC(Renderer);

  void ProcessMesh(const Mesh &mesh);

  void Begin(Scene &scene);
  void End();

  void Draw();

  Texture *GetColorTexture() const;

private:
  MeshAllocator mesh_allocator_;
  std::unique_ptr<Texture> color_texture_;
  std::unique_ptr<Renderbuffer> color_renderbuffer_;
  std::unique_ptr<Renderbuffer> depth_renderbuffer_;
  std::unique_ptr<Framebuffer> framebuffer_;
  std::vector<DrawArraysIndirectCommand> arrays_command_;
  std::vector<DrawElementsIndirectCommand> elements_command_;
};

} // namespace Terabithia

#endif // RENDERER_H