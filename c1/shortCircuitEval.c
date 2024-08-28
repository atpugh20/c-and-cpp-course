/* Logical Operators and Short Circuit evaluation */

#include <stdio.h>

int main() {
  int isOutside, isRaining;
  printf("Are you outside? (1=Yes, 0=No): ");
  scanf("%d", &isOutside);
  printf("Is it raining? (1=Yes, 0=No): ");
  scanf("%d", &isRaining);
  if (isOutside && isRaining) 
    printf("Bring an umbrella!");
  else 
    printf("I guess you don't need an umbrella then!");
  
  return 0;
}
