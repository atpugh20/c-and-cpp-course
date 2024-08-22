/* This program uses assert to 
 * check for program correctness */

#define NDEBUG // turns off assert, goes before assert.h

#include <stdio.h>
#include <assert.h>
#include <ctype.h>

int main(void) {
    assert(0); // aborts program if 0 (false)
    printf("This program runs\n");
    return 0;
}
