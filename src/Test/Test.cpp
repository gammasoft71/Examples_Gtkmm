#include <gtkmm.h>

using namespace Glib;
using namespace Gtk;

class Form : public Window {
public:
  Form() {
    this->add(this->fixed);
    this->fixed.add(this->vbox);
    this->fixed.move(this->vbox, 30 , 10);
    this->vbox.pack_start(this->hbox);

    this->button.set_label("Button");
    this->button.set_size_request(50, 10);
    this->hbox.pack_start(this->button);
    
    this->set_title("Test");
    this->resize(300, 300);
    this->show_all();
  }
  
private:
  Layout fixed;
  VBox vbox;
  HBox hbox;
  Button button;
};

int main(int argc, char* argv[]) {
  RefPtr<Application> application = Application::create(argc, argv);
  Form form;
  return application->run(form);
}
