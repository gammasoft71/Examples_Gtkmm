#include <iomanip>
#include <gtkmm.h>

using namespace Glib;
using namespace Gtk;

class Form : public Window {
public:
  Form() {
    this->add(this->scrolledWindow);
    this->scrolledWindow.add(this->fixed);
    
    this->label.set_text(ustring::format(std::fixed, std::setprecision(1), (double)this->counter / 10));
    this->label.override_color(Gdk::RGBA("#1E90FF"));
    Pango::FontDescription textFont("Arial");
    textFont.set_size(48 * PANGO_SCALE);
    textFont.set_style(Pango::Style::STYLE_ITALIC);
    textFont.set_weight(Pango::Weight::WEIGHT_BOLD);
    this->label.override_font(textFont);
    this->fixed.add(this->label);
    this->fixed.move(this->label, 10, 10);

    this->button.set_label("Start");
    this->fixed.add(this->button);
    this->fixed.move(this->button, 10, 90);
    this->button.signal_button_release_event().connect([&](GdkEventButton* event) {
      this->enableTimer = !this->enableTimer;
      this->button.set_label(this->enableTimer ? "Stop" : "Start");
      if (this->enableTimer) {
        signal_timeout().connect([&] {
          this->label.set_text(ustring::format(std::fixed, std::setprecision(1), (double)++this->counter / 10));
          return this->enableTimer;
        }, 100);
      }
      return true;
    });

    this->set_title("Timer example");
    this->resize(230, 130);
    this->show_all();
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
