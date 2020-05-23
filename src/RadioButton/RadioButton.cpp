#include <gtkmm.h>

using namespace Glib;
using namespace Gtk;

class Form : public Window {
public:
  Form() {
    add(scrolledWindow);
    scrolledWindow.add(fixed);
    
    radioButton1.set_label("radioButton 1");
    radioButton1.set_active(true);
    radioButton1.set_group(radioButtonGroup1);
    fixed.add(radioButton1);
    fixed.move(radioButton1, 30, 30);
    
    radioButton2.set_label("radioButton 2");
    radioButton2.set_group(radioButtonGroup1);
    fixed.add(radioButton2);
    fixed.move(radioButton2, 30, 60);
    
    radioButton3.set_label("radioButton 3");
    radioButton3.set_group(radioButtonGroup1);
    fixed.add(radioButton3);
    fixed.move(radioButton3, 30, 90);

    set_title("RadioButton example");
    resize(300, 300);
    show_all();
  }
  
private:
  Fixed fixed;
  ScrolledWindow scrolledWindow;
  RadioButtonGroup radioButtonGroup1;
  RadioButton radioButton1;
  RadioButton radioButton2;
  RadioButton radioButton3;
};

int main(int argc, char* argv[]) {
  RefPtr<Application> application = Application::create(argc, argv);
  Form form;
  return application->run(form);
}
