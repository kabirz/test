#include <gtk/gtk.h>

int main()
{
  GtkWidget *window;
  GtkWidget *list, *list_item;
  GList *item_list;

  gtk_init(0, NULL);
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(window), 300, 300);
  gtk_window_set_title(GTK_WINDOW(window), "GtkList");
  g_signal_connect(GTK_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit),
		   NULL);

  list = gtk_list_new();
  //gtk_list_set_selection_mode(GTK_LIST(list),GTK_SELECTION_MULTIPLE);

  item_list = NULL;
  list_item = gtk_list_item_new_with_label("first");
  item_list = g_list_append(item_list, list_item);
  list_item = gtk_list_item_new_with_label("second");
  item_list = g_list_append(item_list, list_item);
  list_item = gtk_list_item_new_with_label("third");
  item_list = g_list_append(item_list, list_item);

  gtk_list_insert_items(GTK_LIST(list), item_list, 0);
  item_list = NULL;
  list_item = gtk_list_item_new_with_label("insert_before_third");
  item_list = g_list_append(item_list, list_item);
  gtk_list_insert_items(GTK_LIST(list), item_list, 2);

  item_list = NULL;
  list_item = gtk_list_item_new_with_label("append");
  item_list = g_list_append(item_list, list_item);
  gtk_list_append_items(GTK_LIST(list), item_list);

  item_list = NULL;
  list_item = gtk_list_item_new_with_label("prepend");
  item_list = g_list_append(item_list, list_item);
  gtk_list_prepend_items(GTK_LIST(list), item_list);

  //gtk_list_clear_items(GTK_LIST(list),0,2);
  gtk_list_select_item(GTK_LIST(list), 3);
  //gtk_list_select_all(GTK_LIST(list));

  gtk_container_add(GTK_CONTAINER(window), list);
  gtk_widget_show_all(window);
  gtk_main();
  return 0;
}
