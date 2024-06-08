#include "application.h"
#include "easyloggingpp/easylogging++.h"
INITIALIZE_EASYLOGGINGPP

int main(int argc, char **argv) {
  START_EASYLOGGINGPP(argc, argv);

  Terabithia::Application application;

  application.Run();

  return 0;
}