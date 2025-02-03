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
#ifndef BLX_WINDOW_H
#define BLX_WINDOW_H

#include <string.h>

#define BLX_CLOSE_OP(blx, e) ((e->type == ClientMessage) \
                              && ((Atom) e->xclient.data.l[0] == blx->close_op))

#define blx_dtext(blx, x, y, text) (XDrawString((blx)->display, (blx)->window, (blx)->gc, (x), (y), (text), strlen(text)))

blx_t *blx_create(unsigned int width, unsigned int height);

void blx_set_title(blx_t *blx, const char *title);

void blx_set_location(blx_t *blx, int x, int y);

void blx_set_size(blx_t *blx, unsigned int width, unsigned int height);

void blx_fixe_size(blx_t *blx);

void blx_show(blx_t *blx);

void blx_hide(blx_t *blx);

void blx_clear(blx_t *blx);

void blx_destroy(blx_t **blx);

void blx_loop(blx_t *blx, int (*update)(blx_t *));

#endif /* blx/window.h */
