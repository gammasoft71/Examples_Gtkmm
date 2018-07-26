#include <iostream>
#include <gtkmm.h>

using namespace Glib;
using namespace Gtk;

class Form : public Window {
public:
  Form() {
    this->add(this->scrolledWindow);
    this->scrolledWindow.add(this->fixed);
    
    this->button.set_label("Open...");
    this->fixed.add(this->button);
    this->fixed.child_property_x(this->button) = 10;
    this->fixed.child_property_y(this->button) = 10;
    this->button.signal_button_release_event().connect([&](GdkEventButton* event) {
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
        this->label.set_text(ustring::compose("File = %1", ustring(openFileDialog.get_filename())));
      return true;
    });

    this->label.set_text("File = ");
    this->fixed.add(this->label);
    this->fixed.child_property_x(this->label) = 10;
    this->fixed.child_property_y(this->label) = 50;

    this->set_title("OpenFileDialog example");
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
