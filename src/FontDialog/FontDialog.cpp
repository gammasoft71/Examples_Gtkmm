#include <iostream>
#include <gtkmm.h>

using namespace Glib;
using namespace Gtk;

class Form : public Window {
public:
  Form() {
    this->add(this->scrolledWindow);
    this->scrolledWindow.add(this->fixed);
    
    this->button.set_label("Font...");
    this->fixed.add(this->button);
    this->fixed.child_property_x(this->button) = 10;
    this->fixed.child_property_y(this->button) = 10;
    this->button.signal_button_release_event().connect([&](GdkEventButton* event) {
      Gtk::FontChooserDialog fontDialog("");
      fontDialog.set_transient_for(*this);
      fontDialog.set_font_desc(this->label.get_style_context()->get_font());
      if (fontDialog.run() == RESPONSE_OK)
        this->label.override_font(fontDialog.get_font_desc());
      return true;
    });

    this->label.set_text("The quick brown fox jumps over the lazy dog.\n"
                         "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG.\n"
                         "0123456789+-*/%~^&|=<>≤≥±÷≠{{[()]}},;:.?¿!¡\n"
                         "àçéèêëïî@@°_#§$ù£€æœøπµ©®∞\\\"'\n"
                         "\u0400{u0401\u0402\u0403\u0404\u0405\u0406\u0407\u0408\u0409\u040a\u040b\u040c\u040d\u040e\u040f\n"
                         "\u0410\u0411\u0412\u0413\u0414\u0415\u0416\u0417\u0418\u0419\u041a\u041b\u041c\u041d\u041e\u041f\n"
                         "\u4ea0\u4ea1\u4ea2\u4ea3\u4ea4\u4ea5\u4ea6\u4ea7\u4ea8\u4ea9\u4eaa\u4eab\u4eac\u4ead\u4eae\u4eaf\n"
                         "\u4eb0\u4eb1\u4eb2\u4eb3\u4eb4\u4eb5\u4eb6\u4eb7\u4eb8\u4eb9\u4eba\u4ebb\u4ebc\u4ebd\u4ebe\u4ebf\n"
                         "\U0001F428");
    this->fixed.add(this->label);
    this->fixed.child_property_x(this->label) = 10;
    this->fixed.child_property_y(this->label) = 50;

    this->set_title("FontDialog example");
    this->set_size_request(400, 400);
    this->show_all();
  }
  
private:
  Fixed fixed;
  ScrolledWindow scrolledWindow;
  Button button;
  Label label;
};

int main(int argc, char* argv[]) {
  RefPtr<Application> application = Application::create(argc, argv);
  Form form;
  return application->run(form);
}
