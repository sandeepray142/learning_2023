#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long computeTotalSeconds(const char* timeStr) {
    char* timeCopy = strdup(timeStr); // Create a mutable copy of the input string
    char* token;
    char* delimiter = ":";
    unsigned long hours, minutes, seconds;

    // Split timeCopy into hours, minutes, and seconds
    token = strtok(timeCopy, delimiter);
    hours = strtoul(token, NULL, 10);

    token = strtok(NULL, delimiter);
    minutes = strtoul(token, NULL, 10);

    token = strtok(NULL, delimiter);
    seconds = strtoul(token, NULL, 10);

    // Free the allocated memory for timeCopy
    free(timeCopy);

    // Compute total seconds
    unsigned long totalSeconds = hours * 3600 + minutes * 60 + seconds;

    return totalSeconds;
}

int main() {
    const char* timeStr = "10:12:50";
    unsigned long totalSeconds = computeTotalSeconds(timeStr);

    printf("Input String: %s\n", timeStr);
    printf("Total Seconds: %lu\n", totalSeconds);

    return 0;
}
