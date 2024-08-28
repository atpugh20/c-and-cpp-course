#include<stdio.h>
#include<math.h> /* has  sin(), abs(), and fabs() */

int main(void) { 
  double interval;
  double result;
  for(int i = 0; i < 30; i++) {
    interval = i/10.0;
    result = fabs(sin(interval)); // I changed the abs() to fabs()
    printf("sin( %lf ) = %lf \t", interval, result);
  }

  printf("\n+++++++\n");
  return 0;
}
