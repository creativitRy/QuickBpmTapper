//
// Created by Gahwon on 8/18/2019.
//

#ifndef QUICKBPMTAPPER_CALLBACKS_H
#define QUICKBPMTAPPER_CALLBACKS_H

#include <gtk/gtk.h>

namespace bpm {
    void tap_clicked(GtkButton *button, gpointer data);

    void undo_clicked(GtkButton *button, gpointer data);

    void reset_clicked(GtkButton *button, gpointer data);

    void musicbee_clicked(GtkButton *button, gpointer data);

    gboolean key_pressed(GtkWidget *widget, GdkEventKey *event, gpointer data);
}


#endif //QUICKBPMTAPPER_CALLBACKS_H
