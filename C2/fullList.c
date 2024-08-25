/* This program represents how to  */

// INIT //

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct list { int data; struct list *next; } list;

// FUNCTIONS //

int isEmpty(const list *l) { return (l == NULL); }

list *createList(int d) {
    list *head = malloc(sizeof(list));
    head -> data = d;
    head -> next = NULL;
    return head;
}

list *addToFront(int d, list *h) {
    list *head = createList(d);
    head -> next = h;
    return head;
}

list *arrayToList(int d[], int size) {
    list *head = createList(d[0]);
    for (int i = 1; i < size; i++) {
        head = addToFront(d[i], head);
    }
    return head;
}

// MAIN //

int main(void) {

    return 0;
}
