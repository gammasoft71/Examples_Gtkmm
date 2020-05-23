#include <gtkmm.h>

using namespace Glib;
using namespace Gtk;

class WindowMain : public Window {
public:
  WindowMain() {
    add(scrolledWindow);
    scrolledWindow.add(fixed);
    
    checkBox1.set_label("Checked");
    checkBox1.set_active(true);
    fixed.add(checkBox1);
    fixed.move(checkBox1, 30, 30);
    
    checkBox2.set_label("Unchecked");
    checkBox2.set_active(false);
    fixed.add(checkBox2);
    fixed.move(checkBox2, 30, 60);
    
    checkBox3.set_label("Indeterminate");
    checkBox3.set_active(true);
    checkBox3.set_inconsistent(true);
    fixed.add(checkBox3);
    fixed.move(checkBox3, 30, 90);

    set_title("CheckBox example");
    resize(300, 300);
    show_all();
  }
  
private:
  Fixed fixed;
  ScrolledWindow scrolledWindow;
  CheckButton checkBox1;
  CheckButton checkBox2;
  CheckButton checkBox3;
};

int main(int argc, char* argv[]) {
  auto application = Application::create(argc, argv);
  WindowMain window;
  return application->run(window);
}
