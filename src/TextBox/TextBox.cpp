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
    this->fixed.move(this->textBox1, 10, 10);

    this->textBox2.set_text("textBox2");
    this->fixed.add(this->textBox2);
    this->fixed.move(this->textBox2, 10, 50);

    this->set_title("TextBox example");
    this->resize(300, 300);
    this->show_all();
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
