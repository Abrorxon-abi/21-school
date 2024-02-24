#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define STROKI 25
#define STOLBCI 80
#define MAX_GENERATIONS 1000

void output_txt(int array[][STOLBCI]);

void view(int array[][STOLBCI]) {
    int i;
    int j;
    for (j = 0; j < STROKI; j++) {
        for (i = 0; i < STOLBCI; i++) {
            if (array[j][i] == 1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

int sosedi(int array[][STOLBCI], int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;

            int xposition = (x + i + STROKI) % STROKI;
            int yposition = (y + j + STOLBCI) % STOLBCI;

            count += array[xposition][yposition];
        }
    }

    return count;
}
void update_board(int array[][STOLBCI]) {
    int new_array[STROKI][STOLBCI];

    for (int i = 0; i < STROKI; i++) {
        for (int j = 0; j < STOLBCI; j++) {
            int neighbours = sosedi(array, i, j);

            if (array[i][j]) {
                new_array[i][j] = (neighbours == 2 || neighbours == 3);
            } else {
                new_array[i][j] = (neighbours == 3);
            }
        }
    }

    for (int i = 0; i < STROKI; i++) {
        for (int j = 0; j < STOLBCI; j++) {
            array[i][j] = new_array[i][j];
        }
    }
}

void clear_screen() { printf("\033[2J\033[1;1H"); }

void sleep_ms(int ms) { usleep(ms * 1000); }

int main() {
    int array[STROKI][STOLBCI] = {[0] = 0};
    output_txt(array);
    int generation_count = 0;

    while (generation_count < MAX_GENERATIONS) {
        clear_screen();
        view(array);
        update_board(array);

        int speed = 200;
        sleep_ms(speed);
        generation_count++;
    }

    return 0;
}

void output_txt(int array[][STOLBCI]) {
    for (int i = 0; i < STROKI; i++) {
        for (int j = 0; j <= STOLBCI; j++) {
            array[i][j] = (getchar() == '1' ? 1 : 0);
        }
    }
}