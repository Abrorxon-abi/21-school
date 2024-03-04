// I WANT TO PLAY WITH YOU
//         YOUR FRIEND, AI

#include <stdio.h>
void pole(int x_ball, int y_ball, int y_p1, int y_p2, int score_l, int score_r);
int main() {
    int x_ball = 40, y_ball = 12, y_p1 = 12, y_p2 = 12;
    int score_l = 0;
    int score_r = 0;
    int traf_x = -1;
    int traf_y = 1;
    while (1) {
        pole(x_ball, y_ball, y_p1, y_p2, score_l, score_r);
        if (score_l == 21) {
            printf("Победил левый игрок\n");
            printf("%d : %d\n", score_l, score_r);
            break;
        } else if (score_r == 21) {
            printf("Победил правый игрок\n");
            printf("%d : %d\n", score_l, score_r);
            break;
        }
        char key;
        scanf("%c", &key);
        if (key == ' ' || key == 'a' || key == 'z' || key == 'k' || key == 'm' || key == 'A' || key == 'Z' ||
            key == 'K' || key == 'M') {
            if ((key == 'a' || key == 'A') && y_p1 >= 2) {
                y_p1 = y_p1 - 1;
            }
            if ((key == 'z' || key == 'Z') && y_p1 <= 20) {
                y_p1 = y_p1 + 1;
            }
            if ((key == 'k' || key == 'K') && y_p2 >= 2) {
                y_p2 = y_p2 - 1;
            }
            if ((key == 'm' || key == 'M') && y_p2 <= 20) {
                y_p2 = y_p2 + 1;
            }
            y_ball += traf_y;
            x_ball += traf_x;
            if (y_ball == 23 || y_ball == 1) {
                traf_y *= -1;
            } else if ((y_ball == y_p2 || y_ball == (y_p2 + 1) || y_ball == (y_p2 + 2)) && x_ball == 78) {
                traf_x *= -1;
            } else if ((y_ball == y_p1 || y_ball == (y_p1 + 1) || y_ball == (y_p1 + 2)) && x_ball == 2) {
                traf_x *= -1;
            } else if (x_ball == 0 || x_ball == 80) {
                if (x_ball == 80) {
                    score_l += 1;
                } else if (x_ball == 0) {
                    score_r += 1;
                }
                x_ball = 40;
                y_ball = 12;
            }
        }
        printf("\e[1;1H\e[2J");
    }
    return 0;
}

void pole(int x_ball, int y_ball, int y_p1, int y_p2, int score_l, int score_r) {
    int score1_left, score1_right, score2_left, score2_right;
    score1_left = score_l / 10;
    score1_right = score_l % 10;
    score2_left = score_r / 10;
    score2_right = score_r % 10;
    for (int y = 0; y < 25; y++) {
        for (int x = 0; x < 80; x++) {
            if (y == 0 || y == 24) {
                printf("%c", 45);
            } else {
                if (y == y_ball && x == x_ball) {
                    printf("%c", 111);
                } else if ((y >= y_p1 && y <= y_p1 + 2) && x == 1) {
                    printf("%c", 124);
                } else if ((y >= y_p2 && y <= y_p2 + 2) && x == 78) {
                    printf("%c", 124);
                } else if (x == 0 || x == 79) {
                    printf("%c", 124);
                } else if (x == 35 && y == 2) {
                    printf("%d", score1_left);
                } else if (x == 36 && y == 2) {
                    printf("%d", score1_right);
                } else if (x == 45 && y == 2) {
                    printf("%d", score2_left);
                } else if (x == 46 && y == 2) {
                    printf("%d", score2_right);
                } else {
                    printf("%c", 32);
                }
            }
        }
        printf("%c", 10);
    }
}
