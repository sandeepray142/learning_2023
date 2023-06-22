#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 100
#define MAX_LINE_LENGTH 100

typedef struct {
    int entryNo;
    char sensorNo[10];
    float temperature;
    int humidity;
    int light;
    char timestamp[9];
} LogEntry;

LogEntry logEntries[MAX_LOG_ENTRIES];
int numLogEntries = 0;

void extractLogEntries() {
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Unable to open data.csv\n");
        return;
    }

    char line[MAX_LINE_LENGTH];
    fgets(line, sizeof(line), file); // Skip the header line

    while (fgets(line, sizeof(line), file) != NULL) {
        char *token = strtok(line, ",");
        int i = 0;

        while (token != NULL) {
            switch (i) {
                case 0:
                    logEntries[numLogEntries].entryNo = atoi(token);
                    break;
                case 1:
                    strcpy(logEntries[numLogEntries].sensorNo, token);
                    break;
                case 2:
                    logEntries[numLogEntries].temperature = atof(token);
                    break;
                case 3:
                    logEntries[numLogEntries].humidity = atoi(token);
                    break;
                case 4:
                    logEntries[numLogEntries].light = atoi(token);
                    break;
                case 5:
                    strcpy(logEntries[numLogEntries].timestamp, token);
                    break;
                default:
                    break;
            }

            token = strtok(NULL, ",");
            i++;
        }

        numLogEntries++;
    }

    fclose(file);
}

void displayLogEntries() {
    if (numLogEntries == 0) {
        printf("No log entries found.\n");
        return;
    }

    printf("Log Entries:\n");
    for (int i = 0; i < numLogEntries; i++) {
        printf("Entry No: %d\n", logEntries[i].entryNo);
        printf("Sensor No: %s\n", logEntries[i].sensorNo);
        printf("Temperature: %.1f\n", logEntries[i].temperature);
        printf("Humidity: %d\n", logEntries[i].humidity);
        printf("Light: %d\n", logEntries[i].light);
        printf("Timestamp: %s\n", logEntries[i].timestamp);
        printf("\n");
    }
}

int main() {
    extractLogEntries();
    displayLogEntries();
    return 0;
}
