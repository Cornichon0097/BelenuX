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
#include <blx/color.h>

blx_color_t blx_rgb(int r, int g, int b)
{
        return ((blx_color_t) ((r << 16) | (g << 8) | b));
}

void blx_color(blx_t *const blx, blx_color_t color)
{
        XSetForeground(blx->display, blx->gc, color);
}
