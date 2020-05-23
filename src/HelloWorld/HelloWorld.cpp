#include <gtkmm.h>

using namespace Glib;
using namespace Gtk;

class Form : public Window {
public:
  Form() {
    add(scrolledWindow);
    scrolledWindow.add(fixed);
    
    label1.set_text("Hello, World!");
    label1.override_color(Gdk::RGBA("#008000"));
    Pango::FontDescription textFont;
    textFont.set_family("Arial");
    textFont.set_size(34 * PANGO_SCALE);
    textFont.set_style(Pango::Style::STYLE_ITALIC);
    textFont.set_weight(Pango::Weight::WEIGHT_BOLD);
    label1.override_font(textFont);
    fixed.add(label1);
    fixed.move(label1, 5, 100);
    
    set_title("My first application");
    resize(300, 300);
    show_all();
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
