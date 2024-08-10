#include <stdio.h>

int main() {
  int blanks = 0, digits = 0, letters = 0, others = 0;
  int c;
  
  while((c = getchar()) != EOF) {
    if (c == ' ') blanks++;
    else if (c >= '0' && c <= '9') digits++;
    else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c<= 'Z')) letters++;
    else others++;
  }

  printf("Blanks = %d, Digits = %d, Letters = %d, Others = %d", 
	blanks, digits, letters, others);

  return 0;
}
