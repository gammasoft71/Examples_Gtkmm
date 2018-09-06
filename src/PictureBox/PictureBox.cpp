#include <gtkmm.h>

using namespace Glib;
using namespace Gtk;

class Form : public Window {
public:
  Form() {
    this->add(this->scrolledWindow);
    this->scrolledWindow.add(this->fixed);
    
    this->fixed.add(this->panel1);
    this->fixed.move(this->panel1, 10, 10);
    this->panel1.set_shadow_type(Gtk::SHADOW_IN);
    this->panel1.set_size_request(280, 280);

    this->panel1.add(this->pictureBox1);
    this->pictureBox1.set_size_request(280, 280);
    this->pictureBox1.set("Resources/Logo.png");

    this->set_title("PictureBox example");
    this->resize(300, 300);
    this->show_all();
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
