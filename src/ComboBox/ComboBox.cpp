#include <iostream>
#include <gtkmm.h>

using namespace Glib;
using namespace Gtk;

class Form : public Window {
public:
  Form() {
    add(scrolledWindow);
    scrolledWindow.add(fixed);

    fixed.add(comboBox1);
    fixed.move(comboBox1, 10, 10);

    comboBox1.append("item1");
    comboBox1.append("item2");
    comboBox1.append("item3");
    comboBox1.set_active(1);

    set_title("ComboBox example");
    resize(300, 300);
    show_all();
  }
  
private:
  Fixed fixed;
  ScrolledWindow scrolledWindow;
  ComboBoxText comboBox1 {true};
};

int main(int argc, char* argv[]) {
  RefPtr<Application> application = Application::create(argc, argv);
  Form form;
  return application->run(form);
}
