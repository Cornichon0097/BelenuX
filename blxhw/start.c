#include <stdlib.h>
#include <stdio.h>

#include <unistd.h>

#include <blx/blx.h>

int run(__attribute__((unused)) blx_t *const blx, blx_event_t *const event)
{
        switch (event->type) {
        case ButtonPress:
                blx_color(blx, RED);
                blx_frec(blx, 0, 0, 100, 100);
                break;
        default:
                break;
        }

        return BLX_DEFAULT_CODE;
}

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

        blx_color(blx, BLACK);
        blx_frec(blx, 0, 0, 100, 100);

        blx_run(blx, &run);

        blx_destroy(&blx);

        return EXIT_SUCCESS;
}
