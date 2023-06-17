#include <stdio.h>

int main() {
    int array[] = {10, 20, 30, 40, 50};
    int length = sizeof(array) / sizeof(array[0]);
    int sum = 0;

    for (int i = 0; i < length; i += 2) {
        sum += array[i];
    }

    printf("Sum of every alternate element: %d\n", sum);

    return 0;
}
