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
#ifndef BLX_EVENT_H
#define BLX_EVENT_H

#define BLX_DEFAULT_CODE 0x0
#define BLX_EXIT_CODE 0xff

#define BLX_CLOSE_OP(blx, e) ((e->type == ClientMessage) \
                              && ((Atom) e->xclient.data.l[0] == blx->close_op))

typedef XEvent blx_event_t;

void blx_run(blx_t *blx, int (*runner)(blx_t *, blx_event_t *));

#endif /* blx/event.h */
