/* This program will print all the chars */

#include <stdio.h>
#include <math.h>

int main() {
  int bits = 128; // total bits in a byte
  for (int i = 0; i < bits; i++) {
    printf("%c", i); // prints i as a character
  }
  return 0;
}
