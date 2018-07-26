#include <gtkmm.h>

using namespace Glib;
using namespace Gtk;

class Form : public Window {
public:
  Form() {
    this->add(this->scrolledWindow);
    this->scrolledWindow.add(this->fixed);
    
    this->label1.set_text("Hello, World!");
    this->label1.override_color(Gdk::RGBA("#008000"));
    Pango::FontDescription textFont;
    textFont.set_family("Arial");
    textFont.set_size(34 * PANGO_SCALE);
    textFont.set_style(Pango::Style::STYLE_ITALIC);
    textFont.set_weight(Pango::Weight::WEIGHT_BOLD);
    this->label1.override_font(textFont);
    this->fixed.add(this->label1);
    this->fixed.move(this->label1, 5, 100);
    
    this->set_title("My first application");
    this->resize(300, 300);
    this->show_all();
  }
  
private:
  Fixed fixed;
  ScrolledWindow scrolledWindow;
  Label label1;
};

int main(int argc, char* argv[]) {
  RefPtr<Application> application = Application::create(argc, argv);
  Form form;
  return application->run(form);
}
