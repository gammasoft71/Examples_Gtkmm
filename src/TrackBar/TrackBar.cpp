#include <gtkmm.h>

using namespace Glib;
using namespace Gtk;

class Form : public Window {
public:
  Form() {
    this->add(this->scrolledWindow);
    this->scrolledWindow.add(this->fixed);

    this->fixed.add(this->trackBar);
    this->fixed.child_property_x(this->trackBar) = 20;
    this->fixed.child_property_y(this->trackBar) = 50;
    this->trackBar.set_size_request(200, 10);
    this->trackBar.set_range(0.0, 200.0);
    this->trackBar.set_draw_value(false);
    this->trackBar.signal_value_changed().connect([&] {
      this->progressBar.set_fraction(this->trackBar.get_value() / 200.0);
      this->label.set_text(ustring::compose("%1", (int)this->trackBar.get_value()));
    });
    this->trackBar.set_value(100);

    this->fixed.add(this->progressBar);
    this->fixed.child_property_x(this->progressBar) = 20;
    this->fixed.child_property_y(this->progressBar) = 100;
    this->progressBar.set_size_request(200, 10);

    this->fixed.add(this->label);
    this->fixed.child_property_x(this->label) = 20;
    this->fixed.child_property_y(this->label) = 150;
    
    this->set_title("Label example");
    this->set_size_request(300, 300);
    this->show_all();
  }
  
private:
  Fixed fixed;
  ScrolledWindow scrolledWindow;
  Scale trackBar {ORIENTATION_HORIZONTAL};
  ProgressBar progressBar;
  Label label;
};

int main(int argc, char* argv[]) {
  RefPtr<Application> application = Application::create(argc, argv);
  Form form;
  return application->run(form);
}
