#include <stdio.h>

// Function to print numbers from 1 to n
void printForward(int n) {
    for (int i = 1; i <= n; i++) {
        printf("%d", i);
    }
}

// Function to print spaces 
void printSpaces(int n) {
    for (int i = 1; i <= n; i++) {
        printf(" ");
    }
}

// Function to print numbers from n to 1
void printBackward(int n) {
    for (int i = n; i >= 1; i--) {
        printf("%d", i);
    }
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    for (int i = n; i >= 1; i--) {
        printForward(i);
        printSpaces(2 * (n - i));
        printBackward(i);
        printf("\n");
    }

    return 0;
}
