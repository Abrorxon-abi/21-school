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

int main() {
    FILE *file = fopen("door_data.txt", "w");

    if (!file) {
        fprintf(stderr, "error opening file.\n");
        return 1;
    }

    fprintf(file, "%s | %s | %s | %s\n", "Abscissa", "Versiera", "Lemniscate", "Hyperbola");

    for (double x = -M_PI; x <= M_PI; x += M_PI / 21) {
        double versiera_value = versiera(x);
        double lemniscate_value = lemniscate(x);
        double hyperbola_value = hyperbola(x);

        if (isnan(versiera_value) || isnan(lemniscate_value) || isnan(hyperbola_value)) {
            fprintf(file, "%.7f | - | - | -\n", x);

        } else {
            fprintf(file, "%.7f | %.7f | %.7f | %.7f\n", x, versiera_value, lemniscate_value,
                    hyperbola_value);
        }
    }

    fclose(file);

    return 0;
}