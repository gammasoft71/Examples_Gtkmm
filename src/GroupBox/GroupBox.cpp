#include <gtkmm.h>

using namespace Glib;
using namespace Gtk;

class Form : public Window {
public:
  Form() {
    add(scrolledWindow);
    scrolledWindow.add(fixed);
    
    groupBox1.set_label("GroupBox 1");
    fixed.add(groupBox1);
    fixed.move(groupBox1, 10, 10);
    groupBox1.set_size_request(305, 460);
    
    groupBox2.set_label("GroupBox 2");
    fixed.add(groupBox2);
    fixed.move(groupBox2, 325, 10);
    groupBox2.set_size_request(305, 460);

    set_title("GroupBox example");
    resize(640, 480);
    show_all();
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
