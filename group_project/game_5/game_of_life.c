#include<stdio.h>
#include<stdlib.h>
void draw(int **field);
void add(char **field, char **start, int x, int y, int lx, int ly);
void in_old(int **field, int **field_old);
int read_file(int init_matrix[25][80]);
void process(int **field_next,  int ** field);
void input();
void clean(int **arr, int n);
void createArr(int **field, int **field_old, int **field_next);
int check(int **field_next, int **field, int **field_old);
int main() {
    int init_matrix[25][80];
    int game_mode = 1, speed = 1;
    int **field= NULL, **field_old = NULL, **field_next = NULL;

    field = malloc(sizeof(int) * 25 * 80 + 25 * sizeof(int*));
    field_old = malloc(sizeof(int) * 25 * 80 + 25 * sizeof(int*));
    field_next = malloc(sizeof(int) * 25 * 80 + 25 * sizeof(int*));

    int * str = (int*) (field + 25);
    int * str1 = (int*) (field_old + 25);
    int * str2 = (int*) (field_next + 25);

    for (int i = 0; i < 25; i++) {
        field[i] = str + 80*i;
        field_old[i] = str1 + 80*i;
        field_next[i] = str2 + 80*i;
    }
    if (read_file(init_matrix) == 1) {
        printf("n/a");
        return 1;
    }
     
    for (int i = 0; i<25; i++) {
        for (int j = 0; j < 80; j++) {
            field[i][j] = init_matrix[i][j];
            field_old[i][j] = 0;
            field_next[i][j] = field[i][j];
        }
    }
    
    draw(field);
    process(field_next, field);

    if (game_mode == 1) {
        while (1) {
            input();
            if (!check(field_next, field, field_old)) {
                for (int i = 0; i < 80; i++) {
                    if (i < 35 || i > 44)
                        printf("-");
                    if (i == 35)
                        printf(" The end! ");
                }
                break;
            }
            in_old(field, field_old);
            process(field, field_old);
            process(field_next, field);
            draw(field);
        }
    }
    else {
        switch (speed) {
            case 1: break;
            case 2: break;
            case 3: break;
            case 4: break;
            case 5: break;
        }
    }
    free(field);
    free(field_old);
    free(field_next);
}
int read_file(int init_matrix[25][80]) {
    int flag = 0;
    for (int i = 0; i < 25; i++) {
        for(int j = 0; j < 80; j++) {
            int read_int = scanf("%d", &init_matrix[i][j]);
            if(read_int == 0 || read_int == EOF) {
                flag = 1;
                break;
            }
        } if(flag) {
            break;
        }
    } freopen("/dev/tty", "r", stdin);
    return flag;
}
int check(int **field_next, int **field, int **field_old) {
    int flag = 0;
    
    for (int i = 0; i < 25; i++)
        for (int j = 0; j < 80; j++)
            if (field[i][j] == field_old[i][j])
                flag++;
    if (flag == 25 * 80) return 0;
    
    for (int i = 0; i < 25; i++)
        for (int j = 0; j < 80; j++)
            if (field[i][j] == 0)
                flag++;
    if (flag == 0) return 0;
    
    for (int i = 0; i < 25; i++)
        for (int j = 0; j < 80; j++)
            if (field_next[i][j] == field_old[i][j])
                flag++;
    if (flag == 25 * 80) {
        int a;
        printf("\nThe cycle is endless. You want continue? (1 -> yes   2 -> no)\nYou answer: ");
        while (!scanf("%d", &a)) printf("\nInpute 1 or 2: ");
        if (a == 2) return 0;
    }
    return 1;
}
void input() {
    int flag = 1;
    char c;
    int scan = scanf("%c", &c);
    if ( scan != 1 || c != ' ' ) {
        flag = 0;
    }
    char d = getchar();
    if ( d != '\n' && d != EOF ) {
        flag = 0;
    }
}
void in_old(int **field, int **field_old) {
    for (int i = 0; i < 25; i++)
        for (int j = 0; j < 80; j++)
            field_old[i][j] = field[i][j];
}
void draw(int **field) {
    for (int i = 0; i < 25; i++)
        for (int j = 0; j < 80; j++) {
            if (i == 24 && j == 79) {
                if (field[i][j] == 0) printf(" ");
                else printf("o");
                break;
            }
            if (j == 79) {
                if (field[i][j] == 0) printf(" \n");
                else printf("o\n");
                break;
            }
            if (field[i][j] == 0) printf(" ");
            else printf("o");
        }
}
void process(int **field, int ** field_old) {
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 80; j++) {
            int count = 0;
            int y[8] = { i - 1, i - 1, i - 1, 
                            i,           i, 
                            i + 1, i + 1, i + 1 }, 
                x[8] = { j - 1, j, j + 1, 
                        j - 1,      j + 1, 
                        j - 1, j, j + 1 };
                        
            for (int t = 0; t < 8; t++) {
                if (t < 3 && y[t] < 0) y[t] = 24;
                if (t > 4 && y[t] > 24) y[t] = 0;
                if ((t == 0 || t == 3 || t == 5) && x[t] < 0) { x[t] = 79; }
                if ((t == 2 || t == 4 || t == 7) && x[t] > 79) { x[t] = 0; }
            }
            for (int k = 0; k < 8; k++)
                if (field_old[y[k]][x[k]] == 1)
                    count++;

            if (field_old[i][j] == 0) {
                if (count == 3)
                    field[i][j] = 1;
            }
            else {
                if (count < 2 || count > 3)
                    field[i][j] = 0;
            }
        }
    }
}