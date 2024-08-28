/* This program takes an array of grades, 
 * prints each grade, then prints the 
 * average of all the grades */

#include <stdio.h>

int main(void) {
    int grades[5] = {100, 75, 80, 90, 96};
    double size = sizeof(grades) / sizeof(int);
    int sum = 0;
    double average = 0.0;
    
    printf("The grades are:\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %d\n", i + 1, grades[i]);
        sum += grades[i];
    }

    average = sum / size;
    printf("\nThe average is: %.2lf", average);
     
    return 0;
}
