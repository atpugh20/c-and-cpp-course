/* This program give a mathematical example
 * of using asserts (divding by 0) */

#include <assert.h>
#include <stdio.h>

int main(void) {
    double x, y, result;
    while(1) {
        printf("\n\nGive a number: ");
        scanf("%lf", &x);
        printf("\nGive another number: ");
        scanf("%lf", &y);
        assert(y != 0);
        result = x / y;
        printf("\n%lf / %lf = %lf", x, y, result);
    }

    return 0;
}
