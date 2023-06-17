#include <stdio.h>

void findSmallestAndLargestDigits(int n, int nums[]) {
    int smallest = 9;
    int largest = 0;

    for (int i = 0; i < n; i++) {
        int current = nums[i];

        while (current != 0) {
            int digit = current % 10;

            if (digit < smallest) {
                smallest = digit;
            }

            if (digit > largest) {
                largest = digit;
            }

            current /= 10;
        }
    }

    printf("Smallest Digit: %d\n", smallest);
    printf("Largest Digit: %d\n", largest);
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("Not Valid\n");
        return 0;
    }

    int nums[n];

    for (int i = 0; i < n; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &nums[i]);
    }

    findSmallestAndLargestDigits(n, nums);

    return 0;
}
