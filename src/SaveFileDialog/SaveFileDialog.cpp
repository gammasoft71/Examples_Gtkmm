#include <iostream>
#include <gtkmm.h>

using namespace Glib;
using namespace Gtk;

class Form : public Window {
public:
  Form() {
    add(scrolledWindow);
    scrolledWindow.add(fixed);
    
    button.set_label("Save...");
    fixed.add(button);
    fixed.move(button, 10, 10);
    button.signal_button_release_event().connect([&](GdkEventButton* event) {
      FileChooserDialog saveFileDialog("", FILE_CHOOSER_ACTION_SAVE);
      saveFileDialog.add_button("Cancel", RESPONSE_CANCEL);
      saveFileDialog.add_button("Open", RESPONSE_OK);
      saveFileDialog.set_current_folder(ustring::compose("%1/Desktop", ustring(getenv("HOME"))));
      saveFileDialog.set_current_name("MyFile.txt");
      saveFileDialog.set_transient_for(*this);

      Glib::RefPtr<Gtk::FileFilter> fileFilter = Gtk::FileFilter::create();
      fileFilter->set_name("Text Files (*.txt)");
      fileFilter->add_pattern("*.txt");
      saveFileDialog.add_filter(fileFilter);
      fileFilter = Gtk::FileFilter::create();
      fileFilter->set_name("All Files (*.*)");
      fileFilter->add_pattern("*.*");
      saveFileDialog.add_filter(fileFilter);
      
      if (saveFileDialog.run() == RESPONSE_OK)
        label.set_text(ustring::compose("File = %1", ustring(saveFileDialog.get_filename())));
      return true;
    });

    label.set_text("File = ");
    fixed.add(label);
    fixed.move(label, 10, 50);

    set_title("SaveFileDialog example");
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
