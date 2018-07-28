#include <memory>
#include <gtkmm.h>

void OnButtonClicked(GtkButton* button, gpointer application) {
  g_application_quit(G_APPLICATION(application));
}

void OnApplicationActivate(GtkApplication* application, gpointer userData) {
  GtkRequestedSize requestedSize;
  requestedSize.minimum_size = 0;
  requestedSize.natural_size = 0;
  gtk_distribute_natural_allocation(0, 0, &requestedSize);

  GtkWindow* form = GTK_WINDOW(gtk_window_new(GTK_WINDOW_TOPLEVEL));
  gtk_window_set_title(form, "Test");
  gtk_window_set_default_size(form, 300, 300);

  GtkFixed* fixed = GTK_FIXED(gtk_fixed_new());
  gtk_container_add(GTK_CONTAINER(form), GTK_WIDGET(fixed));

  GtkButton* button = GTK_BUTTON(gtk_button_new());
  gtk_button_set_label(button, "Quit");
  gtk_widget_set_size_request(GTK_WIDGET(button), 50, 10);
  gtk_widget_set_hexpand(GTK_WIDGET(button), false);
  gtk_widget_set_vexpand(GTK_WIDGET(button), false);
  gtk_container_add(GTK_CONTAINER(fixed), GTK_WIDGET(button));
  gtk_fixed_move(fixed, GTK_WIDGET(button), 10, 10);
  g_signal_connect(button, "clicked", G_CALLBACK(OnButtonClicked), application);

  gtk_widget_show_all(GTK_WIDGET(form));
  gtk_window_set_application(form, application);
}

int main(int argc, char* argv[]) {
  GtkApplication* application = gtk_application_new("org.gammasoft71.Test", G_APPLICATION_FLAGS_NONE);
  g_signal_connect(application, "activate", G_CALLBACK(OnApplicationActivate), nullptr);
  int result = g_application_run(G_APPLICATION(application), argc, argv);
  g_object_unref(application);
  return result;
}
