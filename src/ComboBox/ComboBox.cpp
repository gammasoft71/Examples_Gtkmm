#include <iostream>
#include <gtkmm.h>

using namespace Glib;
using namespace Gtk;

class Form : public Window {
public:
  Form() {
    this->add(this->scrolledWindow);
    this->scrolledWindow.add(this->fixed);

    this->fixed.add(this->comboBox1);
    this->fixed.move(this->comboBox1, 10, 10);

    this->comboBox1.append("item1");
    this->comboBox1.append("item2");
    this->comboBox1.append("item3");
    this->comboBox1.set_active(1);

    this->set_title("ComboBox example");
    this->resize(300, 300);
    this->show_all();
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
