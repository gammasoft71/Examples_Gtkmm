#include <gtkmm.h>

using namespace Glib;
using namespace Gtk;

int main(int argc, char* argv[]) {
  RefPtr<Application> application = Application::create(argc, argv);
  Window form;
  return application->run(form);
}
