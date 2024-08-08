#include <stdio.h>

int main() {
  int a = 5, b = 3, c = 5, d = 8;
  double average = 0.0;
  printf("a=%d b=%d c=%d d=%d\n", a, b, c, d);
  average = (a + b + c + d) / 4.0;
  printf("The average is %lf.", average);
}
