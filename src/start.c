#include <stdlib.h>
#include <stdio.h>

#include <unistd.h>

#include <version.h>
#include <blx/blx.h>

int main(const int argc, char *const argv[])
{
        blx_t *blx;
        int opt;

        while ((opt = getopt(argc, argv, "v")) != -1) {
                switch (opt) {
                case 'v':
                        printf("%s version %d.%d\n", argv[0],
                               BELENOX_VERSION_MAJOR, BELENOX_VERSION_MINOR);
                        exit(EXIT_SUCCESS);
                        break;
                default:
                        break;
                }
        }

        blx = blx_create(100, 0, 100, 100);

        blx_map(blx);

        XSetForeground(blx->display, blx->gc, BLACK);
        while (blx_open(blx)) {
                blx_frec(blx, 0, 0, 100, 100);
        }

        blx_destroy(&blx);

        return EXIT_SUCCESS;
}
