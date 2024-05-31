#ifndef EDITOR_HELEPERS_H
#define EDITOR_HELEPERS_H

#include "core_types.h"
#include <string>

namespace Terabithia {

bool PrimaryButton(const std::string &name, const Vector2i &size);
void InputVector3(std::string_view item_name, Vector3f &value);

} // namespace Terabithia

#endif // EDITOR_HELEPERS_H