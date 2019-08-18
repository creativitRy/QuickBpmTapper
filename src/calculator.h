//
// Created by Gahwon on 8/18/2019.
//

#ifndef QUICKBPMTAPPER_CALCULATOR_H
#define QUICKBPMTAPPER_CALCULATOR_H

#include <gtk/gtk.h>

namespace bpm {
    void init(GtkLabel *bpm, GtkLabel *taps);

    int get_bpm();
    void tap();

    void undo();
    void reset();
}


#endif //QUICKBPMTAPPER_CALCULATOR_H
