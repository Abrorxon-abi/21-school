#include <stdio.h>
#include <math.h>

float important_function(float x);

int main() {
    float x;

    if (scanf("%f", &x) != 1) {
        printf("n/a\n");
        return 0;
    }

    printf("%.1f\n", important_function(x));

    return 0;
}

float important_function(float x) {
    return -2070.4 * x;
}
