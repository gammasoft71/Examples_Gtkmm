#include <string>
#include <vector>
#include <gtkmm.h>

using namespace Glib;
using namespace Gtk;
using namespace std;

class Window1 : public Window {
public:
  Window1() {
    add(scrolledWindow);
    scrolledWindow.add(fixed);
    
    fixed.add(choice_context);
    fixed.move(choice_context, 10, 10);
    fixed.add(choice_size);
    fixed.move(choice_size, 10, 60);
    fixed.add(panel1);
    fixed.move(panel1, 10, 110);
    fixed.add(label);
    fixed.move(label, 10, 400);
    fixed.add(button_previous);
    fixed.move(button_previous, 10, 430);
    fixed.add(button_next);
    fixed.move(button_next, 190, 430);

    choice_context.set_size_request(280, choice_size.get_height());
    choice_context.append("Actions");
    choice_context.append("Animations");
    choice_context.append("Applications");
    choice_context.append("Categories");
    choice_context.append("Devices");
    choice_context.append("Emblems");
    choice_context.append("Emotes");
    choice_context.append("International");
    choice_context.append("Mime types");
    choice_context.append("Places");
    choice_context.append("Status");
    choice_context.set_active(0);
    choice_context.signal_changed().connect([&] {
      images_index = 0;
      update_window();
    });

    choice_size.set_size_request(280, choice_size.get_height());
    choice_size.append("Icon size menu");
    choice_size.append("Icon size small toolbar");
    choice_size.append("Icon size large toolbar");
    choice_size.append("Icon size button");
    choice_size.append("Icon size dnd");
    choice_size.append("Icon size dialog");
    choice_size.append("256 x 256 pixels");
    choice_size.set_active(6);
    choice_size.signal_changed().connect([&] {
      update_window();
    });

    panel1.set_size_request(280, 280);
    panel1.set_shadow_type(Gtk::SHADOW_IN);
    panel1.add(pictureBox1);
    pictureBox1.set_size_request(280, 280);

    label.set_size_request(280, label.get_height());
    label.set_justify(Justification::JUSTIFY_CENTER);

    button_previous.set_label("Previous");
    button_previous.set_size_request(100, button_previous.get_height());
    button_previous.signal_button_release_event().connect([&](GdkEventButton*) {
      if (images_index > 0) images_index--;
      update_window();
      return true;
    });

    button_next.set_label("Next");
    button_next.set_size_request(100, button_next.get_height());
    button_next.signal_button_release_event().connect([&](GdkEventButton*) {
      if (images_index < images[choice_context.get_active_row_number()].size() - 1) images_index++;
      update_window();
      return true;
    });

    set_title("Images example");
    resize(300, 480);
    update_window();
    show_all();
  }
  
private:
  void update_window() {
    static IconSize icon_size_256  = IconSize::register_new("256x256", 256, 256);
    pictureBox1.set_from_icon_name(images[choice_context.get_active_row_number()][images_index],  choice_size.get_active_row_number() != 6 ? IconSize {choice_size.get_active_row_number() + 1} : icon_size_256);
    label.set_text(images[choice_context.get_active_row_number()][images_index]);
    button_previous.set_sensitive(images_index != 0);
    button_next.set_sensitive(images_index != images[choice_context.get_active_row_number()].size() - 1);
  }

