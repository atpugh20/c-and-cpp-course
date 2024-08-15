#include <stdio.h>

int power(int num, int pow) {
  int result = num;
  for (int i = 0; i < pow - 1; i++) {
    result *= num;
  }
  return result;
}

int main() {
  int bits = power(2, 8);
  printf("%d", bits);

  return 0;
}
