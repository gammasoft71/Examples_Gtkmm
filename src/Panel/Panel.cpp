#include <gtkmm.h>

using namespace Glib;
using namespace Gtk;

class Form : public Window {
public:
  Form() {
    add(scrolledWindow);
    scrolledWindow.add(fixed);
    
    fixed.add(panel1);
    fixed.move(panel1, 10, 10);
    panel1.set_size_request(305, 460);
    panel1.set_shadow_type(Gtk::SHADOW_IN);
    
    fixed.add(panel2);
    fixed.move(panel2, 325, 10);
    panel2.set_size_request(305, 460);
    panel2.set_shadow_type(Gtk::SHADOW_ETCHED_IN);

    set_title("Panel example");
    resize(640, 480);
    show_all();
  }
  
private:
  Fixed fixed;
  ScrolledWindow scrolledWindow;
  Frame panel1;
  Frame panel2;
};

int main(int argc, char* argv[]) {
  RefPtr<Application> application = Application::create(argc, argv);
  Form form;
  return application->run(form);
}
