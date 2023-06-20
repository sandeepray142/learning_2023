#include <stdio.h>

#define SIZE 10

int main() {
    int arr[SIZE] = {64, 84, 20, 36, 12, 90, 72, 10, 45, 60};
    int i, min, max;

    min = max = arr[0]; // Initialize min and max with the first element

    for (i = 1; i < SIZE; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    printf("Array elements: ");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nMinimum value: %d\n", min);
    printf("Maximum value: %d\n", max);

    return 0;
}
