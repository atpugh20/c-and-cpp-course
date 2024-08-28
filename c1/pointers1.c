/* This program uses a pointer and 
 * prints out its address and value */

#include <stdio.h>

int main(void) {
    double sum = 0.0;
    double *ptrToSum = &sum;
    int grades[5] = {100, 90, 80, 70, 60};

    printf("Sum is at %p or at %lu, and has the value %lf",
            ptrToSum, ptrToSum, *ptrToSum);
    
    printf("\nGrades is at %p or from %lu to %lu",
            grades, grades, grades+5);

    return 0;
}
