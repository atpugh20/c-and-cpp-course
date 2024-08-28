#include <stdio.h>

extern double pi = 3.14159;

void staticCookies(void) {
    static int cookies = 5;
    printf("cookies = %d\n", cookies);
    printf("pi = %lf \n", pi);
    cookies++;
}

int main(void) {
    staticCookies();
    auto int pies = 2;
    const int cakes = 3;
    printf("pies = %d\ncakes = %d \n", pies, cakes);
    staticCookies();
    return 0;
}
