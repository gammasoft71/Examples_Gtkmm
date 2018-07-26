#include <iostream>
#include <gtkmm.h>

using namespace Glib;
using namespace Gtk;

class Form : public Window {
public:
  Form() {
    this->add(this->scrolledWindow);
    this->scrolledWindow.add(this->fixed);
    
    this->button.set_label("Folder...");
    this->fixed.add(this->button);
    this->fixed.child_property_x(this->button) = 10;
    this->fixed.child_property_y(this->button) = 10;
    this->button.signal_button_release_event().connect([&](GdkEventButton* event) {
      FileChooserDialog folderBrowserDialog("", FILE_CHOOSER_ACTION_SELECT_FOLDER);
      folderBrowserDialog.add_button("Cancel", RESPONSE_CANCEL);
      folderBrowserDialog.add_button("Open", RESPONSE_OK);
      folderBrowserDialog.set_current_folder(ustring::compose("%1/Desktop", ustring(getenv("HOME"))));
      folderBrowserDialog.set_transient_for(*this);
      if (folderBrowserDialog.run() == RESPONSE_OK)
        this->label.set_text(ustring::compose("Path = %1", ustring(folderBrowserDialog.get_current_folder())));
      return true;
    });

    this->label.set_text("Path = ");
    this->fixed.add(this->label);
    this->fixed.child_property_x(this->label) = 10;
    this->fixed.child_property_y(this->label) = 50;

    this->set_title("FolderBrowserDialog example");
    this->resize(300, 300);
    this->show_all();
  }
  
private:
  Fixed fixed;
  ScrolledWindow scrolledWindow;
  Button button;
  Label label;
};

int main(int argc, char* argv[]) {
  RefPtr<Application> application = Application::create(argc, argv);
  Form form;
  return application->run(form);
}
