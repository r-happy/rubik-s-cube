// 色を定義
#define WHITE 0
#define YELLOW 1
#define RED 2
#define ORANGE 3
#define BLUE 4
#define GREEN 5

// 面の定義
#define TOP_FACE 0
#define BOTTOM_FACE 1
#define FRONT_FACE 2
#define BACK_FACE 3
#define LEFT_FACE 4
#define RIGHT_FACE 5

// 値を保存する構造体の定義
struct _cube {
    int cube[6][9];
};
typedef struct _cube CUBE;

// 関数のプロトタイプ
void init_cube(CUBE *p_cube);
void display_cube(const CUBE *p_cube);
void rotate_T(CUBE *p_cube);
void two_rotate_T(CUBE *p_cube);
void reverse_rotate_T(CUBE *p_cube);
void rotate_B(CUBE *p_cube);
void rotate_F(CUBE *p_cube);
void rotate_B(CUBE *p_cube);
void rotate_L(CUBE *p_cube);
void rotate_R(CUBE *p_cube);
