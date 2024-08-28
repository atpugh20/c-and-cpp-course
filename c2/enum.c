/* This program shows how the enum data type is used */

#include <stdio.h>

// declare type
enum day {sun, mon, tue, wed, thu, fri, sat};
typedef enum day day;

void printDay(day d) {
    switch(d) {
        case sun: printf("SUNDAY"); break;
        case mon: printf("MONDAY"); break;
        case tue: printf("TUESDAY"); break;
        case wed: printf("WEDNESDAY"); break;
        case thu: printf("THURSDAY"); break;
        case fri: printf("FRIDAY"); break;
        case sat: printf("SATURDAY"); break;
        default: printf("%d is an error", d);
    }
}

enum day nextDay(day d) {
    return (d + 1 % 7);
}

int main(void) {
    enum day today = mon;
    printDay(today);
    printf("\n\n");
    printDay(5);
    printf("\n\n");
    printDay(nextDay(today));
    printf("\n\nYER!");
    return 0;
}
