#include <stdio.h>

int stringToInt(const char* str) {
    int result = 0;
    int sign = 1;
    int i = 0;

    if (str[0] == '-') {
        sign = -1;
        i = 1;
    }

    while (str[i] != '\0') {
        result = result * 10 + (str[i] - '0');
        i++;
    }

    return sign * result;
}

int main() {
    char str[] = "5278";
    int number = stringToInt(str);

    printf("String: %s\n", str);
    printf("Integer: %d\n", number);

    return 0;
}
