#include <stdio.h>

void printExponent(double num) {
    // Create a pointer to the double variable
    unsigned long long* ptr = (unsigned long long*)&num;

    // Extract the exponent bits using bitwise operators
    unsigned long long exponent = (*ptr >> 52) & 0x7FF;

    // Print the exponent in hexadecimal and binary format
    printf("Exponent (Hex): 0x%llx\n", exponent);
    printf("Exponent (Binary): ");
    
    // Print each bit of the exponent in binary format
    for (int i = 10; i >= 0; i--) {
        printf("%llu", (exponent >> i) & 1);
    }
    printf("\n");
}

int main() {
    double x = 0.7;
    
    printf("Double value: %lf\n", x);
    printExponent(x);

    return 0;
}
