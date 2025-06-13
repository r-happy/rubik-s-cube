#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "cube.h"

int main(void) {
    srand((time(NULL)));
    CUBE cube;

    init_cube(&cube);
    printf("初期状態\n");
    display_cube(&cube);

    int num_moves = 100;
    shuffle_cube(&cube, num_moves);

    printf("結果");
    display_cube(&cube);

    return 0;
}
