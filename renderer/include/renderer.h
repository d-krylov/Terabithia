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

  void Begin(const Scene &scene);

private:
  MeshAllocator mesh_allocator_;
  std::unique_ptr<Texture> color_texture_;
  std::unique_ptr<Framebuffer> framebuffer_;
};

} // namespace Terabithia

#endif // RENDERER_H