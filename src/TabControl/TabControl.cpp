#include <iostream>
#include <gtkmm.h>

using namespace Glib;
using namespace Gtk;

class Form : public Window {
public:
  Form() {
    this->add(this->scrolledWindow);
    this->scrolledWindow.add(this->fixed);
    
    this->tabControl1.set_size_request(370, 250);
    this->fixed.add(this->tabControl1);
    this->fixed.child_property_x(this->tabControl1) = 10;
    this->fixed.child_property_y(this->tabControl1) = 10;

    this->tabControl1.insert_page(this->pageTab1, "tabPage1", 0);
    this->tabControl1.insert_page(this->pageTab2, "tabPage2", 1);
    this->tabControl1.insert_page(this->pageTab3, "tabPage3", 2);

    this->labelPage1.set_label("labelTabPage1");

    this->tabControl1.set_tab_label(this->pageTab1, this->labelPage1);

    this->pageTab1.add(this->fixedTabPage1);

    this->fixedTabPage1.add(this->radioTop);
    this->fixedTabPage1.child_property_x(this->radioTop) = 10;
    this->fixedTabPage1.child_property_y(this->radioTop) = 10;
    this->radioTop.set_label("Top");
    this->radioTop.set_group(this->radioButtonGroup);
    this->radioTop.signal_toggled().connect([this]() {
       this->tabControl1.set_tab_pos(PositionType::POS_TOP);
    });

    this->fixedTabPage1.add(this->radioLeft);
    this->fixedTabPage1.child_property_x(this->radioLeft) = 10;
    this->fixedTabPage1.child_property_y(this->radioLeft) = 40;
    this->radioLeft.set_label("Leff");
    this->radioLeft.set_group(this->radioButtonGroup);
    this->radioLeft.signal_toggled().connect([this]() {
      this->tabControl1.set_tab_pos(PositionType::POS_LEFT);
    });

    this->fixedTabPage1.add(this->radioRight);
    this->fixedTabPage1.child_property_x(this->radioRight) = 10;
    this->fixedTabPage1.child_property_y(this->radioRight) = 70;
    this->radioRight.set_label("Right");
    this->radioRight.set_group(this->radioButtonGroup);
    this->radioRight.signal_toggled().connect([this]() {
      this->tabControl1.set_tab_pos(PositionType::POS_RIGHT);
    });

    this->fixedTabPage1.add(this->radioBottom);
    this->fixedTabPage1.child_property_x(this->radioBottom) = 10;
    this->fixedTabPage1.child_property_y(this->radioBottom) = 100;
    this->radioBottom.set_label("Bottom");
    this->radioBottom.set_group(this->radioButtonGroup);
    this->radioBottom.signal_toggled().connect([this]() {
      this->tabControl1.set_tab_pos(PositionType::POS_BOTTOM);
    });

    this->set_title("TabControl example");
    this->resize(390, 270);
    this->show_all();
  }
  
private:
  Fixed fixed;
  ScrolledWindow scrolledWindow;
  Notebook tabControl1;
  Label labelPage1;
  Frame pageTab1;
  Frame pageTab2;
  Frame pageTab3;
  RadioButtonGroup radioButtonGroup;
  RadioButton radioTop;
  RadioButton radioLeft;
  RadioButton radioRight;
  RadioButton radioBottom;
  Fixed fixedTabPage1;
};

int main(int argc, char* argv[]) {
  RefPtr<Application> application = Application::create(argc, argv);
  Form form;
  return application->run(form);
}
