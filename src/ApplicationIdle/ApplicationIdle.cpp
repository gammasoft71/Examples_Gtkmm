#include <chrono>
#include <gtkmm.h>

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
    std::chrono::milliseconds elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - lastIdleTime);
    if (elapsedTime.count() >= 100) {
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
