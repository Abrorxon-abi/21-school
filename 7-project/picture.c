#include <stdio.h>

#define N 15
#define M 13

void transform(int *buf, int **matr, int n, int m);
void make_picture(int **picture, int n, int m);
void reset_picture(int **picture, int n, int m);

int main() {
    int picture_data[N][M];
    int *picture[N];
    transform(*picture_data, picture, N, M);

    make_picture(picture, N, M);
}

void make_picture(int **picture, int n, int m) {
    int frame_w[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int frame_h[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int tree_trunk[] = {7, 7, 7, 7};
    int tree_foliage[] = {3, 3, 3, 3};
    int sun_data[6][5] = {{0, 6, 6, 6, 6}, {0, 0, 6, 6, 6}, {0, 0, 6, 6, 6},
                          {0, 6, 0, 0, 6}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};

    reset_picture(picture, n, m);

    int length_frame_h = sizeof(frame_h) / sizeof(frame_h[0]);
    int length_frame_w = sizeof(frame_w) / sizeof(frame_w[0]);
    int length_tree_trunk = sizeof(tree_trunk) / sizeof(tree_trunk[0]);
    for (int i = 0; i < length_frame_w; i++) {
        picture[0][i] = frame_w[i];
        picture[length_frame_h / 2][i] = frame_w[i];
        picture[length_frame_h - 1][i] = frame_w[i];
    }
    for (int i = 0; i < length_frame_h; i++) {
        picture[i][0] = frame_h[i];
        picture[i][length_frame_w / 2] = frame_h[i];
        picture[i][length_frame_w - 1] = frame_h[i];
    }
    int sun_data_i = -1, sun_data_j = 0;
    for (int i = 0; i < length_frame_h; i++) {
        for (int j = 0; j < length_frame_w; j++) {
            if (i > 0 && i < length_frame_h / 2 && j > length_frame_w / 2 && j < length_frame_w - 1) {
                picture[i][j] = sun_data[sun_data_i][sun_data_j];
                sun_data_j++;
            }
            if (i == 2 && j == 3) {
                for (int k = 0; k < length_tree_trunk; k++) {
                    picture[i + k][j] = tree_foliage[k];
                    picture[i + k][j + 1] = tree_foliage[k];
                }
            }
            if (i == 3 && j == 2) {
                for (int k = 0; k < length_tree_trunk; k++) {
                    picture[i][j + k] = tree_foliage[k];
                    picture[i + 1][j + k] = tree_foliage[k];
                }
            }
            if ((i == length_frame_h / 2 - 1 || i == length_frame_h / 2 + 1 || i == length_frame_h / 2 + 2 ||
                 i == length_frame_h / 2 + 3) &&
                j == 3) {
                for (int k = 0; k < length_tree_trunk; k++) {
                    picture[i][j] = tree_trunk[k];
                    picture[i][j + 1] = tree_trunk[k];
                }
            }
            if (i == (length_frame_h / 2 + length_frame_h / 4) && j == 2) {
                for (int k = 0; k < length_tree_trunk; k++) {
                    picture[i][j + k] = tree_trunk[k];
                }
            }
        }
        sun_data_j = 0;
        sun_data_i++;
    }

    for (int i = 0; i < length_frame_h; i++) {
        for (int j = 0; j < length_frame_w; j++) {
            printf("%d ", picture[i][j]);
        }
        printf("\n");
    }
}

void reset_picture(int **picture, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            picture[i][j] = 0;
        }
    }
}

void transform(int *buf, int **matr, int n, int m) {
    for (int i = 0; i < n; i++) {
        matr[i] = buf + i * m;
    }
}