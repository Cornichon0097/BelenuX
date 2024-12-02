#ifndef BLX_TYPES_H
#define BLX_TYPES_H

#include <X11/Xlib.h>
#include <X11/Xatom.h>

struct blx {
        Display *display;
        int      screen;
        Window   window;
        GC       gc;
        Atom     close_op;
};

typedef struct blx blx_t;

typedef XPoint blx_point_t;

#endif /* blx/types.h */
