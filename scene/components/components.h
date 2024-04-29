#ifndef COMPONENTS_H
#define COMPONENTS_H

#include "UUID.h"
#include <string>

namespace Terabithia {

struct IDComponent {
  UUID id_;
};

struct NameComponent {
  std::string name_;
};

} // namespace Terabithia

#endif // COMPONENTS_H