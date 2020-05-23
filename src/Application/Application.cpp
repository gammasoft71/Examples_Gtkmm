#include <gtkmm.h>

using namespace Glib;
using namespace Gtk;

int main(int argc, char* argv[]) {
  auto application = Application::create(argc, argv);
  Window window;
  return application->run(window);
}
