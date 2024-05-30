#include "application.h"
#include "easyloggingpp/easylogging++.h"
INITIALIZE_EASYLOGGINGPP

int main() {

  Terabithia::Application application;

  application.Run();

  return 0;
}