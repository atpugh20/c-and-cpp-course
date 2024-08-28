/* Prints out various types of integers */

#include <stdio.h>

int main() {
  short ShortA = 7;
  int NormA = 20;
  unsigned UnsignedA = 21u;
  long LongA = 100l;

  printf("Size of all these are: %lu, %lu, %lu, %lu", 
	  sizeof(ShortA), sizeof(NormA), sizeof(UnsignedA), sizeof(LongA)); 
  
  return 0;
}
