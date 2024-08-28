/* This program introduces the ADT Stack */

#include <stdio.h>
#include <ctype.h>

#define MAX_LEN 1000
#define EMPTY -1
#define FULL (MAX_LEN - 1)

typedef struct stack{ char s[MAX_LEN]; int top; } stack;

void reset(stack *stk) { stk->top = EMPTY; }

// places char on top of stack
void push(char c, stack *stk) {
    stk->top++;
    stk->s[stk->top] = c;
}

// removes char at the top of the stack
char pop(stack *stk) { return (stk->s[stk->top--]); }

// returns char at the top of the stack
char top(const stack *stk) { return (stk->s[stk->top]); }

int isEmpty(const stack *stk) { return (stk->top == EMPTY); }

int isFull(const stack *stk) { return (stk->top == FULL); }

int main(void) {
    // init
    stack stackOfChar;
    char *str = "i am alfredo";
    char strBack[13];
    int i = 0;
    reset(&stackOfChar);

    printf("Original is:\t%s\n", str);

    // populates stack with chars
    while (str[i] != '\0') {
        push(str[i++], &stackOfChar);
    }
    i = 0;

    // takes char off the stack and adds it to strBack[]
    while(!isEmpty(&stackOfChar) && i < 20) {
        strBack[i++] = pop(&stackOfChar);
    }

    printf("Reverse is: \t%s\n\n\n", strBack);
    return 0;
}
