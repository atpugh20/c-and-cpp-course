#include <stdio.h>
#include <math.h>

int main() {
  double sResult, cResult;
  printf("Sine-Cosine Table (CSV Style):\n\nNumber,   Sine,     Cosine,\n");
  for (double i = 0.0; i <= 1.0; i+=0.01) {
    sResult = sin(i);
    cResult = cos(i);
    printf("%lf, %lf, %lf\n", i, sResult, cResult);
  }
  return 0;
}
