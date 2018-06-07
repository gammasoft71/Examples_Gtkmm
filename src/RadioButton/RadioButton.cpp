#include <gtkmm.h>

using namespace Glib;
using namespace Gtk;

class Form : public Window {
public:
  Form() {
    this->add(this->scrolledWindow);
    this->scrolledWindow.add(this->fixed);
    
    this->radioButton1.set_label("radioButton 1");
    this->radioButton1.set_active(true);
    this->radioButton1.set_group(this->radioButtonGroup1);
    this->fixed.add(this->radioButton1);
    this->fixed.child_property_x(this->radioButton1) = 30;
    this->fixed.child_property_y(this->radioButton1) = 30;
    
    this->radioButton2.set_label("radioButton 2");
    this->radioButton2.set_group(this->radioButtonGroup1);
    this->fixed.add(this->radioButton2);
    this->fixed.child_property_x(this->radioButton2) = 30;
    this->fixed.child_property_y(this->radioButton2) = 60;
    
    this->radioButton3.set_label("radioButton 3");
    this->radioButton3.set_group(this->radioButtonGroup1);
    this->fixed.add(this->radioButton3);
    this->fixed.child_property_x(this->radioButton3) = 30;
    this->fixed.child_property_y(this->radioButton3) = 90;

    this->set_title("RadioButton example");
    this->set_size_request(300, 300);
    this->show_all();
  }
  
private:
  Fixed fixed;
  ScrolledWindow scrolledWindow;
  RadioButtonGroup radioButtonGroup1;
  RadioButton radioButton1;
  RadioButton radioButton2;
  RadioButton radioButton3;
};

// The main entry point for the application.
int main(int argc, char* argv[]) {
  RefPtr<Application> application = Application::create(argc, argv);
  Form form;
  return application->run(form);
}
