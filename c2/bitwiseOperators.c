/* This covers bitwise operators, which is to help 
 * with my Discrete Structures and Algorithms class */

// Operators:
//
// & = AND
// | = OR
// ^ = XOR
// << = Left shift
// >> = Right shift

#include <stdio.h>

int main() {
    int x = 6;  // 6 = 00000110 
    int y = 12; //12 = 00001100 
    int z = 0;  // 0 = 00000000
    
    z = x & y;
    printf("AND\t\t%d\n", z);
    
    z = x | y;
    printf("OR\t\t%d\n", z);

    z = x ^ y;
    printf("XOR\t\t%d\n", z);

    z = x << 2;
    printf("Left Shift\t%d\n", z);
    
    z = y >> 2;
    printf("Right Shift\t%d\n", z);
    return 0;
}
