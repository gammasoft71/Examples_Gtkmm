#include <gtkmm.h>

using namespace Glib;
using namespace Gtk;

class Form : public Window {
public:
  Form() {
    this->add(this->scrolledWindow);
    this->scrolledWindow.add(this->fixed);
    
    this->button1.set_label("button1");
    this->button1.signal_button_release_event().connect([&](GdkEventButton* event) {
      this->label1.set_text(ustring::compose("button1 clicked %1 times", ++this->button1Clicked));
      return true;
    });
    this->fixed.add(this->button1);
    this->fixed.child_property_x(this->button1) = 50;
    this->fixed.child_property_y(this->button1) = 50;
    
    this->button2.set_label("button2");
    this->button2.set_size_request(200, 75);
    this->button2.signal_button_release_event().connect([&](GdkEventButton* event) {
      this->label2.set_text(ustring::compose("button2 clicked %1 times", ++this->button2Clicked));
      return true;
    });
    this->fixed.add(this->button2);
    this->fixed.child_property_x(this->button2) = 50;
    this->fixed.child_property_y(this->button2) = 100;
    
    this->label1.set_text(ustring::compose("button1 clicked %1 times", this->button1Clicked));
    this->fixed.add(this->label1);
    this->fixed.child_property_x(this->label1) = 50;
    this->fixed.child_property_y(this->label1) = 200;
    
    this->label2.set_text(ustring::compose("button2 clicked %1 times", this->button2Clicked));
    this->fixed.add(this->label2);
    this->fixed.child_property_x(this->label2) = 50;
    this->fixed.child_property_y(this->label2) = 230;
    
    this->set_title("Button example");
    this->resize(300, 300);
    this->show_all();
  }
  
private:
  Fixed fixed;
  ScrolledWindow scrolledWindow;
  Button button1;
  Button button2;
  Label label1;
  Label label2;
  int button1Clicked = 0;
  int button2Clicked = 0;
};

int main(int argc, char* argv[]) {
  RefPtr<Application> application = Application::create(argc, argv);
  Form form;
  return application->run(form);
}
