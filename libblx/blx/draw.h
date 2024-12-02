#ifndef BLX_DRAW_H
#define BLX_DRAW_H

#include <blx/types.h>

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
