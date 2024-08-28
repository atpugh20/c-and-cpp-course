/* This code covers the preprocessor lecture */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEAL_WT 8800
#define MIN_SEAL_WT 4400

// macro for random male weight
#define RANGE           4400
#define POPULATION      1000
#define WEIGHT_OVER     rand() % RANGE // rand() is 0 to RAND_MAX
#define WEIGHT          WEIGHT_OVER + MIN_SEAL_WT
#define FILL            for (i = 0; i < POPULATION; i++) \
                            data[i] = WEIGHT

int main(void) {
    int i;
    int data[POPULATION];
    srand(time(0)); // sets the random seed
    FILL; // uses the macro to populate random weights
    for (int i = 0; i < POPULATION; i++) {
        printf("%d.\t%d\n", i+1, data[i]);
    } 
    return 0;
}
