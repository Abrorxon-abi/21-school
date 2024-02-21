#include <stdio.h>

#define LEN 100

void sum(const int *buff1, int len1, const int *buff2, int len2, int *result, int *result_length);
void sub(const int *buff1, int len1, const int *buff2, int len2, int *result, int *result_length);
int input(int *a);
void output(int *result, int result_length);

int main() {
    int mass1[LEN], mass2[LEN], len1 = 0, len2 = 0;
    for (int i = 0; i < LEN; i++) {
        mass1[i] = 0;
        mass2[i] = 0;
    }  // обнуление массивов
    len1 = input(mass1);
    len2 = input(mass2);
    if (len1 < 0 || len2 < 0) {
        printf("n/a");
    } else {
        int result[LEN + 1] = {0}, result_length;
        sum(mass1, len1, mass2, len2, result, &result_length);
        output(result, result_length);
        printf("\n");
        sub(mass1, len1, mass2, len2, result, &result_length);
        if (((mass1[len1] < mass2[len2]) && (len1 == len2)) || len1 < len2) {
            printf("n/a");
        } else {
            output(result, result_length);
        }
    }
    return 0;
}

int input(int *a) {
    char ch;
    int n = 0, value_read;
    while (n < LEN) {
        value_read = scanf("%d%c", &a[n], &ch);
        if (value_read < 1 || (ch != ' ' && ch != '\n')) {  // Проверка на ввод чисел и разрешённые символы
            // ретёрн в случае ошибки
            return -1;
        }
        if (value_read == 2 && (ch == ' ' || ch == '\n')) {
            if (a[n] > 9 || a[n] < 0) {  // Проверка, что введено число от 0 до 9
                return -1;
            }
            n++;
        }

        if (value_read == 2 && ch == '\n') {  // Если получен перенос строки, завершаем ввод
            break;
        }
    }
    // Переворот массива
    for (int i = 0; i < n / 2; i++) {
        int temp = a[i];
        a[i] = a[n - i - 1];
        a[n - i - 1] = temp;
    }
    return n;
}

void sum(const int *buff1, int len1, const int *buff2, int len2, int *result, int *result_length) {
    int carry = 0;
    int i = 0;
    for (; i < len1 || i < len2; i++) {
        int summ = carry;
        if (i < len1) summ += buff1[i];
        if (i < len2) summ += buff2[i];
        result[i] = summ % 10;
        carry = summ / 10;
    }
    if (carry > 0) result[i++] = carry;
    *result_length = i;
    while (*result_length > 1 && result[*result_length - 1] == 0) {
        (*result_length)--;
    }
}

void output(int *result, int result_length) {
    for (int i = result_length - 1; i >= 0; i--) {
        printf("%d ", result[i]);
    }
    printf("\b");
}

void sub(const int *buff1, int len1, const int *buff2, int len2, int *result, int *result_length) {
    int borrow = 0;
    *result_length = len1;  // максимальная длина длина 1 числа
    for (int i = 0; i < *result_length; ++i) {
        int diff = buff1[i] - (i < len2 ? buff2[i] : 0) - borrow;
        borrow = 0;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        }
        result[i] = diff;
    }

    // Убираем нули спереди если есть
    while (*result_length > 1 && result[*result_length - 1] == 0) {
        (*result_length)--;
    }
}