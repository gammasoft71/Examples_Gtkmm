#include <iostream>
#include <gtkmm.h>

using namespace Glib;
using namespace Gtk;

class Form : public Window {
public:
  Form() {
    add(scrolledWindow);
    scrolledWindow.add(fixed);
    
    fixed.add(progressBar1);
    fixed.move(progressBar1, 50, 50);
    progressBar1.set_size_request(200, 10);
    progressBar1.set_fraction(0.0);
    
    fixed.add(progressBar2);
    fixed.move(progressBar2, 50, 80);
    progressBar2.set_size_request(200, 10);
    progressBar2.set_fraction(0.5);
    
    fixed.add(progressBar3);
    fixed.move(progressBar3, 50, 110);
    progressBar3.set_size_request(200, 10);
    progressBar3.set_fraction(1.0);
    
    fixed.add(progressBar4);
    fixed.move(progressBar4, 50, 140);
    progressBar4.set_size_request(200, 10);
    progressBar4.set_fraction(0.0);
    
    fixed.add(progressBar5);
    fixed.move(progressBar5, 50, 170);
    progressBar5.set_size_request(200, 10);
    progressBar5.set_fraction(0.0);
    
    signal_timeout().connect([&]() {
      progressBar4.set_fraction(progressBar4.get_fraction() < 1.0 ? progressBar4.get_fraction() + 0.007142857142857 : 0.0);
      return true;
    }, 50);
    
    signal_timeout().connect([&]() {
      progressBar5.pulse();
      return true;
    }, 100);
    
    set_title("ProgressBar example");
    resize(300, 300);
    show_all();
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
