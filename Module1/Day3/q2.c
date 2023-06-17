#include <stdio.h>
#include <stdint.h>

void printBits(uint32_t num) {
    for (int i = 31; i >= 0; i--) {
        uint32_t mask = 1 << i;
        uint32_t bit = (num & mask) >> i;
        printf("%u", bit);
    }
    printf("\n");
}

int main() {
    uint32_t num;
    printf("Enter a 32-bit integer: ");
    scanf("%u", &num);

    printf("Bits: ");
    printBits(num);

    return 0;
}
