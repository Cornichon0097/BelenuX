#ifndef BLX_DISPLAY_H
#define BLX_DISPLAY_H

#include <blx/types.h>

blx_t *blx_create(int x, int y, unsigned int width, unsigned int height);

void blx_map(blx_t *blx);

void blx_unmap(blx_t *blx);

void blx_destroy(blx_t **blx);

#endif /* display.h */
