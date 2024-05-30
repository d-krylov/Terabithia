#ifndef RENDERER_H
#define RENDERER_H

#include "graphics.h"
#include "mesh.h"

namespace Terabithia {

class Renderer {
public:
  Renderer();

  ~Renderer();

  void ProcessMesh(const Mesh &mesh);

private:
  VertexArray vertex_array_;
};

} // namespace Terabithia

#endif // RENDERER_H