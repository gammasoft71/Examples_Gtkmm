#include <chrono>
#include <gtkmm.h>

using namespace std::chrono;
using namespace std::literals;
using namespace Glib;
using namespace Gtk;

class WindowMain : public Window {
public:
  WindowMain() {
    signal_idle().connect(sigc::mem_fun(*this, &WindowMain::OnApplicationIdle));

    resize(300, 300);
    show_all();
  }

private:
  bool OnApplicationIdle() {
    static auto lastIdleTime = high_resolution_clock::now();
    auto elapsedTime = high_resolution_clock::now() - lastIdleTime;
    if (elapsedTime >= 100ms) {
      set_title(ustring::compose("%1", ++counter));
      lastIdleTime = high_resolution_clock::now();
    }
    return true;
  }

  int counter = 0;
};

int main(int argc, char* argv[]) {
  auto application = Application::create(argc, argv);
  WindowMain window;
  return application->run(window);
}