  vector<vector<string>> images {
    {"address-book-new", "application-exit", "appointment-new", "call-start", "call-stop", "contact-new", "document-new", "document-open", "document-open-recent", "document-page-setup", "document-print", "document-print-preview", "document-properties", "document-revert", "document-save", "document-save-as", "document-send", "edit-clear", "edit-copy", "edit-cut", "edit-delete", "edit-find", "edit-find-replace", "edit-paste", "edit-redo", "edit-select-all", "edit-undo", "folder-new", "format-indent-less", "format-indent-more", "format-justify-center", "format-justify-fill", "format-justify-left", "format-justify-right", "format-text-direction-ltr", "format-text-direction-rtl", "format-text-bold", "format-text-italic", "format-text-underline", "format-text-strikethrough", "go-bottom", "go-down", "go-first", "go-home", "go-jump", "go-last", "go-next", "go-previous", "go-top", "go-up", "help-about", "help-contents", "help-faq", "insert-image", "insert-link", "insert-object", "insert-text", "list-add", "list-remove", "mail-forward", "mail-mark-important", "mail-mark-junk", "mail-mark-notjunk", "mail-mark-read", "mail-mark-unread", "mail-message-new", "mail-reply-all", "mail-reply-sender", "mail-send", "mail-send-receive", "media-eject", "media-playback-pause", "media-playback-start", "media-playback-stop", "media-record", "media-seek-backward", "media-seek-forward", "media-skip-backward", "media-skip-forward", "object-flip-horizontal", "object-flip-vertical", "object-rotate-left", "object-rotate-right", "process-stop", "system-lock-screen", "system-log-out", "system-run", "system-search", "system-reboot", "system-shutdown", "tools-check-spelling", "view-fullscreen", "view-refresh", "view-restore", "view-sort-ascending", "view-sort-descending", "window-close", "window-new", "zoom-fit-best", "zoom-in", "zoom-original", "zoom-out"},{ "process-working"},
    {"accessories-calculator", "accessories-character-map", "accessories-dictionary", "accessories-text-editor", "help-browser", "multimedia-volume-control", "preferences-desktop-accessibility", "preferences-desktop-font", "preferences-desktop-keyboard", "preferences-desktop-locale", "preferences-desktop-multimedia", "preferences-desktop-screensaver", "preferences-desktop-theme", "preferences-desktop-wallpaper", "system-file-manager", "system-software-install", "system-software-update", "utilities-system-monitor", "utilities-terminal"},
    {"applications-accessories", "applications-development", "applications-engineering", "applications-games", "applications-graphics", "applications-internet", "applications-multimedia", "applications-office", "applications-other", "applications-science", "applications-system", "applications-utilities", "preferences-desktop", "preferences-desktop-peripherals", "preferences-desktop-personal", "preferences-other", "preferences-system", "preferences-system-network", "system-help"},
    {"audio-card", "audio-input-microphone", "battery", "camera-photo", "camera-video", "camera-web", "computer", "drive-harddisk", "drive-optical", "drive-removable-media", "input-gaming", "input-keyboard", "input-mouse", "input-tablet", "media-flash", "media-floppy", "media-optical", "media-tape", "modem", "multimedia-player", "network-wired", "network-wireless", "pda", "phone", "printer", "scanner", "video-display"},
    {"emblem-default", "emblem-documents", "emblem-downloads", "emblem-favorite", "emblem-important", "emblem-mail", "emblem-photos", "emblem-readonly", "emblem-shared", "emblem-symbolic-link", "emblem-synchronized", "emblem-system", "emblem-unreadable"},
    {"face-angel", "face-angry", "face-cool", "face-crying", "face-devilish", "face-embarrassed", "face-kiss", "face-laugh", "face-monkey", "face-plain", "face-raspberry", "face-sad", "face-sick", "face-smile", "face-smile-big", "face-smirk", "face-surprise", "face-tired", "face-uncertain", "face-wink", "face-worried"},
    {"flag-af", "flag-ax", "flag-al", "flag-dz", "flag-as", "flag-ad", "flag-ao", "flag-ai", "flag-aq", "flag-ag", "flag-ar", "flag-am", "flag-aw", "flag-au", "flag-at", "flag-az", "flag-bs", "flag-bh", "flag-bd", "flag-bb", "flag-by", "flag-be", "flag-bz", "flag-bj", "flag-bm", "flag-bt", "flag-bo", "flag-bq", "flag-ba", "flag-bw", "flag-bv", "flag-br", "flag-io", "flag-bn", "flag-bg", "flag-bf", "flag-bi", "flag-cv", "flag-kh", "flag-cm", "flag-ca", "flag-ky", "flag-cf", "flag-td", "flag-cl", "flag-cn", "flag-cx", "flag-cc", "flag-co", "flag-km", "flag-cg", "flag-cd", "flag-ck", "flag-cr", "flag-ci", "flag-hr", "flag-cu", "flag-cw", "flag-cy", "flag-cz", "flag-dk", "flag-dj", "flag-dm", "flag-do", "flag-ec", "flag-eg", "flag-sv", "flag-gq", "flag-er", "flag-ee", "flag-sz", "flag-et", "flag-fk", "flag-fo", "flag-fj", "flag-fi", "flag-fr", "flag-gf", "flag-pf", "flag-tf", "flag-ga", "flag-gm", "flag-ge", "flag-de", "flag-gh", "flag-gi", "flag-gr", "flag-gl", "flag-gd", "flag-gp", "flag-gu", "flag-gt", "flag-gg", "flag-gn", "flag-gw", "flag-gy", "flag-ht", "flag-hm", "flag-va", "flag-hn", "flag-hk", "flag-hu", "flag-is", "flag-in", "flag-id", "flag-ir", "flag-iq", "flag-ie", "flag-im", "flag-il", "flag-it", "flag-jm", "flag-jp", "flag-je", "flag-jo", "flag-kz", "flag-ke", "flag-ki", "flag-kp", "flag-kr", "flag-kw", "flag-kg", "flag-la", "flag-lv", "flag-lb", "flag-ls", "flag-lr", "flag-ly", "flag-li", "flag-lt", "flag-lu", "flag-mo", "flag-mg", "flag-mw", "flag-my", "flag-mv", "flag-ml", "flag-mt", "flag-mh", "flag-mq", "flag-mr", "flag-mu", "flag-yt", "flag-mx", "flag-fm", "flag-md", "flag-mc", "flag-mn", "flag-me", "flag-ms", "flag-ma", "flag-mz", "flag-mm", "flag-na", "flag-nr", "flag-np", "flag-nl", "flag-nc", "flag-nz", "flag-ni", "flag-ne", "flag-ng", "flag-nu", "flag-nf", "flag-mk", "flag-mp", "flag-no", "flag-om", "flag-pk", "flag-pw", "flag-ps", "flag-pa", "flag-pg", "flag-py", "flag-pe", "flag-ph", "flag-pn", "flag-pl", "flag-pt", "flag-pr", "flag-qa", "flag-re", "flag-ro", "flag-ru", "flag-rw", "flag-bl", "flag-sh", "flag-kn", "flag-lc", "flag-mf", "flag-pm", "flag-vc", "flag-ws", "flag-sm", "flag-st", "flag-sa", "flag-sn", "flag-rs", "flag-sc", "flag-sl", "flag-sg", "flag-sx", "flag-sk", "flag-si", "flag-sb", "flag-so", "flag-za", "flag-gs", "flag-ss", "flag-es", "flag-lk", "flag-sd", "flag-sr", "flag-sj", "flag-se", "flag-ch", "flag-sy", "flag-tw", "flag-tj", "flag-tz", "flag-th", "flag-tl", "flag-tg", "flag-tk", "flag-to", "flag-tt", "flag-tn", "flag-tr", "flag-tm", "flag-tc", "flag-tv", "flag-ug", "flag-ua", "flag-ae", "flag-gb", "flag-us", "flag-um", "flag-uy", "flag-uz", "flag-vu", "flag-ve", "flag-vn", "flag-vg", "flag-vi", "flag-wf", "flag-eh", "flag-ye", "flag-zm", "flag-zw"},
    {"application-x-executable", "audio-x-generic", "font-x-generic", "image-x-generic", "package-x-generic", "text-html", "text-x-generic", "text-x-generic-template", "text-x-script", "video-x-generic", "x-office-address-book", "x-office-calendar", "x-office-document", "x-office-presentation", "x-office-spreadsheet"},
    {"folder", "folder-remote", "network-server", "network-workgroup", "start-here", "user-bookmarks", "user-desktop", "user-home", "user-trash"},
    {"appointment-missed", "appointment-soon", "audio-volume-high", "audio-volume-low", "audio-volume-medium", "audio-volume-muted", "battery-caution", "battery-low", "dialog-error", "dialog-information", "dialog-password", "dialog-question", "dialog-warning", "folder-drag-accept", "folder-open", "folder-visiting", "image-loading", "image-missing", "mail-attachment", "mail-unread", "mail-read", "mail-replied", "mail-signed", "mail-signed-verified", "media-playlist-repeat", "media-playlist-shuffle", "network-error", "network-idle", "network-offline", "network-receive", "network-transmit", "network-transmit-receive", "printer-error", "printer-printing", "security-high", "security-medium", "security-low", "software-update-available", "software-update-urgent", "sync-error", "sync-synchronizing", "task-due", "task-past-due", "user-available", "user-away", "user-idle", "user-offline", "user-trash-full", "weather-clear", "weather-clear-night", "weather-few-clouds", "weather-few-clouds-night", "weather-fog", "weather-overcast", "weather-severe-alert", "weather-showers", "weather-showers-scattered", "weather-snow", "weather-storm"}
  };
  size_t images_index = 0;
  Fixed fixed;
  ScrolledWindow scrolledWindow;
  ComboBoxText choice_context;
  ComboBoxText choice_size;
  Frame panel1;
  Image pictureBox1;
  Label label;
  Button button_previous;
  Button button_next;
};

int main(int argc, char* argv[]) {
  RefPtr<Application> application = Application::create(argc, argv);
  Window1 window1;
  return application->run(window1);
}
