#ifndef UUID_H
#define UUID_H

#include <cstdint>

namespace Terabithia {

class UUID {
public:
  UUID();
  UUID(uint64_t uuid);
  operator uint64_t() { return uuid_; }
  operator const uint64_t() const { return uuid_; }

private:
  uint64_t uuid_;
};

} // namespace Terabithia

namespace std {
template <typename T> struct hash;

template <> struct hash<Terabithia::UUID> {
  std::size_t operator()(const Terabithia::UUID &uuid) const {
    return (uint64_t)uuid;
  }
};

} // namespace std

#endif // UUID_H