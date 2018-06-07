#include <gtkmm.h>

using namespace Glib;
using namespace Gtk;

class Form : public Window {
public:
  Form() {
    this->add(this->scrolledWindow);
    this->scrolledWindow.add(this->fixed);
    
    this->label1.set_text("label1");
    this->fixed.add(this->label1);
    this->fixed.child_property_x(this->label1) = 10;
    this->fixed.child_property_y(this->label1) = 10;
    
    this->set_title("Label example");
    this->set_size_request(300, 300);
    this->show_all();
  }
  
private:
  Fixed fixed;
  ScrolledWindow scrolledWindow;
  Label label1;
};

// The main entry point for the application.
int main(int argc, char* argv[]) {
  RefPtr<Application> application = Application::create(argc, argv);
  Form form;
  return application->run(form);
}
