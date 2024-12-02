#ifndef BLX_TYPES_H
#define BLX_TYPES_H

#include <X11/Xlib.h>
#include <X11/Xatom.h>

struct blx {
        Display *display;
        int      screen;
        Window   window;
        GC       gc;
        Atom     closing;
};

typedef struct blx blx_t;

#endif /* blx/types.h */
