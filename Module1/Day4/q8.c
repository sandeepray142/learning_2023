#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isLeapYear(int year) {
    // Check if the year is a leap year
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return 1; // Leap year
    } else {
        return 0; // Not a leap year
    }
}

int countDays(char* date) {
    // Extract day, month, and year from the date string
    char* token;
    char* delimiter = "/";
    int day, month, year;

    token = strtok(date, delimiter);
    day = atoi(token);

    token = strtok(NULL, delimiter);
    month = atoi(token);

    token = strtok(NULL, delimiter);
    year = atoi(token);

    // Array to store the number of days in each month
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Update the number of days in February if it's a leap year
    if (isLeapYear(year)) {
        daysInMonth[1] = 29;
    }

    // Calculate the total number of days
    int totalDays = 0;
    for (int i = 0; i < month - 1; i++) {
        totalDays += daysInMonth[i];
    }
    totalDays += day;

    return totalDays;
}

int main() {
    char date1[] = "10/04/2015";
    char date2[] = "20/12/1995";

    int days1 = countDays(date1);
    int days2 = countDays(date2);

    int daysElapsed = abs(days1 - days2);

    printf("Date 1: %s\n", date1);
    printf("Date 2: %s\n", date2);
    printf("Days Elapsed: %d\n", daysElapsed);

    return 0;
}
