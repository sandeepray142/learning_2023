#include <stdio.h>

struct Time {
    int hours;
    int minutes;
    int seconds;
};

void getTimePeriod(struct Time* t) {
    printf("Enter time period (hours minutes seconds): ");
    scanf("%d %d %d", &t->hours, &t->minutes, &t->seconds);
}

struct Time calculateDifference(struct Time t1, struct Time t2) {
    struct Time diff;
    int totalSeconds1 = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
    int totalSeconds2 = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;
    int diffSeconds = totalSeconds1 - totalSeconds2;

    diff.hours = diffSeconds / 3600;
    diffSeconds %= 3600;
    diff.minutes = diffSeconds / 60;
    diff.seconds = diffSeconds % 60;

    return diff;
}

void printTimePeriod(struct Time t) {
    printf("Time period: %02d:%02d:%02d\n", t.hours, t.minutes, t.seconds);
}

int main() {
    struct Time time1, time2, difference;

    printf("Enter time period 1:\n");
    getTimePeriod(&time1);

    printf("Enter time period 2:\n");
    getTimePeriod(&time2);

    difference = calculateDifference(time1, time2);

    printf("Difference between time period 1 and time period 2:\n");
    printTimePeriod(difference);

    return 0;
}
