#include <iostream>
#include <gtkmm.h>

using namespace Glib;
using namespace Gtk;

class Form : public Window {
public:
  Form() {
    this->add(this->vbox);
    this->vbox.pack_start(this->menuBar, PACK_SHRINK);
    this->vbox.pack_end(this->scrolledWindow);
    this->scrolledWindow.add(this->fixed);
    
    this->menuFile.set_label("File");
    this->menuBar.append(menuFile);
    
    this->menuEdit.set_label("Edit");
    this->menuBar.append(menuEdit);
    
    this->menuView.set_label("View");
    this->menuBar.append(menuView);
    
    this->menuWindow.set_label("Window");
    this->menuBar.append(menuWindow);
    
    this->menuHelp.set_label("Help");
    this->menuBar.append(menuHelp);
    
    this->menuFile.set_submenu(subMenuFile);
    this->menuEdit.set_submenu(subMenuEdit);
    this->menuView.set_submenu(subMenuView);
    this->menuWindow.set_submenu(subMenuWindow);
    this->menuHelp.set_submenu(subMenuHelp);
    
    this->subMenuFile.append(this->menuFileNew);
    this->subMenuFile.append(this->menuFileOpen);
    this->subMenuFile.append(this->separator1);
    this->subMenuFile.append(this->menuFileClose);

    this->subMenuEdit.append(this->menuEditUndo);
    this->subMenuEdit.append(this->menuEditRedo);
    this->subMenuEdit.append(this->separator2);
    this->subMenuEdit.append(this->menuEditCut);
    this->subMenuEdit.append(this->menuEditCopy);
    this->subMenuEdit.append(this->menuEditPaste);
    this->subMenuEdit.append(this->menuEditDelete);
    this->subMenuEdit.append(this->separator3);
    this->subMenuEdit.append(this->menuEditSelectAll);

    this->menuFileNew.set_label("_New");
    this->menuFileNew.set_use_underline(true);
    this->menuFileNew.Gtk::Widget::add_accelerator("New", this->get_accel_group(), 'n', Gdk::CONTROL_MASK, Gtk::ACCEL_VISIBLE);
    this->menuFileNew.signal_activate().connect([&]() {
      std::cout << "MainMenu/File/New" << std::endl;
    });

    this->menuFileOpen.set_label("_Open");
    this->menuFileOpen.set_use_underline(true);
    this->menuFileOpen.signal_activate().connect([&]() {
      std::cout << "MainMenu/File/Open" << std::endl;
    });

    this->menuFileClose.set_label("_Close");
    this->menuFileClose.set_use_underline(true);
    this->menuFileClose.signal_activate().connect([&]() {
      std::cout << "MainMenu/File/Close" << std::endl;
    });
    
    this->menuEditUndo.set_label("_Undo");
    this->menuEditUndo.set_use_underline(true);
    this->menuEditUndo.signal_activate().connect([&]() {
      std::cout << "MainMenu/Edit/Undo" << std::endl;
    });
    
    this->menuEditRedo.set_label("_Redo");
    this->menuEditRedo.set_use_underline(true);
    this->menuEditRedo.signal_activate().connect([&]() {
      std::cout << "MainMenu/Edit/Redo" << std::endl;
    });
    
    this->menuEditCut.set_label("C_ut");
    this->menuEditCut.set_use_underline(true);
    this->menuEditCut.signal_activate().connect([&]() {
      std::cout << "MainMenu/Edit/Cut" << std::endl;
    });
    
    this->menuEditCopy.set_label("_Copy");
    this->menuEditCopy.set_use_underline(true);
    this->menuEditCopy.signal_activate().connect([&]() {
      std::cout << "MainMenu/Edit/Copy" << std::endl;
    });
    
    this->menuEditPaste.set_label("_Paste");
    this->menuEditPaste.set_use_underline(true);
    this->menuEditPaste.signal_activate().connect([&]() {
      std::cout << "MainMenu/Edit/Paste" << std::endl;
    });
    
    this->menuEditDelete.set_label("_Delete");
    this->menuEditDelete.set_use_underline(true);
    this->menuEditDelete.signal_activate().connect([&]() {
      std::cout << "MainMenu/Edit/Delete" << std::endl;
    });
    
    this->menuEditSelectAll.set_label("Select _All");
    this->menuEditSelectAll.set_use_underline(true);
    this->menuEditSelectAll.signal_activate().connect([&]() {
      std::cout << "MainMenu/Edit/SelectAll" << std::endl;
    });

    this->set_title("MainMenu example");
    this->set_size_request(300, 300);
    this->show_all();
  }
  
private:
  VBox vbox;
  Fixed fixed;
  ScrolledWindow scrolledWindow;
  MenuBar menuBar;
  MenuItem menuFile;
  MenuItem menuEdit;
  MenuItem menuView;
  MenuItem menuWindow;
  MenuItem menuHelp;
  
  Menu subMenuFile;
  Menu subMenuEdit;
  Menu subMenuView;
  Menu subMenuWindow;
  Menu subMenuHelp;

  MenuItem menuFileNew;
  SeparatorMenuItem separator1;
  MenuItem menuFileOpen;
  MenuItem menuFileClose;

  MenuItem menuEditUndo;
  MenuItem menuEditRedo;
  SeparatorMenuItem separator2;
  MenuItem menuEditCut;
  MenuItem menuEditCopy;
  MenuItem menuEditPaste;
  MenuItem menuEditDelete;
  SeparatorMenuItem separator3;
  MenuItem menuEditSelectAll;
};

int main(int argc, char* argv[]) {
  RefPtr<Application> application = Application::create(argc, argv);
  Form form;
  return application->run(form);
}
