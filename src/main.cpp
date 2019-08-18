#include <gtk/gtk.h>
#include <cstdlib>
#include <iostream>
#include "musicbee.h"

static gboolean delete_event(GtkWidget *widget, GdkEvent *event, gpointer data) {
    bpm::try_set_bpm(100);
    // true to stop delete_event propagation
    return false;
}

static void destroy(GtkWidget *widget, gpointer data) {
    gtk_main_quit();
}

int main(int argc, char **argv) {
    gtk_init(&argc, &argv);

    GtkBuilder *builder;
    GtkWidget *window;

    builder = gtk_builder_new();
    GError *err = nullptr;
    if (!gtk_builder_add_from_file(builder, "resources/main.glade", &err)) {
        std::cerr << "Error loading glade file. Message:" << err->message << std::endl;
        exit(2);
    }

    window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));
    gtk_builder_connect_signals(builder, nullptr);
    g_signal_connect(window, "delete-event", G_CALLBACK(delete_event), NULL);
    g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);

    g_object_unref(builder);

    gtk_widget_show(window);
    gtk_main();
    return 0;
}
