#include <stdio.h>

#include "cube.h"

int main(void) {
    CUBE cube;

    init_cube(&cube);
    display_cube(&cube);
    rotate_T(&cube);
    rotate_T(&cube);
    display_cube(&cube);

    return 0;
}
