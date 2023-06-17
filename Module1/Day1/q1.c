#include <stdio.h>

// Function to find the biggest of two numbers using if-else
int findMaxUsingIfElse(int num1, int num2) {
    if (num1 > num2) {
        return num1;
    } else {
        return num2;
    }
}

// Function to find the biggest of two numbers using the ternary operator
int findMaxUsingTernary(int num1, int num2) {
    int max = (num1 > num2) ? num1 : num2;
    return max;
}

int main() {
    int number1, number2;

    printf("Enter the first number: ");
    scanf("%d", &number1);

    printf("Enter the second number: ");
    scanf("%d", &number2);

    // Using if-else
    int maxUsingIfElse = findMaxUsingIfElse(number1, number2);
    printf("The biggest number using if-else is: %d\n", maxUsingIfElse);

    // Using ternary operator
    int maxUsingTernary = findMaxUsingTernary(number1, number2);
    printf("The biggest number using the ternary operator is: %d\n", maxUsingTernary);

    return 0;
}
