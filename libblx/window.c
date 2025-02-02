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

        XSelectInput(blx->display, blx->window, ExposureMask
                                                | KeyPressMask
                                                | KeyReleaseMask
                                                | ButtonPressMask
                                                | ButtonReleaseMask
                                                | StructureNotifyMask);

        blx->close_op = XInternAtom(blx->display, "WM_DELETE_WINDOW", False);
        XSetWMProtocols(blx->display, blx->window, &(blx->close_op), 1);
}

blx_t *blx_create(const unsigned int width, const unsigned int height)
{
        blx_t *blx = (blx_t *) malloc(sizeof(blx_t));

        if (blx != NULL) {
                blx_init(blx, width, height);
                blx_show(blx);
        }

        return blx;
}

void blx_set_location(blx_t *const blx, const int x, const int y)
{
        XSizeHints hints;

        hints.flags = PPosition;
        hints.x     = x;
        hints.y     = y;

        XSetWMNormalHints(blx->display, blx->window, &hints);
}

void blx_set_title(blx_t *const blx, const char* const title)
{
        XStoreName(blx->display, blx->window, title);
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

void blx_clear_window(blx_t *const blx)
{
        XClearWindow(blx->display, blx->window);
}

void blx_show(blx_t *const blx)
{
        XMapWindow(blx->display, blx->window);
}

void blx_hide(blx_t *const blx)
{
        XUnmapWindow(blx->display, blx->window);
}

void blx_destroy(blx_t **const blx)
{
        XCloseDisplay((*blx)->display);

        free(*blx);
        *blx = NULL;
}
