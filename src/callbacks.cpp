//
// Created by Gahwon on 8/18/2019.
//

#include "callbacks.h"
#include "calculator.h"
#include "musicbee.h"

void bpm::tap_clicked(GtkButton *button, gpointer data) {
    bpm::tap();
}

void bpm::undo_clicked(GtkButton *button, gpointer data) {
    g_print("undo\n");
    bpm::undo();
}

void bpm::reset_clicked(GtkButton *button, gpointer data) {
    g_print("reset\n");
    bpm::reset();
}

void bpm::musicbee_clicked(GtkButton *button, gpointer data) {
    g_print("musicbee\n");
    bpm::try_set_bpm(bpm::get_bpm());
}

gboolean bpm::key_pressed(GtkWidget *widget, GdkEventKey *event, gpointer data) {
    if (event->keyval == GDK_KEY_space) {
        tap_clicked(nullptr, data);
        return true;
    } else if (event->keyval == GDK_KEY_z) {
        undo_clicked(nullptr, data);
        return true;
    } else if (event->keyval == GDK_KEY_Escape) {
        reset_clicked(nullptr, data);
        return true;
    }
    return false;
}
