#include <math.h>
#include <stdio.h>

double versiera(double x) { return sin(x) / (1 + cos(x)); }

double lemniscate(double x) { return sqrt(2 * cos(2 * x)); }

double hyperbola(double x) {
    if (x == 0) {
        return -1;
    }

    return 1 / x;
}

void plotFunction(double (*function)(double), double scale_x, double scale_y) {
    for (int row = 0; row < 21; row++) {
        for (int col = 0; col < 42; col++) {
            double x = col * scale_x - M_PI;
            double y = function(x);

            if (fabs(row - 10.5 - y * scale_y) < 0.5) {
                printf("*");
            } else {
                printf(" ");
            }
        }

        printf("\n");
    }
    printf("\n");
}

int main() {
    printf("Versiera:\n");
    plotFunction(versiera, M_PI / 21, 1);

    printf("Lemniscate:\n");
    plotFunction(lemniscate, M_PI / 21, 2);

    printf("Hyperbola:\n");
    plotFunction(hyperbola, M_PI / 21, 10);

    return 0;
}