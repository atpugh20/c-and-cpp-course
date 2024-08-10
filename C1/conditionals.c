#include <stdio.h>

int main() {
  int num;
  char lower;
  char upper;
  char tres;

  // need to prevent newline
  printf("Give a num:\n");
  scanf("%d", &num);
  printf("Give a lower:\n");
  scanf("%c", &lower);
  printf("Give a upper:\n");
  scanf("%c", &upper);
  
  
  // Normal if
  if (num > 5) printf("gretter thn fife");
  else printf("HUH");

  // Ternary operator
  tres = (lower >= 'a' && lower <= 'z') ? '1' : '0';
  printf("%c", &tres);

  // switch
  switch(upper) {
    case 'A':
      printf("ALEX");
      break;
    case 'Z':
      printf("ZACH");
      break;
    default:
      printf("beeeeeaawwwuu");
      break;
  }

  return 0;
}
