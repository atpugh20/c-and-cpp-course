/* This program shows how to use a singly linked list */

// INIT //

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct list { int data; struct list *next; } list;

// FUNCTIONS //

int isEmpty(const list *l) { return (l == NULL); }

void printList(list *l, char *title) {
    printf("%s\n", title);
    while (l != NULL) {
        printf("%d: ", l->data);
        l = l->next;
    }
}

// MAIN //

int main(void) {
    list listOfInt;
    list *head = NULL;
    head = malloc(sizeof(list));
    printf("sizeof(list) = %lu\n", sizeof(list));
    head -> data = 5;
    head -> next = NULL;
    printList(head, "single element list");
    printf("\n\n");
    return 0;
}
