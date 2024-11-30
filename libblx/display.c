#include <stdlib.h>
#include <stdio.h>

#include <blx/display.h>

#include <X11/Xutil.h>

#define BORDER_WIDTH 1U

/**
 * @brief      { function_description }
 *
 * @param      blx     The blx
 * @param[in]  width   The width
 * @param[in]  height  The height
 */
static void blx_init(blx_t *const blx,
                     const unsigned int width, const unsigned int height)
{
        blx->display = XOpenDisplay(NULL);
        blx->screen  = XDefaultScreen(blx->display);
        blx->gc      = XDefaultGC(blx->display, blx->screen);
        blx->window  = XCreateSimpleWindow(blx->display,
                                        XRootWindow(blx->display, blx->screen),
                                        0, 0, width, height, BORDER_WIDTH,
                                        XBlackPixel(blx->display, blx->screen),
                                        XWhitePixel(blx->display, blx->screen));
}

/**
 * @brief      { function_description }
 *
 * @param      blx   The blx
 * @param[in]  x     { parameter_description }
 * @param[in]  y     { parameter_description }
 */
static void blx_set_hints(blx_t *const blx, const int x, const int y)
{
        XSizeHints *hints = XAllocSizeHints();

        hints->flags = PPosition;
        hints->x     = x;
        hints->y     = y;

        XSetWMNormalHints(blx->display, blx->window, hints);
        XFree(hints);
}

/**
 * @brief      { function_description }
 *
 * @param      blx   The blx
 */
static void blx_set_attr(blx_t *const blx)
{
        XSetWindowAttributes attr;

        attr.backing_store = Always;
        XChangeWindowAttributes(blx->display, blx->window,
                                CWBackingStore, &attr);
}

/**
 * @brief      { function_description }
 *
 * @param[in]  blx  The blx dispaly
 */
static void blx_set_handler(blx_t *const blx)
{
        XSelectInput(blx->display, blx->window, ExposureMask
                                                | KeyPressMask
                                                | KeyReleaseMask
                                                | ButtonPressMask
                                                | ButtonReleaseMask
                                                | StructureNotifyMask);

        blx->closing = XInternAtom(blx->display, "WM_DELETE_WINDOW", False);
        XSetWMProtocols(blx->display, blx->window, &(blx->closing), 1);
}

/**
 * @brief      Create a new blx object.
 *
 * The blx_create() function create a new \a blx object. The \a blx object is
 * set at position (x, y) with a width x height size.
 *
 * @param[in]  x       { parameter_description }
 * @param[in]  y       { parameter_description }
 * @param[in]  width   The width
 * @param[in]  height  The height
 *
 * @return     { description_of_the_return_value }
 */
blx_t *blx_create(const int x, const int y,
                  const unsigned int width, const unsigned int height)
{
        blx_t *blx = (blx_t *) malloc(sizeof(blx_t));

        blx_init(blx, width, height);
        blx_set_hints(blx, x, y);
        blx_set_attr(blx);
        blx_set_handler(blx);

        return blx;
}

/**
 * @brief      { function_description }
 *
 * @param[in]  blx  The blx dispaly
 */
void blx_map(blx_t *const blx)
{
        XEvent event;

        XMapWindow(blx->display, blx->window);

        do {
                XNextEvent(blx->display, &event);
        } while (event.type != Expose);
}

/**
 * @brief      { function_description }
 *
 * @param      blx   The blx
 */
void blx_unmap(blx_t *const blx)
{
  XUnmapWindow(blx->display, blx->window);
  XCheckTypedWindowEvent(blx->display, blx->window, UnmapNotify, NULL);
}

/**
 * @brief      { function_description }
 *
 * @param      blx   The blx
 */
void blx_destroy(blx_t **const blx)
{
        XCloseDisplay((*blx)->display);
        free(*blx);

        *blx = NULL;
}

