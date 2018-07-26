#include <gtkmm.h>

using namespace Glib;
using namespace Gtk;

class Form : public Window {
public:
  Form() {
    this->add(this->scrolledWindow);
    this->scrolledWindow.add(this->fixed);
    
    this->fixed.add(this->panel1);
    this->fixed.move(this->panel1, 10, 10);
    this->panel1.set_size_request(305, 460);
    this->panel1.set_shadow_type(Gtk::SHADOW_IN);
    
    this->fixed.add(this->panel2);
    this->fixed.move(this->panel2, 325, 10);
    this->panel2.set_size_request(305, 460);
    this->panel2.set_shadow_type(Gtk::SHADOW_ETCHED_IN);

    this->set_title("Panel example");
    this->resize(640, 480);
    this->show_all();
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
