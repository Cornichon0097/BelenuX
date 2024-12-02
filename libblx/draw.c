#include <blx/draw.h>

void blx_dpoint(blx_t *const blx, const int x, const int y)
{
        XDrawPoint(blx->display, blx->window, blx->gc, x, y);
}

void blx_dline(blx_t *const blx, const int x1, const int y1,
               const int x2, const int y2)
{
        XDrawLine(blx->display, blx->window, blx->gc, x1, y1, x2, y2);
}

void blx_drec(blx_t *const blx, const int x, const int y,
              const unsigned int width, const unsigned int height)
{
        XDrawRectangle(blx->display, blx->window, blx->gc, x, y, width, height);
}

void blx_frec(blx_t *const blx, const int x, const int y,
              const unsigned int width, const unsigned int height)
{
        XFillRectangle(blx->display, blx->window, blx->gc, x, y, width, height);
}

void blx_darc(blx_t *const blx, const int x, const int y,
              const unsigned int width, const unsigned int height,
              const int angle1, const int angle2)
{
        XDrawArc(blx->display, blx->window, blx->gc, x, y, width, height, angle1 * 64, angle2 * 64);
}

void blx_farc(blx_t *const blx, const int x, const int y,
              const unsigned int width, const unsigned int height,
              const int angle1, const int angle2)
{
        XFillArc(blx->display, blx->window, blx->gc, x, y, width, height, angle1 * 64, angle2 * 64);
}
