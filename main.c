#include <stdio.h>

#include "cube.h"

int main(void) {
    CUBE cube;

    init_cube(&cube);
    display_cube(&cube);
    // two_rotate_U(&cube);
    rotate_R(&cube);
    display_cube(&cube);
    rotate_L(&cube);
    display_cube(&cube);

    return 0;
}
