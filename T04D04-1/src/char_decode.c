#include <stdio.h>

int is_alpha(char c) { return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'); }

int my_atoi(const char *str) {
    int result = 0;
    int sign = 1;
    int i = 0;

    while (str[i] == ' ') {
        i++;
    }

    if (str[i] == '-') {
        sign = -1;
        i++;
    }

    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');
        i++;
    }

    return result * sign;
}

int my_strlen(const char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

void my_strcpy(char *dest, const char *src) {
    int i = 0;
    while ((dest[i] = src[i]) != '\0') {
        i++;
    }
}

char *my_strchr(const char *str, int c) {
    while (*str != '\0') {
        if (*str == c) {
            return (char *)str;
        }
        str++;
    }
    return NULL;
}

char *my_strtok(char *str, const char *delim) {
    static char *last_token = NULL;
    if (str != NULL) {
        last_token = str;
    } else if (last_token == NULL) {
        return NULL;
    }

    char *start = last_token;
    while (*last_token != '\0') {
        if (my_strchr(delim, *last_token) != NULL) {
            *last_token = '\0';
            last_token++;
            return start;
        }
        last_token++;
    }

    last_token = NULL;
    if (*start == '\0') {
        return NULL;
    } else {
        return start;
    }
}

void encode(char *input) {
    char *token = my_strtok(input, " ");
    while (token != NULL) {
        if (my_strlen(token) != 1 || !is_alpha(token[0])) {
            printf("n/a\n");
            return;
        }
        printf("%02X ", token[0]);
        token = my_strtok(NULL, " ");
    }
    printf("\n");
}

void decode(char *input) {
    char *token = my_strtok(input, " ");
    while (token != NULL) {
        int value;
        if (sscanf(token, "%x", &value) != 1 || value < 0 || value > 255) {
            printf("n/a\n");
            return;
        }
        printf("%c ", (char)value);
        token = my_strtok(NULL, " ");
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        return 1;
    }

    int mode = my_atoi(argv[1]);
    if (mode != 0 && mode != 1) {
        return 1;
    }

    char input[100];
    if (fgets(input, sizeof(input), stdin) != NULL) {
        input[my_strlen(input) - 1] = '\0';

        if (mode == 0) {
            encode(input);
        } else {
            decode(input);
        }
    } else {
        return 1;
    }

    return 0;
}
