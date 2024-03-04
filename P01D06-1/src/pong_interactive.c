// NOTE: Run file with "-lncurses" flag: gcc file_name -lncurses

#include <ncurses.h>
#include <stdio.h>
#include <unistd.h>

#define STR 25
#define ROW 80

void frame(char field[STR][ROW]);
int racket(char field[STR][ROW], int *left_racket, int *right_racket);
void ball(char field[STR][ROW], int left_racket, int right_racket, int *ball_i, int *ball_j, int *dir_x,
          int *dir_y);
void goal(int *score, int *left_racket, int *right_racket, int *ball_i, int *ball_j, int *dir_x, int *dir_y);
void draw_field(char field[STR][ROW]);

int main() {
    char field[STR][ROW];
    int left_racket = STR / 2, right_racket = STR / 2;
    int ball_i = STR / 2, ball_j = ROW / 2;
    int dir_y = 1, dir_x = 1;
    int left_score = 0, right_score = 0;
    char winner = 'n';
    char input = 'f';

    initscr();

    do {
        nodelay(stdscr, true);

        frame(field);
        input = racket(field, &left_racket, &right_racket);
        ball(field, left_racket, right_racket, &ball_i, &ball_j, &dir_x, &dir_y);

        if (ball_j == 1)
            goal(&right_score, &left_racket, &right_racket, &ball_i, &ball_j, &dir_x, &dir_y);
        else if (ball_j == ROW - 2)
            goal(&left_score, &left_racket, &right_racket, &ball_i, &ball_j, &dir_x, &dir_y);

        clear();
        if (left_score == 21) {
            winner = 'l';
            break;
        } else if (right_score == 21) {
            winner = 'r';
            break;
        }
        usleep(80 * 1000);
        mvprintw(0, 0, "LEFT PLAYER score = %d\n", left_score);
        mvprintw(0, 58, "RIGHT PLAYER SCORE = %d\n", right_score);

        draw_field(field);
    } while (input != 'q');

    endwin();

    if (winner == 'l') {
        printf("LEFT PLAYER WON!\n");
    } else if (winner == 'r') {
        printf("RIGHT PLAYER WON!\n");
    }

    return 0;
}

void frame(char field[STR][ROW]) {
    for (int i = 0; i < STR; i++) {
        for (int j = 0; j < ROW; j++) {
            if (i == 0 || i == STR - 1) {
                field[i][j] = '-';
            } else if (j == 0 || j == ROW - 1) {
                field[i][j] = '|';
            } else if (j == ROW / 2) {
                field[i][j] = '|';
            } else {
                field[i][j] = ' ';
            }
        }
    }
}

int racket(char field[STR][ROW], int *left_racket, int *right_racket) {
    char input = getch();

    int step = 1;

    switch (input) {
        case 'a': {
            if ((*left_racket) > step + 2) (*left_racket) -= step;
            break;
        }
        case 'z': {
            if ((*left_racket) < STR - 2) (*left_racket) += step;
            break;
        }
        case 'k': {
            if ((*right_racket) > step + 2) (*right_racket) -= step;
            break;
        }
        case 'm': {
            if ((*right_racket) < STR - 2) (*right_racket) += step;
            break;
        }
    }

    field[*left_racket][1] = '|';
    field[*left_racket - 1][1] = '|';
    field[*left_racket - 2][1] = '|';

    field[*right_racket][ROW - 2] = '|';
    field[*right_racket - 1][ROW - 2] = '|';
    field[*right_racket - 2][ROW - 2] = '|';

    return input;
}

void ball(char field[STR][ROW], int left_racket, int right_racket, int *ball_i, int *ball_j, int *dir_x,
          int *dir_y) {
    if ((*ball_i) == 1 && (*dir_y) == -1)
        (*dir_y) *= -1;
    else if ((*ball_i) == STR - 2 && (*dir_y) == 1)
        (*dir_y) *= -1;

    if ((*ball_j) == 2 && (*dir_x) == -1) {
        for (int i = -1; i <= 1; ++i) {
            if ((*ball_i) >= left_racket + i && (*ball_i) <= left_racket + 2 && field[*ball_i][1] == '|') {
                (*dir_x) *= -1;
                break;
            }
        }
    }

    if ((*ball_j) == ROW - 3 && (*dir_x) == 1) {
        for (int i = -1; i <= 1; ++i) {
            if ((*ball_i) >= right_racket + i && (*ball_i) <= right_racket + 2 &&
                field[*ball_i][ROW - 2] == '|') {
                (*dir_x) *= -1;
                break;
            }
        }
    }

    (*ball_i) += (*dir_y);
    (*ball_j) += (*dir_x);

    field[*ball_i][*ball_j] = 'o';
}

void goal(int *score, int *left_racket, int *right_racket, int *ball_i, int *ball_j, int *dir_x, int *dir_y) {
    (*score)++;

    *left_racket = STR / 2;
    *right_racket = STR / 2;

    *ball_i = STR / 2;
    *ball_j = ROW / 2;
    (*dir_x) *= -1;
    (*dir_y) *= -1;
}

void draw_field(char field[STR][ROW]) {
    for (int i = 0; i < STR; i++) {
        for (int j = 0; j < ROW; j++) {
            printw("%c", field[i][j]);
        }
        printw("\n");
    }
}