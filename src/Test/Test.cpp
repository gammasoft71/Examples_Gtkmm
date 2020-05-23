#include <gtk/gtk.h>
#include <any>
#include <string>
#include <iostream>

void OnButtonClicked(GtkButton* button, gpointer application) {
  g_application_quit(G_APPLICATION(application));
}

void OnApplicationActivate(GtkApplication* application, gpointer userData) {
  GtkWindow* form = GTK_WINDOW(gtk_window_new(GTK_WINDOW_TOPLEVEL));
  gtk_window_set_title(form, "Test");
  gtk_window_set_default_size(form, 300, 300);

  GtkFixed* fixed = GTK_FIXED(gtk_fixed_new());
  gtk_container_add(GTK_CONTAINER(form), GTK_WIDGET(fixed));

  GtkButton* button = GTK_BUTTON(gtk_button_new());
  GTK_WIDGET_GET_CLASS(button)->get_preferred_width = [](GtkWidget* widget, gint *minimum_width, gint *natural_width) {*minimum_width = *natural_width = 0;};
  GTK_WIDGET_GET_CLASS(button)->get_preferred_height_and_baseline_for_width = [](GtkWidget* widget, gint width, gint* minimum_height, gint* natural_height,gint* minimum_baseline, gint* natural_baseline) {*minimum_height = *natural_height = *minimum_baseline = *natural_baseline = 0;};
  gtk_button_set_label(button, "Quit");
  gtk_container_add(GTK_CONTAINER(fixed), GTK_WIDGET(button));
  gtk_fixed_move(fixed, GTK_WIDGET(button), 10, 10);
  gtk_widget_set_size_request(GTK_WIDGET(button), 75, 25);
  g_signal_connect(button, "clicked", G_CALLBACK(OnButtonClicked), application);

  gtk_widget_show_all(GTK_WIDGET(form));
  gtk_window_set_application(form, application);
}

using namespace std;
using namespace std::string_literals;

int main(int argc, char* argv[]) {
  GtkApplication* application = gtk_application_new("org.gammasoft71.Test", G_APPLICATION_FLAGS_NONE);
  g_signal_connect(application, "activate", G_CALLBACK(OnApplicationActivate), nullptr);
  int result = g_application_run(G_APPLICATION(application), argc, argv);
  g_object_unref(application);
  return result;
}
