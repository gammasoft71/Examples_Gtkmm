#include <gtkmm.h>

using namespace Glib;
using namespace Gtk;

class Form : public Window {
public:
  Form() {
    this->add(this->scrolledWindow);
    this->scrolledWindow.add(this->fixed);
    
    this->groupBox1.set_label("GroupBox 1");
    this->fixed.add(this->groupBox1);
    this->fixed.move(this->groupBox1, 10, 10);
    this->groupBox1.set_size_request(305, 460);
    
    this->groupBox2.set_label("GroupBox 2");
    this->fixed.add(this->groupBox2);
    this->fixed.move(this->groupBox2, 325, 10);
    this->groupBox2.set_size_request(305, 460);

    this->set_title("GroupBox example");
    this->resize(640, 480);
    this->show_all();
  }
  
private:
  Fixed fixed;
  ScrolledWindow scrolledWindow;
  Frame groupBox1;
  Frame groupBox2;
};

int main(int argc, char* argv[]) {
  RefPtr<Application> application = Application::create(argc, argv);
  Form form;
  return application->run(form);
}
