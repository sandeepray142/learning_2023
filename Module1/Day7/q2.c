#include <stdio.h>
#include <ctype.h>
#include <string.h>

void convertToUpper(FILE *source, FILE *destination) {
    int ch;
    while ((ch = fgetc(source)) != EOF) {
        fputc(toupper(ch), destination);
    }
}

void convertToLower(FILE *source, FILE *destination) {
    int ch;
    while ((ch = fgetc(source)) != EOF) {
        fputc(tolower(ch), destination);
    }
}

void convertToSentenceCase(FILE *source, FILE *destination) {
    int ch;
    int capitalize = 1; // Start new sentence with a capital letter
    while ((ch = fgetc(source)) != EOF) {
        if (capitalize) {
            fputc(toupper(ch), destination);
            capitalize = 0;
        } else {
            fputc(tolower(ch), destination);
        }

        if (ch == '.' || ch == '?' || ch == '!') {
            capitalize = 1; // Next sentence will start with a capital letter
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Insufficient arguments.\n");
        printf("Usage: ./cp -u/-l/-s source_file destination_file\n");
        return 1;
    }

    char *option = argv[1];
    char *sourceFileName = argv[2];
    char *destinationFileName = argv[3];

    FILE *sourceFile = fopen(sourceFileName, "r");
    if (sourceFile == NULL) {
        printf("Unable to open source file.\n");
        return 1;
    }

    FILE *destinationFile = fopen(destinationFileName, "w");
    if (destinationFile == NULL) {
        printf("Unable to open destination file.\n");
        fclose(sourceFile);
        return 1;
    }

    if (strcmp(option, "-u") == 0) {
        convertToUpper(sourceFile, destinationFile);
    } else if (strcmp(option, "-l") == 0) {
        convertToLower(sourceFile, destinationFile);
    } else if (strcmp(option, "-s") == 0) {
        convertToSentenceCase(sourceFile, destinationFile);
    } else {
        int ch;
        while ((ch = fgetc(sourceFile)) != EOF) {
            fputc(ch, destinationFile);
        }
    }

    printf("File copied successfully.\n");

    fclose(sourceFile);
    fclose(destinationFile);

    return 0;
}
