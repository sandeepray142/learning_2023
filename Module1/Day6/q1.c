#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void parseString(char* input, struct Student* students, int size) {
    char* token;
    int i = 0;

    token = strtok(input, " "); // Split input string by space

    while (token != NULL && i < size) {
        students[i].rollno = atoi(token);
        token = strtok(NULL, " "); // Move to the next token

        strncpy(students[i].name, token, sizeof(students[i].name) - 1);
        students[i].name[sizeof(students[i].name) - 1] = '\0'; // Ensure null-termination
        token = strtok(NULL, " "); // Move to the next token

        students[i].marks = atof(token);
        token = strtok(NULL, " "); // Move to the next token

        i++;
    }
}

int main() {
    int size;
    printf("Enter the number of students: ");
    scanf("%d", &size);
    getchar(); // Clear the newline character from the input buffer

    struct Student* students = malloc(size * sizeof(struct Student));

    printf("Enter student details:\n");
    for (int i = 0; i < size; i++) {
        char input[100];
        fgets(input, sizeof(input), stdin);

        // Remove newline character from the input
        if (input[strlen(input) - 1] == '\n')
            input[strlen(input) - 1] = '\0';

        parseString(input, students, size); // Pass students array directly, without &
    }

    // Print the initialized array of structures
    printf("\nStudent Details:\n");
    for (int i = 0; i < size; i++) {
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n\n", students[i].marks);
    }

    free(students); // Free the allocated memory

    return 0;
}
