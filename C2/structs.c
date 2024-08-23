/* This program introduces the struct data type */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void) {
    // sets the seed for rand()
    srand(time(NULL)); 

    // declaration
    int deckSize = 52;
    char suits[4] = {'d', 'c', 'h', 's'};
    int suitNumber;
    
    // creation of struct
    struct card {
        int num;
        char suit;
    } c1, c2, c3;
    
    // first method for access using '.' (normal access)
    c1.num = rand() % 13 + 1;
    c1.suit = suits[rand() % 4];
    printf("Card (Set with '.'):\t%d of %c\n", c1.num, c1.suit);
    
    // second method for accesss using '->' (for pointers)
    struct card * ptr_to_c1;
    ptr_to_c1 = &c1;
    ptr_to_c1->num = rand() % 13 + 1;
    ptr_to_c1->suit = suits[rand() % 4];
    printf("Card (Set with '->'):\t%d of %c\n", c1.num, c1.suit);

    return 0;
}
