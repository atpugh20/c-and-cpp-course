/* This program performs the bubble-sort on an integer array */

// INIT //

#include <stdio.h>

void swap(int *a, int *b); 
void sort(int nums[], int size);
void printArray(int array[], int size);

// MAIN //

int main(void) {
    int numbers[5] = {5, 8, 3, 10, 9};
    int size = sizeof(numbers) / sizeof(int);
    printf("Original Array: ");
    printArray(numbers, size);
    printf("\nSorted Array: ");
    sort(numbers, size);
    printArray(numbers, size);
    return 0;
}

// FUNCTIONS //

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int nums[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (nums[j] > nums[j+1]) {
                swap(&nums[j], &nums[j+1]);
            }   
        }
    }
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d, ", array[i]);
    }
}

