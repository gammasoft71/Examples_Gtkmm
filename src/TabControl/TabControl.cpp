#include <iostream>
#include <gtkmm.h>

using namespace Glib;
using namespace Gtk;

class Form : public Window {
public:
  Form() {
    this->add(this->scrolledWindow);
    this->scrolledWindow.add(this->fixed);
    
    tabControl1.set_size_request(370, 250);
    fixed.add(tabControl1);
    fixed.child_property_x(tabControl1) = 10;
    fixed.child_property_y(tabControl1) = 10;

    tabControl1.insert_page(pageTab1, "tabPage1", 0);
    tabControl1.insert_page(pageTab2, "tabPage2", 1);
    tabControl1.insert_page(pageTab3, "tabPage3", 2);

    this->set_title("TabControl example");
    this->set_size_request(390, 270);
    this->show_all();
  }
  
private:
  Fixed fixed;
  ScrolledWindow scrolledWindow;
  Notebook tabControl1;
  Frame pageTab1;
  Frame pageTab2;
  Frame pageTab3;
};

int main(int argc, char* argv[]) {
  RefPtr<Application> application = Application::create(argc, argv);
  Form form;
  return application->run(form);
}
