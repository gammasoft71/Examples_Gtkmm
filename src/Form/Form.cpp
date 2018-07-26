#include <gtkmm.h>

using namespace Gtk;

class Form : public Window {
public:
  Form() {
    this->scrolledWindow.add(this->fixed);
    
    this->button.set_label("Close");
    this->button.signal_button_release_event().connect([&](GdkEventButton* event) {
      this->close();
      return true;
    });
    this->fixed.add(this->button);
    this->fixed.child_property_x(this->button) = 10;
    this->fixed.child_property_y(this->button) = 10;

    this->set_title("Form Example");
    this->move(320, 200);
    this->resize(640, 480);
    this->add(this->scrolledWindow);
    this->show_all();
  }

  bool on_delete_event(GdkEventAny* any_event) override {
    MessageDialog dialog(*this, "Are you sure you want exit?", true, MESSAGE_QUESTION, BUTTONS_YES_NO, true);
    dialog.set_title("Close Form");
    dialog.set_modal();
    dialog.set_position(WindowPosition::WIN_POS_CENTER);
    if (dialog.run() == RESPONSE_YES)
      return this->Window::on_delete_event(any_event);
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
