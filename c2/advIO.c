/* This program goes into more advanced input and output topics */

#include <stdio.h>

int main(void) {
    double x = 0.123456789;
    printf("General Printing Ideas\n\n");
    printf("Original x:\t%lf\n", x);
    printf("%%-12.5e:\t%-12.5e\n", x);
    printf("%%e:\t\t%e\n", x);
    printf("%%10.5f:\t\t%10.5f\n", x);
    printf("%%10d:\t\t%10d\n\n", (int)x);
    return 0;
}
