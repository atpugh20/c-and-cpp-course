/* This program will repeat a print 
  statement the input number of times */

#include <stdio.h>

int main() {
  int repeat = 0;
  printf("How many times to repeat? ");
  scanf("%d", &repeat);
  while (repeat > 0) {
    printf("\nLets gooo!");
    repeat--;
  }

  return 0;
}
