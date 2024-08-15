/* This program will take an input from a user, 
 * then calculate the factorial of that number 
 * using recursion */

#include <stdio.h>

long int recursiveFactorial(int num) {
    if (num == 1) return 1;
    else return recursiveFactorial(num - 1) * num;
}

int main(void) {
    int num;
    long int answer;
    printf("Gimme a number for that factorial shiiit: ");
    scanf("%d", &num);
    answer = recursiveFactorial(num);
    printf("%ld", answer);
    return 0;
}
