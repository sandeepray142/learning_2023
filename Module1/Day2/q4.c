#include <stdio.h>

// Function to count the number of set bits in a given number
int countSetBits(int num) {
    int count = 0;
    while (num != 0) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

int main() {
    int array[] = {0x1, 0xF4, 0x10001};
    int length = sizeof(array) / sizeof(array[0]);
    int totalBits = 0;

    for (int i = 0; i < length; i++) {
        totalBits += countSetBits(array[i]);
    }

    printf("Total number of set bits in the array: %d\n", totalBits);

    return 0;
}
