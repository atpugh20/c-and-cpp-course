/*
   This program will accept a double (x) between 0 and 1 from the user, 
   and then calculate the sine of this value. 
*/

#include <stdio.h>
#include <math.h>

int main(void) {
  double x = 0.0, result = 0.0; // Initialize the variables
  // Get x from the user
  printf("Input a decimal point number between 0 and 1: ");
  scanf("%lf", &x);
  // Calculate the sine with the math.h sin() function
  result = sin(x);
  printf("The sine of %lf is equal to: %lf", x, result);
  return 0;
}
