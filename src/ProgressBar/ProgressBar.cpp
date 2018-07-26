#include <iostream>
#include <gtkmm.h>

using namespace Glib;
using namespace Gtk;

class Form : public Window {
public:
  Form() {
    this->add(this->scrolledWindow);
    this->scrolledWindow.add(this->fixed);
    
    this->fixed.add(this->progressBar1);
    this->fixed.move(this->progressBar1, 50, 50);
    this->progressBar1.set_size_request(200, 10);
    this->progressBar1.set_fraction(0.0);
    
    this->fixed.add(this->progressBar2);
    this->fixed.move(this->progressBar2, 50, 80);
    this->progressBar2.set_size_request(200, 10);
    this->progressBar2.set_fraction(0.5);
    
    this->fixed.add(this->progressBar3);
    this->fixed.move(this->progressBar3, 50, 110);
    this->progressBar3.set_size_request(200, 10);
    this->progressBar3.set_fraction(1.0);
    
    this->fixed.add(this->progressBar4);
    this->fixed.move(this->progressBar4, 50, 140);
    this->progressBar4.set_size_request(200, 10);
    this->progressBar4.set_fraction(0.0);
    
    this->fixed.add(this->progressBar5);
    this->fixed.move(this->progressBar5, 50, 170);
    this->progressBar5.set_size_request(200, 10);
    this->progressBar5.set_fraction(0.0);
    
    signal_timeout().connect([&]() {
      this->progressBar4.set_fraction(this->progressBar4.get_fraction() < 1.0 ? this->progressBar4.get_fraction() + 0.007142857142857 : 0.0);
      return true;
    }, 50);
    
    signal_timeout().connect([&]() {
      this->progressBar5.pulse();
      return true;
    }, 100);
    
    this->set_title("ProgressBar example");
    this->resize(300, 300);
    this->show_all();
  }
  
private:
  Fixed fixed;
  ScrolledWindow scrolledWindow;
  ProgressBar progressBar1;
  ProgressBar progressBar2;
  ProgressBar progressBar3;
  ProgressBar progressBar4;
  ProgressBar progressBar5;
};

// The main entry point for the application.
int main(int argc, char* argv[]) {
  RefPtr<Application> application = Application::create(argc, argv);
  Form form;
  return application->run(form);
}
