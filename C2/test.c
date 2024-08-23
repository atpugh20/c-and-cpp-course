#include <stdio.h>

int main() {
    struct point {
        double x;
        double y;
    } p1;

    struct point* ptr = &p1;

    printf("%lf", ptr->y);
}
