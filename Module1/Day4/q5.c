#include <stdio.h>

#define SIZE 10

int main() {
    int arr[SIZE] = {64, 84, 20, 36, 12, 90, 72, 10, 45, 60};
    int sumEvenIndex = 0;
    int sumOddIndex = 0;

    for (int i = 0; i < SIZE; i++) {
        if (i % 2 == 0) {
            sumEvenIndex += arr[i];
        } else {
            sumOddIndex += arr[i];
        }
    }

    int difference = sumEvenIndex - sumOddIndex;

    printf("Array elements: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nSum of elements at even indexes: %d\n", sumEvenIndex);
    printf("Sum of elements at odd indexes: %d\n", sumOddIndex);
    printf("Difference: %d\n", difference);

    return 0;
}
