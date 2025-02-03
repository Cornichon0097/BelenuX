#include <stdlib.h>
#include <stdio.h>

#include <unistd.h>

#include <blx/blx.h>

int update(blx_t *const blx)
{
        blx_dtext(blx, 20, 20, "Hello world!");

        return 0;
}

int main(const int argc, char *const argv[])
{
        blx_t *blx;
        int opt;

        while ((opt = getopt(argc, argv, "v")) != -1) {
                switch (opt) {
                case 'v':
                        printf("%s version %d.%d\n", argv[0],
                               BELENUX_VERSION_MAJOR, BELENUX_VERSION_MINOR);
                        exit(EXIT_SUCCESS);
                        break;
                default:
                        exit(EXIT_FAILURE);
                        break;
                }
        }

        blx = blx_create(100, 100);
        blx_show(blx);
        blx_loop(blx, &update);
        blx_destroy(&blx);

        return EXIT_SUCCESS;
}
