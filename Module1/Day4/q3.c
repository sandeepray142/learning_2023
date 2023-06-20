#include <stdio.h>

#define SIZE 10

int main() {
    int arr[SIZE] = {64, 84, 20, 36, 12, 90, 72, 10, 45, 60};
    int start = 0;
    int end = SIZE - 1;
    int temp;

    printf("Original array: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }

    // Reverse the array
    while (start < end) {
        // Swap elements
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }

    printf("\nReversed array: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
