#include <gtkmm.h>

using namespace Glib;
using namespace Gtk;

class Form : public Window {
public:
  Form() {
    this->add(this->scrolledWindow);
    this->scrolledWindow.add(this->fixed);
    
    this->fixed.add(this->comboBox1);
    this->fixed.child_property_x(this->comboBox1) = 10;
    this->fixed.child_property_y(this->comboBox1) = 10;
    this->comboBox1.set_size_request(121, 30);
    
    this->treeModelColumnRecord.add(this->treeModelColumnString);
    this->listStore = ListStore::create(this->treeModelColumnRecord);
    this->comboBox1.set_model(this->listStore);
    this->comboBox1.pack_start(this->treeModelColumnString);
    
    (*this->listStore->append())[this->treeModelColumnString] = "item1";
    (*this->listStore->append())[this->treeModelColumnString] = "item2";
    (*this->listStore->append())[this->treeModelColumnString] = "item3";
    
    this->comboBox1.set_active(1);
    
    this->set_title("ComboBox example");
    this->set_size_request(300, 300);
    this->show_all();
  }
  
private:
  Fixed fixed;
  ScrolledWindow scrolledWindow;
  ComboBox comboBox1;
  TreeModelColumn<ustring> treeModelColumnString;
  TreeModelColumnRecord treeModelColumnRecord;
  RefPtr<ListStore> listStore;
};

int main(int argc, char* argv[]) {
  RefPtr<Application> application = Application::create(argc, argv);
  Form form;
  return application->run(form);
}

// see https://developer.gnome.org/gtkmm-tutorial/stable/combobox-example-full.html.en for more information
