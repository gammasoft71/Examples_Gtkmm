#include <iostream>
#include <gtkmm.h>

using namespace Glib;
using namespace Gtk;

class Form : public Window {
public:
  Form() {
    add(scrolledWindow);
    scrolledWindow.add(fixed);
    
    button.set_label("Open...");
    fixed.add(button);
    fixed.move(button, 10, 10);
    button.signal_button_release_event().connect([&](GdkEventButton* event) {
      FileChooserDialog openFileDialog("", FILE_CHOOSER_ACTION_OPEN);
      openFileDialog.add_button("Cancel", RESPONSE_CANCEL);
      openFileDialog.add_button("Open", RESPONSE_OK);
      openFileDialog.set_current_folder(ustring::compose("%1/Desktop", ustring(getenv("HOME"))));
      openFileDialog.set_transient_for(*this);

      Glib::RefPtr<Gtk::FileFilter> fileFilter = Gtk::FileFilter::create();
      fileFilter->set_name("Text Files (*.txt)");
      fileFilter->add_pattern("*.txt");
      openFileDialog.add_filter(fileFilter);
      fileFilter = Gtk::FileFilter::create();
      fileFilter->set_name("All Files (*.*)");
      fileFilter->add_pattern("*.*");
      openFileDialog.add_filter(fileFilter);
      
      if (openFileDialog.run() == RESPONSE_OK)
        label.set_text(ustring::compose("File = %1", ustring(openFileDialog.get_filename())));
      return true;
    });

    label.set_text("File = ");
    fixed.add(label);
    fixed.move(label, 10, 50);

    set_title("OpenFileDialog example");
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
    g_object_set(gtk_settings_get_default(), "gtk-button-images", true, NULL);
  RefPtr<Application> application = Application::create(argc, argv);
  Form form;
  return application->run(form);
}
