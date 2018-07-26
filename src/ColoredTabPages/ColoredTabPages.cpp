#include <iostream>
#include <gtkmm.h>

using namespace Glib;
using namespace Gtk;

class Form : public Window {
public:
  Form() {
    this->add(this->scrolledWindow);
    this->scrolledWindow.add(this->fixed);
    
    this->tabControl1.set_size_request(370, 250);
    fixed.add(this->tabControl1);
    fixed.child_property_x(this->tabControl1) = 10;
    fixed.child_property_y(this->tabControl1) = 10;

    this->tabControl1.insert_page(this->tabPageRed, "Red", 0);
    this->tabControl1.insert_page(this->tabPageGreen, "Green", 1);
    this->tabControl1.insert_page(this->tabPageBlue, "Blue", 2);
    this->tabControl1.insert_page(this->tabPageYellow, "Yellow", 3);
    
    this->tabPageRed.override_background_color(Gdk::RGBA("#FF0000"));
    this->tabPageGreen.override_background_color(Gdk::RGBA("#008000"));
    this->tabPageBlue.override_background_color(Gdk::RGBA("#0000FF"));
    this->tabPageYellow.override_background_color(Gdk::RGBA("#FFFF00"));

    this->set_title("TabControl example");
    this->set_size_request(390, 270);
    this->show_all();
  }
  
private:
  Fixed fixed;
  ScrolledWindow scrolledWindow;
  Notebook tabControl1;
  Frame tabPageRed;
  Frame tabPageGreen;
  Frame tabPageBlue;
  Frame tabPageYellow;
};

int main(int argc, char* argv[]) {
  RefPtr<Application> application = Application::create(argc, argv);
  Form form;
  return application->run(form);
}
