#include <stdio.h>

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

int inputShift(int *shift) {
    float shi;
    if (scanf("%f", &shi) > 1 || shi != (float)((int)shi)) {
        return 0;
    };
    *shift = (int)shi;
    if (getchar() != '\n') {
        return 0;
    }
    return 1;
}

void shiftingBuffer(int *buffer, int length, int shift) {
    int temp[length];
    for (int i = 0; i < length; i++) {
        temp[i >= shift % length ? (i - (shift % length)) % length
                                 : ((i + length) - (shift % length)) % length] = buffer[i];
    }
    for (int i = 0; i < length; i++) {
        buffer[i] = temp[i];
    }
}

void output(int *buffer, int length) {
    for (int i = 0; i < length; i++) {
        if (i == length - 1) {
            printf("%d", buffer[i]);
        } else {
            printf("%d ", buffer[i]);
        }
    }
}

int main() {
    int buffer[10], length, shift;
    if (input(buffer, &length) && inputShift(&shift)) {
        shiftingBuffer(buffer, length, shift);
        output(buffer, length);
    } else {
        printf("n/a");
    }
}