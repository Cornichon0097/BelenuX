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

#include <blx/types.h>
#include <blx/event.h>

void blx_loop(blx_t *const blx, int (*runner)(blx_t *, blx_event_t *))
{
        XEvent *event = (XEvent *) malloc(sizeof(XEvent));
        int exit_code;

        do {
                while (XPending(blx->display)) {
                        XNextEvent(blx->display, event);

                        if (BLX_CLOSE_OP(blx, event))
                                exit_code = BLX_EXIT_CODE | runner(blx, event);
                        else
                                exit_code = runner(blx, event);
                }
        } while (!(exit_code & BLX_EXIT_CODE));

        free(event);
}
