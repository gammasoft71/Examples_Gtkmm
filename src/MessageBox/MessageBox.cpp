#include <iostream>
#include <gtkmm.h>

using namespace Glib;
using namespace Gtk;

class Form : public Window {
public:
  Form() {
    add(scrolledWindow);
    scrolledWindow.add(fixed);
    
    button.set_label("MessageBox");
    fixed.add(button);
    fixed.move(button, 10, 10);
    button.signal_button_release_event().connect([&](GdkEventButton* event) {
      MessageDialog messageBox(*this, "Hello, World!", true, MESSAGE_INFO, BUTTONS_OK_CANCEL, true);
      messageBox.set_title("Message");
      messageBox.set_modal();
      messageBox.set_position(WindowPosition::WIN_POS_CENTER);
      int result = messageBox.run();
      labelDialogResult.set_text(ustring::compose("DialogResult = %1", result == RESPONSE_OK ? "OK" : "Cancel"));
      return true;
    });

    labelDialogResult.set_text("");
    fixed.add(labelDialogResult);
    fixed.move(labelDialogResult, 10, 50);

    set_title("MessageBox example");
    resize(300, 300);
    show_all();
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
