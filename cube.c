#include "cube.h"

#include <stdio.h>

// cubeの初期化
// 全面そろえる
void init_cube(CUBE *p_cube) {
    for (int i = 0; i < 9; i++) {
        p_cube->cube[TOP_FACE][i] = WHITE;
        p_cube->cube[BOTTOM_FACE][i] = YELLOW;
        p_cube->cube[FRONT_FACE][i] = RED;
        p_cube->cube[BACK_FACE][i] = ORANGE;
        p_cube->cube[LEFT_FACE][i] = BLUE;
        p_cube->cube[RIGHT_FACE][i] = GREEN;
    }
}

// cubeの表示
void display_cube(const CUBE *p_cube) {
    const char color_chars[] = "WYROBG";
    // 各色に対応するANSIエスケープシーケンス
    const char *color_sequences[] = {
        "\x1b[30;47m",   // WHITE
        "\x1b[30;43m",   // YELLOW
        "\x1b[37;41m",   // RED
        "\x1b[37;101m",  // ORANGE
        "\x1b[37;44m",   // BLUE
        "\x1b[37;42m"    // GREEN
    };
    // リセット
    const char *RESET_COLOR = "\x1b[0m";

    printf("\n");

    // TOP_FACE
    for (int i = 0; i < 3; i++) {
        printf("         ");  // 見た目のための空白
        for (int j = 0; j < 3; j++) {
            int color_index = p_cube->cube[TOP_FACE][3 * i + j];
            printf("%s %c %s", color_sequences[color_index],
                   color_chars[color_index], RESET_COLOR);
        }
        printf("\n");
    }

    // LEFT_FACE, FRONT_FACE, RIGHT_FACE, BACK_FACE
    for (int i = 0; i < 3; i++) {
        // LEFT_FACE
        for (int j = 0; j < 3; j++) {
            int color_index = p_cube->cube[LEFT_FACE][3 * i + j];
            printf("%s %c %s", color_sequences[color_index],
                   color_chars[color_index], RESET_COLOR);
        }

        // FRONT_FACE
        for (int j = 0; j < 3; j++) {
            int color_index = p_cube->cube[FRONT_FACE][3 * i + j];
            printf("%s %c %s", color_sequences[color_index],
                   color_chars[color_index], RESET_COLOR);
        }

        // RIGHT_FACE
        for (int j = 0; j < 3; j++) {
            int color_index = p_cube->cube[RIGHT_FACE][3 * i + j];
            printf("%s %c %s", color_sequences[color_index],
                   color_chars[color_index], RESET_COLOR);
        }

        // BACK_FACE
        for (int j = 0; j < 3; j++) {
            int color_index = p_cube->cube[BACK_FACE][3 * i + j];
            printf("%s %c %s", color_sequences[color_index],
                   color_chars[color_index], RESET_COLOR);
        }
        printf("\n");
    }

    // BOTTOM_FACE
    for (int i = 0; i < 3; i++) {
        printf("         ");  // 見た目のための空白
        for (int j = 0; j < 3; j++) {
            int color_index = p_cube->cube[BOTTOM_FACE][3 * i + j];
            printf("%s %c %s", color_sequences[color_index],
                   color_chars[color_index], RESET_COLOR);
        }
        printf("\n");
    }
}

// 上面を90度時計回りで回転
void rotate_T(CUBE *p_cube) {
    // TOP_FACEの移動
    // // 角
    int temp0 = p_cube->cube[TOP_FACE][0];
    int temp1 = p_cube->cube[TOP_FACE][8];
    p_cube->cube[TOP_FACE][0] = p_cube->cube[TOP_FACE][6];
    p_cube->cube[TOP_FACE][6] = temp1;
    p_cube->cube[TOP_FACE][8] = p_cube->cube[TOP_FACE][2];
    p_cube->cube[TOP_FACE][2] = temp0;
    // // 真ん中
    temp0 = p_cube->cube[TOP_FACE][1];
    temp1 = p_cube->cube[TOP_FACE][7];
    p_cube->cube[TOP_FACE][1] = p_cube->cube[TOP_FACE][3];
    p_cube->cube[TOP_FACE][3] = temp1;
    p_cube->cube[TOP_FACE][7] = p_cube->cube[TOP_FACE][5];
    p_cube->cube[TOP_FACE][5] = temp0;

    // 側面の移動
    int temp_side[3];
    for (int i = 0; i < 3; i++) {
        temp_side[i] = p_cube->cube[FRONT_FACE][i];
    }
    // RIGHT -> FRONT
    for (int i = 0; i < 3; i++) {
        p_cube->cube[FRONT_FACE][i] = p_cube->cube[RIGHT_FACE][i];
    }
    // BACK -> RIGHT
    for (int i = 0; i < 3; i++) {
        p_cube->cube[RIGHT_FACE][i] = p_cube->cube[BACK_FACE][i];
    }
    // LEFT -> BACK
    for (int i = 0; i < 3; i++) {
        p_cube->cube[BACK_FACE][i] = p_cube->cube[LEFT_FACE][i];
    }
    // FRONT(temp_side) -> LEFT
    for (int i = 0; i < 3; i++) {
        p_cube->cube[LEFT_FACE][i] = temp_side[i];
    }
}
void rotate_B(CUBE *p_cube);
void rotate_F(CUBE *p_cube);
void rotate_B(CUBE *p_cube);
void rotate_L(CUBE *p_cube);
void rotate_R(CUBE *p_cube);
