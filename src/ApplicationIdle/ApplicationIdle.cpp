#include <chrono>
#include <gtkmm.h>

using namespace std::chrono_literals;
using namespace Glib;
using namespace Gtk;

class Form : public Window {
public:
  Form() {
    signal_idle().connect(sigc::mem_fun(*this, &Form::OnApplicationIdle));

    this->resize(300, 300);
    this->show_all();
  }

private:
  bool OnApplicationIdle() {
    static std::chrono::high_resolution_clock::time_point lastIdleTime;
    std::chrono::high_resolution_clock::duration elapsedTime = std::chrono::high_resolution_clock::now() - lastIdleTime;
    if (elapsedTime >= 100ms) {
      this->set_title(ustring::compose("%1", ++this->counter));
      lastIdleTime = std::chrono::high_resolution_clock::now();
    }
    return true;
  }

  int counter = 0;
};

int main(int argc, char* argv[]) {
  Glib::RefPtr<Application> application = Application::create(argc, argv);
  Form form;
  return application->run(form);
}
