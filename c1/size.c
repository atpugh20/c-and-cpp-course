/* This code will give us the byte sizes for various data types */

#include <stdio.h>

int main() {
  printf("Size of int is %lu bytes\n", sizeof(int));
  printf("Size of long int is %lu bytes\n", sizeof(long int));
  printf("Size of char is %lu bytes\n", sizeof(char));
  printf("Size of float is %lu bytes\n", sizeof(float));
  printf("Size of double is %lu bytes\n", sizeof(double));
  printf("Size of long double is %lu bytes\n", sizeof(long double));
  return 0;
}
