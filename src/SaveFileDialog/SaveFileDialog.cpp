#include <iostream>
#include <gtkmm.h>

using namespace Glib;
using namespace Gtk;

class Form : public Window {
public:
  Form() {
    this->add(this->scrolledWindow);
    this->scrolledWindow.add(this->fixed);
    
    this->button.set_label("Save...");
    this->fixed.add(this->button);
    this->fixed.move(this->button, 10, 10);
    this->button.signal_button_release_event().connect([&](GdkEventButton* event) {
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
        this->label.set_text(ustring::compose("File = %1", ustring(saveFileDialog.get_filename())));
      return true;
    });

    this->label.set_text("File = ");
    this->fixed.add(this->label);
    this->fixed.move(this->label, 10, 50);

    this->set_title("SaveFileDialog example");
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
