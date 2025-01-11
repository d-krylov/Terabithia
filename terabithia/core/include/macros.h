#ifndef TERABITHIA_MACROS_H
#define TERABITHIA_MACROS_H

#include <utility>

namespace Terabithia {

#define NO_MOVE_CONSTRUCTOR(TypeName) TypeName(TypeName &&) = delete;
#define NO_MOVE_OPERATOR(TypeName) TypeName &operator=(TypeName &&) = delete;

#define NO_MOVE_SEMANTIC(TypeName)                                                                                                         \
  NO_MOVE_CONSTRUCTOR(TypeName)                                                                                                            \
  NO_MOVE_OPERATOR(TypeName)

#define NO_COPY_CONSTRUCTOR(TypeName) TypeName(const TypeName &) = delete;
#define NO_COPY_OPERATOR(TypeName) void operator=(const TypeName &) = delete;

#define NO_COPY_SEMANTIC(TypeName)                                                                                                         \
  NO_COPY_CONSTRUCTOR(TypeName)                                                                                                            \
  NO_COPY_OPERATOR(TypeName)

#define CORE_UNREACHABLE() __builtin_unreachable()

} // namespace Terabithia

#endif // TERABITHIA_MACROS_H