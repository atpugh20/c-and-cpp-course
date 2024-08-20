/* This program reads data from a file to an array,
 * then calculates the average of the entire data set */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int size = 1000;
    int sum = 0;
    double average = 0.0;
    int nums[size];

    // load file with fopen
    FILE *file;
    file = fopen("data.txt", "r");
    char text[6000];
    fgets(text, 6000, file);
    int textSize = sizeof(text) / sizeof(char);
    fclose(file);
    
    // populate nums[] with numbers from file
    int index = 0;
    for (int i = 0; i <  textSize; i+=6) { 
        char line[] = {text[i], text[i+1], text[i+2], text[i+3], '\0'};
        nums[index] = atoi(line);
        index++;
    }

    // calculate average
    for (int i = 0; i < size; i++) {
        sum+=nums[i];
    } 
    average = (double)sum / size;

    printf("The average of the data set is: %lf", average);

    return 0;
}


