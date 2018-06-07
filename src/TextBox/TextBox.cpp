#include <gtkmm.h>

using namespace Glib;
using namespace Gtk;

class Form : public Window {
public:
  Form() {
    this->add(this->scrolledWindow);
    this->scrolledWindow.add(this->fixed);
    
    this->textBox1.set_text("textBox1");
    this->fixed.add(this->textBox1);
    this->fixed.child_property_x(this->textBox1) = 10;
    this->fixed.child_property_y(this->textBox1) = 10;
    
    this->set_title("TextBox example");
    this->set_size_request(300, 300);
    this->show_all();
  }
  
private:
  Fixed fixed;
  ScrolledWindow scrolledWindow;
  Entry textBox1;
};

int main(int argc, char* argv[]) {
  RefPtr<Application> application = Application::create(argc, argv);
  Form form;
  return application->run(form);
}
