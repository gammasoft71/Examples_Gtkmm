#include <iomanip>
#include <gtkmm.h>

using namespace Glib;
using namespace Gtk;

class Form : public Window {
public:
  Form() {
    add(scrolledWindow);
    scrolledWindow.add(fixed);
    
    label.set_text(ustring::format(std::fixed, std::setprecision(1), (double)counter / 10));
    label.override_color(Gdk::RGBA("#1E90FF"));
    Pango::FontDescription textFont("Arial");
    textFont.set_size(48 * PANGO_SCALE);
    textFont.set_style(Pango::Style::STYLE_ITALIC);
    textFont.set_weight(Pango::Weight::WEIGHT_BOLD);
    label.override_font(textFont);
    fixed.add(label);
    fixed.move(label, 10, 10);

    button.set_label("Start");
    fixed.add(button);
    fixed.move(button, 10, 90);
    button.signal_button_release_event().connect([&](GdkEventButton* event) {
      enableTimer = !enableTimer;
      button.set_label(enableTimer ? "Stop" : "Start");
      if (enableTimer) {
        signal_timeout().connect([&] {
          label.set_text(ustring::format(std::fixed, std::setprecision(1), (double)++counter / 10));
          return enableTimer;
        }, 100);
      }
      return true;
    });

    set_title("Timer example");
    resize(230, 130);
    show_all();
  }
  
private:
  Fixed fixed;
  ScrolledWindow scrolledWindow;
  Label label;
  Button button;
  bool enableTimer = false;
  int counter = 0;
};

int main(int argc, char* argv[]) {
  RefPtr<Application> application = Application::create(argc, argv);
  Form form;
  return application->run(form);
}
