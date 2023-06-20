#include <stdio.h>

#define SIZE 11

int main() {
    int arr[SIZE] = {12, 84, 20, 36, 64, 56, 72, 10, 45, 90};
    int i, sum = 0;
    float average;

    printf("Array elements: ");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
        sum += arr[i];
    }

    average = (float)sum / SIZE;

    printf("\nSum: %d\n", sum);
    printf("Average: %.2f\n", average);

    return 0;
}
