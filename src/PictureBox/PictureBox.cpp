#include <gtkmm.h>

using namespace Glib;
using namespace Gtk;

class Form : public Window {
public:
  Form() {
    add(scrolledWindow);
    scrolledWindow.add(fixed);
    
    fixed.add(panel1);
    fixed.move(panel1, 10, 10);
    panel1.set_shadow_type(Gtk::SHADOW_IN);
    panel1.set_size_request(280, 280);

    panel1.add(pictureBox1);
    pictureBox1.set_size_request(280, 280);
    pictureBox1.set("Resources/Logo.png");

    set_title("PictureBox example");
    resize(300, 300);
    show_all();
  }
  
private:
  Fixed fixed;
  ScrolledWindow scrolledWindow;
  Frame panel1;
  Image pictureBox1;
};

int main(int argc, char* argv[]) {
  RefPtr<Application> application = Application::create(argc, argv);
  Form form;
  return application->run(form);
}
