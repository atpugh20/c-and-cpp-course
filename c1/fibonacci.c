/* This program asks the user for an integer n, 
 * then returns the nth digit of the fibonacci sequence */

#include <stdio.h>

long int fib(int n) {
    if (n <=1) return n;
    else return fib(n - 2) + fib(n - 1);
}

int main(void) {
    int n;
    printf("Give number for fiiiib: ");
    scanf("%d", &n);
    long int answer = fib(n);
    printf("The fib number for %d is: %ld", n, answer);
    return 0;
}
