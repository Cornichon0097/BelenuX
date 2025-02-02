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
#ifndef BLX_DRAW_H
#define BLX_DRAW_H

void blx_dpoint(blx_t *blx, int x, int y);

void blx_dline(blx_t *blx, int x1, int y1, int x2, int y2);

void blx_drec(blx_t *blx, int x, int y,
              unsigned int width, unsigned int height);

void blx_frec(blx_t *blx, int x, int y,
              unsigned int width, unsigned int height);

void blx_darc(blx_t *blx, int x, int y,
              unsigned int width, unsigned int height,
              int angle1, int angle2);

void blx_farc(blx_t *blx, int x, int y,
              unsigned int width, unsigned int height,
              int angle1, int angle2);

#endif /* blx/draw.h */
