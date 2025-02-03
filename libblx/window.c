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
#include <blx/window.h>

#include <X11/Xutil.h>

#define BORDER_WIDTH 1U

blx_t *blx_create(const unsigned int width, const unsigned int height)
{
        blx_t *blx = (blx_t *) malloc(sizeof(blx_t));
        /* XSetWindowAttributes attr; */

        if (blx == NULL)
                return NULL;

        blx->display = XOpenDisplay(NULL);

        if (blx->display == NULL) {
                fprintf(stderr, "%s\n", "Cannot connect to server X");
                free(blx);
                return NULL;
        }

        blx->screen  = XDefaultScreen(blx->display);
        blx->gc      = XDefaultGC(blx->display, blx->screen);
        blx->window  = XCreateSimpleWindow(blx->display,
                                        XRootWindow(blx->display, blx->screen),
                                        0, 0, width, height, BORDER_WIDTH,
                                        XBlackPixel(blx->display, blx->screen),
                                        XWhitePixel(blx->display, blx->screen));

        XSelectInput(blx->display, blx->window, ExposureMask
                                                | KeyPressMask
                                                | KeyReleaseMask
                                                | ButtonPressMask
                                                | ButtonReleaseMask
                                                | StructureNotifyMask);

        /* attr.backing_store = Always;
        XChangeWindowAttributes(blx->display, blx->window,
                                CWBackingStore, &attr); */

        blx->close_op = XInternAtom(blx->display, "WM_DELETE_WINDOW", False);
        XSetWMProtocols(blx->display, blx->window, &(blx->close_op), 1);

        return blx;
}

void blx_set_title(blx_t *const blx, const char* const title)
{
        XStoreName(blx->display, blx->window, title);
}

void blx_set_location(blx_t *const blx, const int x, const int y)
{
        XMoveWindow(blx->display, blx->window, x, y);
}

void blx_set_size(blx_t *const blx, const unsigned width, const unsigned height)
{
        XResizeWindow(blx->display, blx->window, width, height);
}

/* void GL_SetFrameRate(unsigned long frame_rate)
{
  GL.time.frame_rate = frame_rate;
  GL.time.frame_time = BILLION / (frame_rate);
}

void blx_set_font(const char* fontname)
{
  GL.font = XLoadQueryFont(GL.display, fontname);
  XSetFont(GL.display, GL.gc, GL.font->fid);
} */

void blx_fixe_size(blx_t *const blx)
{
        XWindowAttributes attr;
        XSizeHints hints;

        XGetWindowAttributes(blx->display, blx->window, &attr);

        hints.flags      = PMinSize | PMaxSize;
        hints.min_width  = hints.max_width  = attr.width;
        hints.min_height = hints.max_height = attr.height;

        XSetWMNormalHints(blx->display, blx->window, &hints);
}

void blx_show(blx_t *const blx)
{
        XMapWindow(blx->display, blx->window);
}

void blx_hide(blx_t *const blx)
{
        XUnmapWindow(blx->display, blx->window);
}

void blx_clear(blx_t *const blx)
{
        XClearWindow(blx->display, blx->window);
}

void blx_destroy(blx_t **const blx)
{
        XCloseDisplay((*blx)->display);

        free(*blx);
        *blx = NULL;
}

void blx_loop(blx_t *const blx, int (*update)(blx_t *))
{
        XEvent *event = (XEvent *) malloc(sizeof(XEvent));

        do {
                XNextEvent(blx->display, event);

                if (update != NULL)
                        update(blx);
        } while (!BLX_CLOSE_OP(blx, event));

        free(event);
}
