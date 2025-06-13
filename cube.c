#include "cube.h"

#include <stdio.h>
#include <stdlib.h>

// cubeの初期化
// 全面そろえる
void init_cube(CUBE* p_cube) {
    for (int i = 0; i < 9; i++) {
        p_cube->cube[UP_FACE][i] = WHITE;
        p_cube->cube[DOWN_FACE][i] = YELLOW;
        p_cube->cube[FRONT_FACE][i] = RED;
        p_cube->cube[BACK_FACE][i] = ORANGE;
        p_cube->cube[LEFT_FACE][i] = BLUE;
        p_cube->cube[RIGHT_FACE][i] = GREEN;
    }
}

// cubeの表示
void display_cube(const CUBE* p_cube) {
    const char color_chars[] = "WYROBG";
    // 各色に対応するANSIエスケープシーケンス
    const char* color_sequences[] = {
        "\x1b[30;47m",   // WHITE
        "\x1b[30;43m",   // YELLOW
        "\x1b[37;41m",   // RED
        "\x1b[37;101m",  // ORANGE
        "\x1b[37;44m",   // BLUE
        "\x1b[37;42m"    // GREEN
    };
    // リセット
    const char* RESET_COLOR = "\x1b[0m";

    printf("\n");

    // TOP_FACE
    for (int i = 0; i < 3; i++) {
        printf("         ");  // 見た目のための空白
        for (int j = 0; j < 3; j++) {
            int color_index = p_cube->cube[UP_FACE][3 * i + j];
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
            int color_index = p_cube->cube[DOWN_FACE][3 * i + j];
            printf("%s %c %s", color_sequences[color_index],
                   color_chars[color_index], RESET_COLOR);
        }
        printf("\n");
    }

    printf("\n");
}

