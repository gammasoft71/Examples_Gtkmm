#include <iostream>
#include <gtkmm.h>

using namespace Glib;
using namespace Gtk;

class Form : public Window {
public:
  Form() {
    add(scrolledWindow);
    scrolledWindow.add(fixed);
    
    button.set_label("Folder...");
    fixed.add(button);
    fixed.move(button, 10, 10);
    button.signal_button_release_event().connect([&](GdkEventButton* event) {
      FileChooserDialog folderBrowserDialog("", FILE_CHOOSER_ACTION_SELECT_FOLDER);
      folderBrowserDialog.add_button("Cancel", RESPONSE_CANCEL);
      folderBrowserDialog.add_button("Open", RESPONSE_OK);
      folderBrowserDialog.set_current_folder(ustring::compose("%1/Desktop", ustring(getenv("HOME"))));
      folderBrowserDialog.set_transient_for(*this);
      if (folderBrowserDialog.run() == RESPONSE_OK)
        label.set_text(ustring::compose("Path = %1", ustring(folderBrowserDialog.get_current_folder())));
      return true;
    });

    label.set_text("Path = ");
    fixed.add(label);
    fixed.move(label, 10, 50);

    set_title("FolderBrowserDialog example");
    resize(300, 300);
    show_all();
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
