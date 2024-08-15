/* Defines a prototype function, 
   then defines it later on */

#include <stdio.h>

int factorial(int num);

int main() {
    int num = 5;
    int f = factorial(num);
    printf("!%d = %d", num, f);
  
    return 0;
}

// Returns the factorial of the int parameter num
int factorial(int num) {
	int result = 1;  
	for (int i = num; i > 0; i--) {
        result *= i; 
	}
    return result;
}
