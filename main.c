#include <stdio.h>

#include "cube.h"

int main(void) {
    CUBE cube;

    init_cube(&cube);
    display_cube(&cube);
    two_rotate_T(&cube);
    display_cube(&cube);
    reverse_rotate_T(&cube);
    reverse_rotate_T(&cube);
    display_cube(&cube);

    return 0;
}
