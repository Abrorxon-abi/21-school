#include <stdio.h>

int main() {
    float x, y;

    if (scanf("%f %f", &x, &y) != 2) {
        printf("n/a\n");
        return 0;
    }

    if (x * x + y * y <= 25) {
        printf("GOTCHA\n"); 
    } else {
        printf("MISS\n");   
    }

    return 0;
}
