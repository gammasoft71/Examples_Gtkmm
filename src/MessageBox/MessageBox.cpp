#include <iostream>
#include <gtkmm.h>

using namespace Glib;
using namespace Gtk;

class Form : public Window {
public:
  Form() {
    this->add(this->scrolledWindow);
    this->scrolledWindow.add(this->fixed);
    
    this->button.set_label("MessageBox");
    this->fixed.add(this->button);
    this->fixed.child_property_x(this->button) = 10;
    this->fixed.child_property_y(this->button) = 10;
    this->button.signal_button_release_event().connect([&](GdkEventButton* event) {
      MessageDialog messageBox(*this, "Hello, World!", true, MESSAGE_INFO, BUTTONS_OK_CANCEL, true);
      messageBox.set_title("Message");
      messageBox.set_modal();
      messageBox.set_position(WindowPosition::WIN_POS_CENTER);
      int result = messageBox.run();
      labelDialogResult.set_text(ustring::compose("DialogResult = %1", result == RESPONSE_OK ? "OK" : "Cancel"));
      return true;
    });

    this->labelDialogResult.set_text("");
    this->fixed.add(this->labelDialogResult);
    this->fixed.child_property_x(this->labelDialogResult) = 10;
    this->fixed.child_property_y(this->labelDialogResult) = 50;

    this->set_title("MessageBox example");
    this->set_size_request(300, 300);
    this->show_all();
  }
  
private:
  Fixed fixed;
  ScrolledWindow scrolledWindow;
  Button button;
  Label labelDialogResult;
};

int main(int argc, char* argv[]) {
  RefPtr<Application> application = Application::create(argc, argv);
  Form form;
  return application->run(form);
}
