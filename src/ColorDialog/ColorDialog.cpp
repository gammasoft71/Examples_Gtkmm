#include <gtkmm.h>

using namespace Glib;
using namespace Gtk;

class WindowMain : public Window {
public:
  WindowMain() {
    add(scrolledWindow);
    scrolledWindow.add(fixed);
    
    button.set_label("Color...");
    fixed.add(button);
    fixed.move(button, 10, 10);
    button.signal_button_release_event().connect([&](GdkEventButton*) {
      ColorChooserDialog colorDialog("");
      colorDialog.set_rgba(get_style_context()->get_background_color());
      colorDialog.set_transient_for(*this);
      colorDialog.set_modal(true);
      if (colorDialog.run() == RESPONSE_OK)
        override_background_color(colorDialog.get_rgba());
      return true;
    });

    
    set_title("ColorDialog example");
    resize(300, 300);
    show_all();
  }
  
private:
  Fixed fixed;
  ScrolledWindow scrolledWindow;
  Button button;
};

int main(int argc, char* argv[]) {
  auto application = Application::create(argc, argv);
  WindowMain window;
  return application->run(window);
}
