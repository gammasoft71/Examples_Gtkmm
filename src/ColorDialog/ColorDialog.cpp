#include <gtkmm.h>

using namespace Glib;
using namespace Gtk;

class Form : public Window {
public:
  Form() {
    this->add(this->scrolledWindow);
    this->scrolledWindow.add(this->fixed);
    
    this->button.set_label("Color...");
    this->fixed.add(this->button);
    this->fixed.child_property_x(this->button) = 10;
    this->fixed.child_property_y(this->button) = 10;
    this->button.signal_button_release_event().connect([&](GdkEventButton* event) {
      ColorChooserDialog colorDialog("");
      colorDialog.set_rgba(this->get_style_context()->get_background_color());
      colorDialog.set_transient_for(*this);
      colorDialog.set_modal(true);
      if (colorDialog.run() == RESPONSE_OK)
        this->override_background_color(colorDialog.get_rgba());
      return true;
    });

    
    this->set_title("ColorDialog example");
    this->resize(300, 300);
    this->show_all();
  }
  
private:
  Fixed fixed;
  ScrolledWindow scrolledWindow;
  Button button;
};

int main(int argc, char* argv[]) {
  RefPtr<Application> application = Application::create(argc, argv);
  Form form;
  return application->run(form);
}
