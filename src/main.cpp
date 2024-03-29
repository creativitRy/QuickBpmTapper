#include <gtk/gtk.h>
#include <cstdlib>
#include <iostream>
#include "callbacks.h"
#include "calculator.h"

static gboolean delete_event(GtkWidget *widget, GdkEvent *event, gpointer data) {
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
        exit(1);
    }

    window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));
    gtk_builder_connect_signals(builder, nullptr);
    g_signal_connect(window, "delete-event", G_CALLBACK(delete_event), nullptr);
    g_signal_connect(window, "destroy", G_CALLBACK(destroy), nullptr);
    gtk_widget_add_events(window, GDK_KEY_PRESS_MASK);
    g_signal_connect(window, "key_press_event", G_CALLBACK(bpm::key_pressed), nullptr);

    auto bpm_label = GTK_LABEL(gtk_builder_get_object(builder, "bpm_label"));
    auto taps_label = GTK_LABEL(gtk_builder_get_object(builder, "taps_label"));
    bpm::init(bpm_label, taps_label);

    auto tap_button = GTK_BUTTON(gtk_builder_get_object(builder, "tap_button"));
    g_signal_connect(tap_button, "button-press-event", G_CALLBACK(bpm::tap_clicked), nullptr);

    auto undo_button = GTK_BUTTON(gtk_builder_get_object(builder, "undo_button"));
    g_signal_connect(undo_button, "clicked", G_CALLBACK(bpm::undo_clicked), nullptr);

    auto reset_button = GTK_BUTTON(gtk_builder_get_object(builder, "reset_button"));
    g_signal_connect(reset_button, "clicked", G_CALLBACK(bpm::reset_clicked), nullptr);

    auto musicbee_button = GTK_BUTTON(gtk_builder_get_object(builder, "musicbee_button"));
    g_signal_connect(musicbee_button, "clicked", G_CALLBACK(bpm::musicbee_clicked), nullptr);

    g_object_unref(builder);

    gtk_widget_show(window);
    gtk_main();
    return 0;
}
