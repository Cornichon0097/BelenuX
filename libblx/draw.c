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
#include <blx/types.h>
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
        XFlush(blx->display);
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
