#include <gtkmm.h>

using namespace Glib;
using namespace Gtk;

class Form : public Window {
public:
  Form() {
    add(scrolledWindow);
    scrolledWindow.add(fixed);

    fixed.add(trackBar);
    fixed.move(trackBar, 20, 50);
    trackBar.set_size_request(200, 10);
    trackBar.set_range(0.0, 200.0);
    trackBar.set_draw_value(false);
    trackBar.signal_value_changed().connect([&] {
      progressBar.set_fraction(trackBar.get_value() / 200.0);
      label.set_text(ustring::compose("%1", (int)trackBar.get_value()));
    });
    trackBar.set_value(100);

    fixed.add(progressBar);
    fixed.move(progressBar, 20, 100);
    progressBar.set_size_request(200, 10);

    fixed.add(label);
    fixed.move(label, 20, 150);
    
    set_title("TrackBar example");
    resize(300, 300);
    show_all();
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
