/* This program creates an array of random integers (0-999), 
 * converts the array into a linked list, sorts the linked list, 
 * and prints the linked list to the console in rows of five. */

// INIT //

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

typedef struct list { int data; struct list *next;} list; 

// FUNCTIONS //

int is_empty(const list *h) { return (h == NULL); } // is empty

list *create_list(int d) {
    /* Allocates the space for the list in memory,
     * then initializes it with the initial data */

    list *head = malloc(sizeof(list));
    head->data = d;
    head->next = NULL;
    return head;
}

list *add_to_front(int d, list *h) {
    list *head = create_list(d);
    head->next = h;
    return head;
}

list *array_to_list(int d[], int size) {
    list *head = create_list(d[0]);
    for (int i = 1; i < size; i++) {
        head = add_to_front(d[i], head);
    }
    return head;
}

void sort_list(list *h, int size) {
    /* Sorts the list from smallest to largest, 
     * using the bubble sorting method */

    for (int i = 0; i < size - 1; i++) {
        list *current = h;
        for (int j = 0; j < size - i - 1; j++) {
            if (current->data > current->next->data) {
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
            }   
            current = current->next;
        }
    }
}

void print_list(list *h, char *title) {
    /* Prints each element of the list to the console. 
     * This is done in tabbed rows of five elements  */

    printf("\n%s\n\n", title);
    int counter = 0;
    while (h != NULL) {
        counter++;
        printf("%d\t", h -> data);
        if (counter == 5) {
            printf("\n\n");
            counter = 0;
        }
        h = h->next;
    }
}

// MAIN //

int main(void) {
    srand(time(0)); // sets seed for random
    list *list_of_int = NULL;
    int size = 100;
    int data[size];
    // fill array with 100 random integers between 0-999
    for (int i = 0; i < size; i++) {
        data[i] = rand() % 1000;
    }
    list_of_int = array_to_list(data, size);
    sort_list(list_of_int, size);
    print_list(list_of_int, "Sorted:");
    return 0;
}
