#include <blx/event.h>

static int close_op(__attribute__((unused)) Display *display, XEvent *event, char *arg)
{
        return ((event->type == ClientMessage)
                && (((Atom) event->xclient.data.l[0]) == (Atom) arg));
}

int blx_open(blx_t *const blx)
{
        XEvent event;

        return !XCheckIfEvent(blx->display, &event, &close_op, (void *) blx->close_op);
}
