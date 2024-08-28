/* This program introduces fscanf() read data from a file */

#include <stdio.h>

#define MAX_HW 200

void read_data(FILE *ptr, int d[], int *size) {
    /* Reads the data and increments size */
    *size = 0;
    while (fscanf(ptr, "%d", &d[*size]) == 1) {
        (*size)++;
    }
}

void print_data(int d[], int size) {
    /* Prints file data in rows of 10 */
    for (int i = 0; i < size; i++) {
        printf("%d\t", d[i]);
        if ((i + 1) % 10 == 0) {
            printf("\n");
        }
    }
}

double average(int d[], int size) {
    /* Returns the average of d[] */
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += d[i];
    }
    return (sum / size);
}

int main() {
    int size;
    FILE *ifp;
    int data[MAX_HW];

    ifp = fopen("myhw", "r");
    read_data(ifp, data, &size);
    printf("\nMy %d homework scores are:\n\n", size);
    print_data(data, size);
    printf("\n\nThe average was: %10f\n\n", average(data, size));
    fclose(ifp);
    return 0;
}

