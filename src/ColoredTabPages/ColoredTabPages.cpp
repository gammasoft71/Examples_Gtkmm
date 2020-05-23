#include <gtkmm.h>

using namespace Glib;
using namespace Gtk;

class WindowMain : public Window {
public:
  WindowMain() {
    add(scrolledWindow);
    scrolledWindow.add(fixed);
    
    tabControl1.set_size_request(370, 250);
    fixed.add(tabControl1);
    fixed.move(tabControl1, 10, 10);

    tabControl1.insert_page(tabPageRed, "Red", 0);
    tabControl1.insert_page(tabPageGreen, "Green", 1);
    tabControl1.insert_page(tabPageBlue, "Blue", 2);
    tabControl1.insert_page(tabPageYellow, "Yellow", 3);
    
    tabPageRed.override_background_color(Gdk::RGBA("#FF0000"));
    tabPageGreen.override_background_color(Gdk::RGBA("#008000"));
    tabPageBlue.override_background_color(Gdk::RGBA("#0000FF"));
    tabPageYellow.override_background_color(Gdk::RGBA("#FFFF00"));

    set_title("Colored TabPages example");
    resize(390, 270);
    show_all();
  }
  
private:
  Fixed fixed;
  ScrolledWindow scrolledWindow;
  Notebook tabControl1;
  Frame tabPageRed;
  Frame tabPageGreen;
  Frame tabPageBlue;
  Frame tabPageYellow;
};

int main(int argc, char* argv[]) {
  auto application = Application::create(argc, argv);
  WindowMain window;
  return application->run(window);
}
