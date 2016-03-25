#include <gtk/gtk.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
  GtkWidget *window;
  GtkWidget *button;
  gtk_init(&argc, &argv);
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "Login");
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);
  gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
  g_signal_connect(GTK_OBJECT(window), "destroy",
		   GTK_SIGNAL_FUNC(gtk_main_quit), NULL);
  button = gtk_button_new_with_label("OK");
  gtk_container_add(GTK_CONTAINER(window), button);

  gtk_widget_show_all(window);
  gtk_main();
  return 0;
}