// 上面を90度時計回りで回転
void rotate_U(CUBE* p_cube) {
    // TOP_FACEの移動
    // // 角
    int temp0 = p_cube->cube[UP_FACE][0];
    int temp1 = p_cube->cube[UP_FACE][8];
    p_cube->cube[UP_FACE][0] = p_cube->cube[UP_FACE][6];
    p_cube->cube[UP_FACE][6] = temp1;
    p_cube->cube[UP_FACE][8] = p_cube->cube[UP_FACE][2];
    p_cube->cube[UP_FACE][2] = temp0;
    // // 真ん中
    temp0 = p_cube->cube[UP_FACE][1];
    temp1 = p_cube->cube[UP_FACE][7];
    p_cube->cube[UP_FACE][1] = p_cube->cube[UP_FACE][3];
    p_cube->cube[UP_FACE][3] = temp1;
    p_cube->cube[UP_FACE][7] = p_cube->cube[UP_FACE][5];
    p_cube->cube[UP_FACE][5] = temp0;

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

// 上面を2回90度回りで回転
void two_rotate_U(CUBE* p_cube) {
    rotate_U(p_cube);
    rotate_U(p_cube);
}

// 上面を3回90度周りで回転(逆向き一回と同じ)
void reverse_rotate_U(CUBE* p_cube) {
    rotate_U(p_cube);
    rotate_U(p_cube);
    rotate_U(p_cube);
}

// =======================================================
// F (Front) 回転
// =======================================================
// 前面を90度時計回りで回転
void rotate_F(CUBE* p_cube) {
    // FRONT_FACE自体の回転 (U回転と同じロジック)
    int temp0 = p_cube->cube[FRONT_FACE][0];
    int temp1 = p_cube->cube[FRONT_FACE][8];
    p_cube->cube[FRONT_FACE][0] = p_cube->cube[FRONT_FACE][6];
    p_cube->cube[FRONT_FACE][6] = temp1;
    p_cube->cube[FRONT_FACE][8] = p_cube->cube[FRONT_FACE][2];
    p_cube->cube[FRONT_FACE][2] = temp0;
    temp0 = p_cube->cube[FRONT_FACE][1];
    temp1 = p_cube->cube[FRONT_FACE][7];
    p_cube->cube[FRONT_FACE][1] = p_cube->cube[FRONT_FACE][3];
    p_cube->cube[FRONT_FACE][3] = temp1;
    p_cube->cube[FRONT_FACE][7] = p_cube->cube[FRONT_FACE][5];
    p_cube->cube[FRONT_FACE][5] = temp0;

    // 側面ステッカーの移動 (UP -> LEFT -> DOWN -> RIGHT -> UP)
    int temp_side[3];
    // UP面の下段を退避
    for (int i = 0; i < 3; i++) temp_side[i] = p_cube->cube[UP_FACE][6 + i];
    // RIGHT面の左列をUP面の下段へ (向きに注意)
    p_cube->cube[UP_FACE][6] = p_cube->cube[RIGHT_FACE][8];
    p_cube->cube[UP_FACE][7] = p_cube->cube[RIGHT_FACE][5];
    p_cube->cube[UP_FACE][8] = p_cube->cube[RIGHT_FACE][2];
    // DOWN面の上段をRIGHT面の左列へ
    p_cube->cube[RIGHT_FACE][2] = p_cube->cube[DOWN_FACE][0];
    p_cube->cube[RIGHT_FACE][5] = p_cube->cube[DOWN_FACE][1];
    p_cube->cube[RIGHT_FACE][8] = p_cube->cube[DOWN_FACE][2];
    // LEFT面の右列をDOWN面の上段へ (向きに注意)
    p_cube->cube[DOWN_FACE][0] = p_cube->cube[LEFT_FACE][8];
    p_cube->cube[DOWN_FACE][1] = p_cube->cube[LEFT_FACE][5];
    p_cube->cube[DOWN_FACE][2] = p_cube->cube[LEFT_FACE][2];
    // 退避したUP面の下段をLEFT面の右列へ
    p_cube->cube[LEFT_FACE][2] = temp_side[0];
    p_cube->cube[LEFT_FACE][5] = temp_side[1];
    p_cube->cube[LEFT_FACE][8] = temp_side[2];
}

void two_rotate_F(CUBE* p_cube) {
    rotate_F(p_cube);
    rotate_F(p_cube);
}

void reverse_rotate_F(CUBE* p_cube) {
    rotate_F(p_cube);
    rotate_F(p_cube);
    rotate_F(p_cube);
}

// =======================================================
// R (Right) 回転
// =======================================================
// 右面を90度時計回りで回転
void rotate_R(CUBE* p_cube) {
    // RIGHT_FACE自体の回転
    int temp0 = p_cube->cube[RIGHT_FACE][0];
    int temp1 = p_cube->cube[RIGHT_FACE][8];
    p_cube->cube[RIGHT_FACE][0] = p_cube->cube[RIGHT_FACE][6];
    p_cube->cube[RIGHT_FACE][6] = temp1;
    p_cube->cube[RIGHT_FACE][8] = p_cube->cube[RIGHT_FACE][2];
    p_cube->cube[RIGHT_FACE][2] = temp0;
    temp0 = p_cube->cube[RIGHT_FACE][1];
    temp1 = p_cube->cube[RIGHT_FACE][7];
    p_cube->cube[RIGHT_FACE][1] = p_cube->cube[RIGHT_FACE][3];
    p_cube->cube[RIGHT_FACE][3] = temp1;
    p_cube->cube[RIGHT_FACE][7] = p_cube->cube[RIGHT_FACE][5];
    p_cube->cube[RIGHT_FACE][5] = temp0;

    // 側面ステッカーの移動 (UP -> FRONT -> DOWN -> BACK -> UP)
    int temp_side[3];
    // UP面の右列を退避
    temp_side[0] = p_cube->cube[UP_FACE][2];
    temp_side[1] = p_cube->cube[UP_FACE][5];
    temp_side[2] = p_cube->cube[UP_FACE][8];
    // BACK面の左列をUP面の右列へ (向きに注意)
    p_cube->cube[UP_FACE][2] = p_cube->cube[BACK_FACE][6];
    p_cube->cube[UP_FACE][5] = p_cube->cube[BACK_FACE][3];
    p_cube->cube[UP_FACE][8] = p_cube->cube[BACK_FACE][0];
    // DOWN面の右列をBACK面の左列へ (向きに注意)
    p_cube->cube[BACK_FACE][0] = p_cube->cube[DOWN_FACE][8];
    p_cube->cube[BACK_FACE][3] = p_cube->cube[DOWN_FACE][5];
    p_cube->cube[BACK_FACE][6] = p_cube->cube[DOWN_FACE][2];
    // FRONT面の右列をDOWN面の右列へ
    p_cube->cube[DOWN_FACE][2] = p_cube->cube[FRONT_FACE][2];
    p_cube->cube[DOWN_FACE][5] = p_cube->cube[FRONT_FACE][5];
    p_cube->cube[DOWN_FACE][8] = p_cube->cube[FRONT_FACE][8];
    // 退避したUP面の右列をFRONT面の右列へ
    p_cube->cube[FRONT_FACE][2] = temp_side[0];
    p_cube->cube[FRONT_FACE][5] = temp_side[1];
    p_cube->cube[FRONT_FACE][8] = temp_side[2];
}

void two_rotate_R(CUBE* p_cube) {
    rotate_R(p_cube);
    rotate_R(p_cube);
}

void reverse_rotate_R(CUBE* p_cube) {
    rotate_R(p_cube);
    rotate_R(p_cube);
    rotate_R(p_cube);
}

// =======================================================
// L (Left) 回転
// =======================================================
// 左面を90度時計回りで回転
void rotate_L(CUBE* p_cube) {
    // LEFT_FACE自体の回転
    int temp0 = p_cube->cube[LEFT_FACE][0];
    int temp1 = p_cube->cube[LEFT_FACE][8];
    p_cube->cube[LEFT_FACE][0] = p_cube->cube[LEFT_FACE][6];
    p_cube->cube[LEFT_FACE][6] = temp1;
    p_cube->cube[LEFT_FACE][8] = p_cube->cube[LEFT_FACE][2];
    p_cube->cube[LEFT_FACE][2] = temp0;
    temp0 = p_cube->cube[LEFT_FACE][1];
    temp1 = p_cube->cube[LEFT_FACE][7];
    p_cube->cube[LEFT_FACE][1] = p_cube->cube[LEFT_FACE][3];
    p_cube->cube[LEFT_FACE][3] = temp1;
    p_cube->cube[LEFT_FACE][7] = p_cube->cube[LEFT_FACE][5];
    p_cube->cube[LEFT_FACE][5] = temp0;

    // 側面ステッカーの移動 (UP -> BACK -> DOWN -> FRONT -> UP)
    int temp_side[3];
    // UP面の左列を退避
    temp_side[0] = p_cube->cube[UP_FACE][0];
    temp_side[1] = p_cube->cube[UP_FACE][3];
    temp_side[2] = p_cube->cube[UP_FACE][6];
    // FRONT面の左列をUP面の左列へ
    p_cube->cube[UP_FACE][0] = p_cube->cube[FRONT_FACE][0];
    p_cube->cube[UP_FACE][3] = p_cube->cube[FRONT_FACE][3];
    p_cube->cube[UP_FACE][6] = p_cube->cube[FRONT_FACE][6];
    // DOWN面の左列をFRONT面の左列へ
    p_cube->cube[FRONT_FACE][0] = p_cube->cube[DOWN_FACE][0];
    p_cube->cube[FRONT_FACE][3] = p_cube->cube[DOWN_FACE][3];
    p_cube->cube[FRONT_FACE][6] = p_cube->cube[DOWN_FACE][6];
    // BACK面の右列をDOWN面の左列へ (向きに注意)
    p_cube->cube[DOWN_FACE][0] = p_cube->cube[BACK_FACE][8];
    p_cube->cube[DOWN_FACE][3] = p_cube->cube[BACK_FACE][5];
    p_cube->cube[DOWN_FACE][6] = p_cube->cube[BACK_FACE][2];
    // 退避したUP面の左列をBACK面の右列へ (向きに注意)
    p_cube->cube[BACK_FACE][2] = temp_side[2];
    p_cube->cube[BACK_FACE][5] = temp_side[1];
    p_cube->cube[BACK_FACE][8] = temp_side[0];
}

void two_rotate_L(CUBE* p_cube) {
    rotate_L(p_cube);
    rotate_L(p_cube);
}

void reverse_rotate_L(CUBE* p_cube) {
    rotate_L(p_cube);
    rotate_L(p_cube);
    rotate_L(p_cube);
}

// =======================================================
// B (Back) 回転
// =======================================================
// 後面を90度時計回りで回転
void rotate_B(CUBE* p_cube) {
    // BACK_FACE自体の回転
    int temp0 = p_cube->cube[BACK_FACE][0];
    int temp1 = p_cube->cube[BACK_FACE][8];
    p_cube->cube[BACK_FACE][0] = p_cube->cube[BACK_FACE][6];
    p_cube->cube[BACK_FACE][6] = temp1;
    p_cube->cube[BACK_FACE][8] = p_cube->cube[BACK_FACE][2];
    p_cube->cube[BACK_FACE][2] = temp0;
    temp0 = p_cube->cube[BACK_FACE][1];
    temp1 = p_cube->cube[BACK_FACE][7];
    p_cube->cube[BACK_FACE][1] = p_cube->cube[BACK_FACE][3];
    p_cube->cube[BACK_FACE][3] = temp1;
    p_cube->cube[BACK_FACE][7] = p_cube->cube[BACK_FACE][5];
    p_cube->cube[BACK_FACE][5] = temp0;

    // 側面ステッカーの移動 (UP -> RIGHT -> DOWN -> LEFT -> UP)
    int temp_side[3];
    // UP面の上段を退避
    for (int i = 0; i < 3; ++i) temp_side[i] = p_cube->cube[UP_FACE][i];
    // LEFT面の左列をUP面の上段へ (向きに注意)
    p_cube->cube[UP_FACE][0] = p_cube->cube[LEFT_FACE][2];
    p_cube->cube[UP_FACE][1] = p_cube->cube[LEFT_FACE][5];
    p_cube->cube[UP_FACE][2] = p_cube->cube[LEFT_FACE][8];
    // DOWN面の下段をLEFT面の左列へ
    p_cube->cube[LEFT_FACE][2] = p_cube->cube[DOWN_FACE][8];
    p_cube->cube[LEFT_FACE][5] = p_cube->cube[DOWN_FACE][7];
    p_cube->cube[LEFT_FACE][8] = p_cube->cube[DOWN_FACE][6];
    // RIGHT面の右列をDOWN面の下段へ (向きに注意)
    p_cube->cube[DOWN_FACE][6] = p_cube->cube[RIGHT_FACE][0];
    p_cube->cube[DOWN_FACE][7] = p_cube->cube[RIGHT_FACE][3];
    p_cube->cube[DOWN_FACE][8] = p_cube->cube[RIGHT_FACE][6];
    // 退避したUP面の上段をRIGHT面の右列へ
    p_cube->cube[RIGHT_FACE][0] = temp_side[2];
    p_cube->cube[RIGHT_FACE][3] = temp_side[1];
    p_cube->cube[RIGHT_FACE][6] = temp_side[0];
}

void two_rotate_B(CUBE* p_cube) {
    rotate_B(p_cube);
    rotate_B(p_cube);
}

void reverse_rotate_B(CUBE* p_cube) {
    rotate_B(p_cube);
    rotate_B(p_cube);
    rotate_B(p_cube);
}

// =======================================================
// D (Down) 回転
// =======================================================
// 下面を90度時計回りで回転
void rotate_D(CUBE* p_cube) {
    // DOWN_FACE自体の回転
    int temp0 = p_cube->cube[DOWN_FACE][0];
    int temp1 = p_cube->cube[DOWN_FACE][8];
    p_cube->cube[DOWN_FACE][0] = p_cube->cube[DOWN_FACE][6];
    p_cube->cube[DOWN_FACE][6] = temp1;
    p_cube->cube[DOWN_FACE][8] = p_cube->cube[DOWN_FACE][2];
    p_cube->cube[DOWN_FACE][2] = temp0;
    temp0 = p_cube->cube[DOWN_FACE][1];
    temp1 = p_cube->cube[DOWN_FACE][7];
    p_cube->cube[DOWN_FACE][1] = p_cube->cube[DOWN_FACE][3];
    p_cube->cube[DOWN_FACE][3] = temp1;
    p_cube->cube[DOWN_FACE][7] = p_cube->cube[DOWN_FACE][5];
    p_cube->cube[DOWN_FACE][5] = temp0;

    // 側面ステッカーの移動 (FRONT -> LEFT -> BACK -> RIGHT -> FRONT)
    int temp_side[3];
    // FRONT面の下段を退避
    for (int i = 0; i < 3; i++) {
        temp_side[i] = p_cube->cube[FRONT_FACE][6 + i];
    }
    // LEFT -> FRONT
    for (int i = 0; i < 3; i++) {
        p_cube->cube[FRONT_FACE][6 + i] = p_cube->cube[LEFT_FACE][6 + i];
    }
    // BACK -> LEFT
    for (int i = 0; i < 3; i++) {
        p_cube->cube[LEFT_FACE][6 + i] = p_cube->cube[BACK_FACE][6 + i];
    }
    // RIGHT -> BACK
    for (int i = 0; i < 3; i++) {
        p_cube->cube[BACK_FACE][6 + i] = p_cube->cube[RIGHT_FACE][6 + i];
    }
    // 退避したFRONT -> RIGHT
    for (int i = 0; i < 3; i++) {
        p_cube->cube[RIGHT_FACE][6 + i] = temp_side[i];
    }
}

void two_rotate_D(CUBE* p_cube) {
    rotate_D(p_cube);
    rotate_D(p_cube);
}

void reverse_rotate_D(CUBE* p_cube) {
    rotate_D(p_cube);
    rotate_D(p_cube);
    rotate_D(p_cube);
}

// cubeをシャッフル
void shuffle_cube(CUBE* p_cube, int num_moves) {
    printf("%d手シャッフル\n", num_moves);

    for (int i = 0; i < num_moves; i++) {
        int move = rand() % 18;

        switch (move) {
            case 0:
                rotate_U(p_cube);
                break;
            case 1:
                two_rotate_U(p_cube);
                break;
            case 2:
                reverse_rotate_U(p_cube);
                break;
            case 3:
                rotate_F(p_cube);
                break;
            case 4:
                two_rotate_F(p_cube);
                break;
            case 5:
                reverse_rotate_F(p_cube);
                break;
            case 6:
                rotate_R(p_cube);
                break;
            case 7:
                two_rotate_R(p_cube);
                break;
            case 8:
                reverse_rotate_R(p_cube);
                break;
            case 9:
                rotate_L(p_cube);
                break;
            case 10:
                two_rotate_L(p_cube);
                break;
            case 11:
                reverse_rotate_L(p_cube);
                break;
            case 12:
                rotate_B(p_cube);
                break;
            case 13:
                two_rotate_B(p_cube);
                break;
            case 14:
                reverse_rotate_B(p_cube);
                break;
            case 15:
                rotate_D(p_cube);
                break;
            case 16:
                two_rotate_D(p_cube);
                break;
            case 17:
                reverse_rotate_D(p_cube);
                break;
        }
    }
}
