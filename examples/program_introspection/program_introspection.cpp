#include "terabithia/common/terabithia.h"
#include <print>

using namespace Terabithia;

int main() {

  Window window(800, 600);

  auto program = Program::CreateFromFiles("../shaders/test/2d.vert", "../shaders/test/2d.frag");

  std::array properties{ProgramResourceProperty::NAME_LENGTH, ProgramResourceProperty::TYPE, ProgramResourceProperty::LOCATION};

  int32_t active_resources{0};

  GetProgramInterface(program.GetHandle(), ProgramInterface::PROGRAM_INPUT, ProgramInterfaceParameterName::ACTIVE_RESOURCES, active_resources);

  for (auto i = 0; i < active_resources; i++) {
    auto ret = GetProgramResource(program.GetHandle(), Terabithia::ProgramInterface::PROGRAM_INPUT, i, properties);
    auto name = GetProgramResourceName(program.GetHandle(), ProgramInterface::PROGRAM_INPUT, i, ret[0]);

    std::println("name: {}, type: {}", name, ToString(AttributeType(ret[1])));
  }

  return 0;
}