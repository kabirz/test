#include <gtk/gtk.h>

int main()
{
  GtkWidget *window;
  GtkWidget *vbox;
  GtkWidget *normal_label, *color_label, *link_label, *angle_label;

  gtk_init(NULL, NULL);
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_default_size(GTK_WINDOW(window), 300, 300);
  gtk_window_set_title(GTK_WINDOW(window), "Label");
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  g_signal_connect(GTK_OBJECT(window), "destroy",
		   G_CALLBACK(gtk_main_quit), NULL);

  vbox = gtk_vbox_new(FALSE, 5);

  normal_label = gtk_label_new("This is a normal label.");
  gtk_label_set_justify(GTK_LABEL(normal_label), GTK_JUSTIFY_RIGHT);
  gtk_box_pack_start(GTK_BOX(vbox), normal_label, FALSE, FALSE, 5);

  color_label = gtk_label_new(NULL);
  gtk_label_set_markup(GTK_LABEL(color_label),
		       "<span fgcolor=\"green\">This is green color label</span>");
  gtk_box_pack_start(GTK_BOX(vbox), color_label, FALSE, FALSE, 5);

  link_label = gtk_label_new(NULL);
  gtk_label_set_markup(GTK_LABEL(link_label),
		       "<a href=\"http://www.google.com\"><span bgcolor=\"red\">google-link</span></a>");
  gtk_box_pack_start(GTK_BOX(vbox), link_label, FALSE, FALSE, 5);

  angle_label = gtk_label_new("This label has angle.");
  gtk_label_set_angle(GTK_LABEL(angle_label), 45);
  gtk_box_pack_start(GTK_BOX(vbox), angle_label, FALSE, FALSE, 5);

  gtk_container_add(GTK_CONTAINER(window), vbox);
  gtk_widget_show_all(window);
  gtk_main();
  return 0;
}
