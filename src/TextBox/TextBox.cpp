#include <gtkmm.h>

using namespace Glib;
using namespace Gtk;

class Form : public Window {
public:
  Form() {
    add(scrolledWindow);
    scrolledWindow.add(fixed);

    textBox1.set_text("textBox1");
    fixed.add(textBox1);
    fixed.move(textBox1, 10, 10);

    textBox2.set_text("textBox2");
    fixed.add(textBox2);
    fixed.move(textBox2, 10, 50);

    set_title("TextBox example");
    resize(300, 300);
    show_all();
  }
  
private:
  Fixed fixed;
  ScrolledWindow scrolledWindow;
  Entry textBox1;
  Entry textBox2;
};

int main(int argc, char* argv[]) {
  RefPtr<Application> application = Application::create(argc, argv);
  Form form;
  return application->run(form);
}
