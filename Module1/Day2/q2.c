#include <stdio.h>

// Generic swap function using pointers
void swap(void* ptr1, void* ptr2, size_t size) {
    // Create a temporary buffer to hold the data during the swap
    char temp[size];

    // Copy data from ptr1 to temp
    char* charPtr1 = (char*)ptr1;
    char* charPtr2 = (char*)ptr2;
    for (size_t i = 0; i < size; i++) {
        temp[i] = charPtr1[i];
    }

    // Copy data from ptr2 to ptr1
    for (size_t i = 0; i < size; i++) {
        charPtr1[i] = charPtr2[i];
    }

    // Copy data from temp to ptr2
    for (size_t i = 0; i < size; i++) {
        charPtr2[i] = temp[i];
    }
}

int main() {
    int num1 = 5, num2 = 10;
    float float1 = 3.14, float2 = 2.71828;
    char char1 = 'A', char2 = 'B';

    printf("Before swap:\n");
    printf("num1 = %d, num2 = %d\n", num1, num2);
    printf("float1 = %f, float2 = %f\n", float1, float2);
    printf("char1 = %c, char2 = %c\n", char1, char2);

    swap(&num1, &num2, sizeof(int));
    swap(&float1, &float2, sizeof(float));
    swap(&char1, &char2, sizeof(char));

    printf("\nAfter swap:\n");
    printf("num1 = %d, num2 = %d\n", num1, num2);
    printf("float1 = %f, float2 = %f\n", float1, float2);
    printf("char1 = %c, char2 = %c\n", char1, char2);

    return 0;
}
