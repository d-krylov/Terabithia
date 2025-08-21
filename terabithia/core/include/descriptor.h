#ifndef TERABITHIA_DESCRIPTOR_H
#define TERABITHIA_DESCRIPTOR_H

#include <cstdint>

namespace Terabithia {

class Descriptor {
public:
  Descriptor(uint32_t descriptor = 0);

  Descriptor(const Descriptor &) = delete;

  Descriptor &operator=(const Descriptor &) = delete;

  Descriptor(Descriptor &&other) noexcept;

  Descriptor &operator=(Descriptor &&other) noexcept;

  uint32_t *get();

  operator uint32_t() const;

  operator uint32_t &();

  bool IsValid() const;

private:
  uint32_t descriptor_{0};
};

} // namespace Terabithia

#endif // TERABITHIA_DESCRIPTOR_H