#include <gtkmm.h>

using namespace Glib;
using namespace Gtk;

class WindowMain : public Window {
public:
  WindowMain() {
    add(scrolledWindow);
    scrolledWindow.add(fixed);
    
    button1.set_label("button1");
    button1.signal_button_release_event().connect([&](GdkEventButton*) {
      label1.set_text(ustring::compose("button1 clicked %1 times", ++button1Clicked));
      return true;
    });
    fixed.add(button1);
    fixed.move(button1, 50, 50);
    
    button2.set_label("button2");
    button2.set_size_request(200, 75);
    button2.signal_button_release_event().connect([&](GdkEventButton*) {
      label2.set_text(ustring::compose("button2 clicked %1 times", ++button2Clicked));
      return true;
    });
    fixed.add(button2);
    fixed.move(button2, 50, 100);

    label1.set_text(ustring::compose("button1 clicked %1 times", button1Clicked));
    fixed.add(label1);
    fixed.move(label1, 50, 200);
    
    label2.set_text(ustring::compose("button2 clicked %1 times", button2Clicked));
    fixed.add(label2);
    fixed.move(label2, 50, 230);
    
    set_title("Button example");
    resize(300, 300);
    show_all();
  }
  
private:
  Fixed fixed;
  ScrolledWindow scrolledWindow;
  Button button1;
  Button button2;
  Label label1;
  Label label2;
  int button1Clicked = 0;
  int button2Clicked = 0;
};

int main(int argc, char* argv[]) {
    g_object_set(gtk_settings_get_default(), "gtk-application-prefer-dark-theme", true, NULL);
    g_object_set(gtk_settings_get_default(), "gtk-button-images", true, NULL);
  //gtk_settings_set_long_property(gtk_settings_get_default(), "gtk-application-prefer-dark-theme", 0, nullptr);
  auto application = Application::create(argc, argv);
  WindowMain window;
  return application->run(window);
}
