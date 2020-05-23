#include <iostream>
#include <gtkmm.h>

using namespace Glib;
using namespace Gtk;

class Form : public Window {
public:
  Form() {
    add(vbox);
    vbox.pack_start(menuBar, PACK_SHRINK);
    vbox.pack_end(scrolledWindow);
    scrolledWindow.add(fixed);
    
    menuFile.set_label("File");
    menuBar.append(menuFile);
    
    menuEdit.set_label("Edit");
    menuBar.append(menuEdit);
    
    menuView.set_label("View");
    menuBar.append(menuView);
    
    menuWindow.set_label("Window");
    menuBar.append(menuWindow);
    
    menuHelp.set_label("Help");
    menuBar.append(menuHelp);
    
    menuFile.set_submenu(subMenuFile);
    menuEdit.set_submenu(subMenuEdit);
    menuView.set_submenu(subMenuView);
    menuWindow.set_submenu(subMenuWindow);
    menuHelp.set_submenu(subMenuHelp);
    
    subMenuFile.append(menuFileNew);
    subMenuFile.append(menuFileOpen);
    subMenuFile.append(separator1);
    subMenuFile.append(menuFileClose);

    subMenuEdit.append(menuEditUndo);
    subMenuEdit.append(menuEditRedo);
    subMenuEdit.append(separator2);
    subMenuEdit.append(menuEditCut);
    subMenuEdit.append(menuEditCopy);
    subMenuEdit.append(menuEditPaste);
    subMenuEdit.append(menuEditDelete);
    subMenuEdit.append(separator3);
    subMenuEdit.append(menuEditSelectAll);

    menuFileNew.set_label("_New");
    menuFileNew.set_use_underline(true);
    menuFileNew.Gtk::Widget::add_accelerator("New", get_accel_group(), 'n', Gdk::CONTROL_MASK, Gtk::ACCEL_VISIBLE);
    menuFileNew.signal_activate().connect([&]() {
      std::cout << "MainMenu/File/New" << std::endl;
    });

    menuFileOpen.set_label("_Open");
    menuFileOpen.set_use_underline(true);
    menuFileOpen.signal_activate().connect([&]() {
      std::cout << "MainMenu/File/Open" << std::endl;
    });

    menuFileClose.set_label("_Close");
    menuFileClose.set_use_underline(true);
    menuFileClose.signal_activate().connect([&]() {
      std::cout << "MainMenu/File/Close" << std::endl;
    });
    
    menuEditUndo.set_label("_Undo");
    menuEditUndo.set_use_underline(true);
    menuEditUndo.signal_activate().connect([&]() {
      std::cout << "MainMenu/Edit/Undo" << std::endl;
    });
    
    menuEditRedo.set_label("_Redo");
    menuEditRedo.set_use_underline(true);
    menuEditRedo.signal_activate().connect([&]() {
      std::cout << "MainMenu/Edit/Redo" << std::endl;
    });
    
    menuEditCut.set_label("C_ut");
    menuEditCut.set_use_underline(true);
    menuEditCut.signal_activate().connect([&]() {
      std::cout << "MainMenu/Edit/Cut" << std::endl;
    });
    
    menuEditCopy.set_label("_Copy");
    menuEditCopy.set_use_underline(true);
    menuEditCopy.signal_activate().connect([&]() {
      std::cout << "MainMenu/Edit/Copy" << std::endl;
    });
    
    menuEditPaste.set_label("_Paste");
    menuEditPaste.set_use_underline(true);
    menuEditPaste.signal_activate().connect([&]() {
      std::cout << "MainMenu/Edit/Paste" << std::endl;
    });
    
    menuEditDelete.set_label("_Delete");
    menuEditDelete.set_use_underline(true);
    menuEditDelete.signal_activate().connect([&]() {
      std::cout << "MainMenu/Edit/Delete" << std::endl;
    });
    
    menuEditSelectAll.set_label("Select _All");
    menuEditSelectAll.set_use_underline(true);
    menuEditSelectAll.signal_activate().connect([&]() {
      std::cout << "MainMenu/Edit/SelectAll" << std::endl;
    });

    set_title("MainMenu example");
    resize(300, 300);
    show_all();
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
