#include <utility>
#include "terabithia/core/include/descriptor.h"

namespace Terabithia {

Descriptor::Descriptor(uint32_t descriptor) : descriptor_(descriptor) {
}

Descriptor::Descriptor(Descriptor &&other) noexcept {
  descriptor_ = std::exchange(other.descriptor_, 0);
}

Descriptor &Descriptor::operator=(Descriptor &&other) noexcept {
  descriptor_ = std::exchange(other.descriptor_, 0);
  return *this;
}

uint32_t *Descriptor::get() {
  return &descriptor_;
}

Descriptor::operator uint32_t() const {
  return descriptor_;
}

Descriptor::operator uint32_t &() {
  return descriptor_;
}

bool Descriptor::IsValid() const {
  return descriptor_ != 0;
}

} // namespace Terabithia