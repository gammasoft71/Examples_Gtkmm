#include <gtkmm.h>

using namespace Gtk;

class Form : public Window {
public:
  Form() {
    scrolledWindow.add(fixed);
    
    button.set_label("Close");
    button.signal_button_release_event().connect([&](GdkEventButton* event) {
      close();
      return true;
    });
    fixed.add(button);
    fixed.move(button, 10, 10);

    set_title("Form Example");
    move(320, 200);
    resize(640, 480);
    add(scrolledWindow);
    show_all();
  }

  bool on_delete_event(GdkEventAny* any_event) override {
    MessageDialog dialog(*this, "Are you sure you want exit?", true, MESSAGE_QUESTION, BUTTONS_YES_NO, true);
    dialog.set_title("Close Form");
    dialog.set_modal();
    dialog.set_position(WindowPosition::WIN_POS_CENTER);
    if (dialog.run() == RESPONSE_YES)
      return Window::on_delete_event(any_event);
    return true;
  }
  
private:
  ScrolledWindow scrolledWindow;
  Fixed fixed;
  Button button;
};

int main(int argc, char* argv[]) {
  Glib::RefPtr<Application> application = Application::create(argc, argv);
  Form form;
  return application->run(form);
}
