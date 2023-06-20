#include <stdio.h>

#define SIZE 10

int main() {
    int arr[SIZE] = {64, 84, 20, 36, 12, 90, 72, 10, 45, 60};
    int sumOdd = 0;
    int sumEven = 0;

    for (int i = 0; i < SIZE; i++) {
        if (arr[i] % 2 == 0) {
            sumEven += arr[i];
        } else {
            sumOdd += arr[i];
        }
    }

    int difference = sumOdd - sumEven;

    printf("Array elements: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nSum of odd elements: %d\n", sumOdd);
    printf("Sum of even elements: %d\n", sumEven);
    printf("Difference: %d\n", difference);

    return 0;
}
