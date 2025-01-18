/*
 *
 * Copyright (C) 2020-2025 Antoni Blanche (antoni.blanche77@gmail.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#include <stdlib.h>
#include <stdio.h>

#include <blx/types.h>
#include <blx/frame.h>

#include <X11/Xutil.h>

#define BORDER_WIDTH 1U

static void blx_init(blx_t *const blx,
                     const unsigned int x, const unsigned int y,
                     const unsigned int width, const unsigned int height)
{
        blx->display = XOpenDisplay(NULL);
        blx->screen  = XDefaultScreen(blx->display);
        blx->gc      = XDefaultGC(blx->display, blx->screen);
        blx->window  = XCreateSimpleWindow(blx->display,
                                        XRootWindow(blx->display, blx->screen),
                                        x, y, width, height, BORDER_WIDTH,
                                        XBlackPixel(blx->display, blx->screen),
                                        XWhitePixel(blx->display, blx->screen));
}

static void blx_set_hints(blx_t *const blx, const int x, const int y)
{
        XSizeHints *hints = XAllocSizeHints();

        hints->flags = PPosition;
        hints->x     = x;
        hints->y     = y;

        XSetWMNormalHints(blx->display, blx->window, hints);
        XFree(hints);
}

static void blx_set_attr(blx_t *const blx)
{
        XSetWindowAttributes attr;

        attr.backing_store = Always;
        XChangeWindowAttributes(blx->display, blx->window,
                                CWBackingStore, &attr);
}

static void blx_set_handler(blx_t *const blx)
{
        XSelectInput(blx->display, blx->window, ExposureMask
                                                | KeyPressMask
                                                | KeyReleaseMask
                                                | ButtonPressMask
                                                | ButtonReleaseMask
                                                | StructureNotifyMask);

        blx->close_op = XInternAtom(blx->display, "WM_DELETE_WINDOW", False);
        XSetWMProtocols(blx->display, blx->window, &(blx->close_op), 1);
}

static void blx_map(blx_t *const blx)
{
        XEvent event;

        XMapWindow(blx->display, blx->window);
        XWindowEvent(blx->display, blx->window, ExposureMask, &event);
}

blx_t *blx_create(const int x, const int y,
                  const unsigned int width, const unsigned int height)
{
        blx_t *blx = (blx_t *) malloc(sizeof(blx_t));

        blx_init(blx, x, y, width, height);
        blx_set_hints(blx, x, y);
        blx_set_attr(blx);
        blx_set_handler(blx);
        blx_map(blx);

        return blx;
}

void blx_destroy(blx_t **const blx)
{
        XUnmapWindow((*blx)->display, (*blx)->window);
        XCloseDisplay((*blx)->display);
        free(*blx);

        *blx = NULL;
}
