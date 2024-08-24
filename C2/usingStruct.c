/* This program uses both enumeration and 
 * structs to provide date information */

// INIT //

#include <stdio.h>

typedef enum month { jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec } month;

typedef struct date {
    month m; 
    int d; 
} date;

const int DAYS_PER_MONTH[] = {
    31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};
const char MONTH_STRINGS[12][10] = {
    "January", "February", "March", "April", "May", "June", 
    "July", "August", "September", "October", "November", "December"
};

// FUNCTIONS //

void nextDay(date *today){
    /* Changes the current date to the next date */

    // checks if last day in month
    if (today->d == DAYS_PER_MONTH[today->m]) {
        // checks if last month
        if (today->m == dec) {
            today->m = jan;
        } else {
            today->m++;
        }
        today->d = 1;
    } else {
        today->d++;
    }
}

void printDate(date today) {
    printf("%s %d", MONTH_STRINGS[today.m], today.d);
}

void printTodayAndTomorrow(date *today) {
    /* Helper function that prints the date, 
     * advances to the next day, 
     * then prints the new date */

    printf("\n");
    printDate(*today);
    nextDay(today);
    printf("\t->\t");
    printDate(*today);
    printf("\n");
}

// MAIN //

int main(void) {
    date today;
    
    today.m = jan; today.d = 1;
    printTodayAndTomorrow(&today);
    
    today.m = feb; today.d = 28;
    printTodayAndTomorrow(&today);
    
    today.m = mar; today.d = 14;
    printTodayAndTomorrow(&today);

    today.m = oct; today.d = 31;
    printTodayAndTomorrow(&today);

    today.m = dec; today.d = 31;
    printTodayAndTomorrow(&today);
    
    return 0;
}
