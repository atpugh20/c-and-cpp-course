/* 
  Program for calculating the area of a circle 
 */

#include <stdio.h>
#define PI 3.14159

int main() {
  double area = 0.0, radius = 0.0;
  printf("Please enter a radius: ");
  scanf("%lf", &radius);
  area = PI * radius * radius;
  printf("With a radius of %lf, the area is %lf.", radius, area);
  return 0;
}
