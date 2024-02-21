#include <stdio.h>

int input(int *buffer, int *length);
void output(int *buffer, int length);
int sum_numbers(int *buffer, int length);
int find_numbers(int *buffer, int length, int number, int *numbers);

int main() {
    int buffer[10], length;
    if (!input(buffer, &length)) {
        printf("n/a");
        return 0;
    }
    output(buffer, length);
    return 0;
}

int input(int *buffer, int *length) {
    float len;
    if (scanf("%f", &len) > 1 || len != (float)((int)len) || len > 10 || len <= 0) {
        return 0;
    };
    *length = (int)len;
    for (int i = 0; i < (int)len; i++) {
        if (scanf("%d", &buffer[i]) != 1) {
            return 0;
        }
    }
    if (getchar() != '\n') {
        return 0;
    }
    return 1;
}

void output(int *buffer, int length) {
    int number = sum_numbers(buffer, length), numbers[10],
        newLength = find_numbers(buffer, length, number, numbers);
    if (newLength) {
        printf("%d\n", number);
        for (int i = 0; i < newLength; i++) {
            if (i == newLength - 1) {
                printf("%d", numbers[i]);
            } else {
                printf("%d ", numbers[i]);
            }
        }

    } else {
        printf("n/a");
    }
}

int sum_numbers(int *buffer, int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] % 2 == 0) {
            sum += buffer[i];
        }
    }
    return sum;
}

int find_numbers(int *buffer, int length, int number, int *numbers) {
    int index = 0;
    if (number == 0) {
        return 0;
    }
    for (int i = 0; i < length; i++) {
        if (buffer[i] != 0 && number % buffer[i] == 0) {
            numbers[index] = buffer[i];
            index++;
        }
    }
    return index;
}