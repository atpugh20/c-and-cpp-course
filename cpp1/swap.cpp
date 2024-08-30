/* This program uses a swap program to represent
 * pass by reference and overloading */

#include <iostream>

void swap(int& i, int& j) {
    int temp = i;
    i = j;
    j = temp;
}

void swap(double& i, double& j) {
    int temp = i;
    i = j;
    j = temp;
}

int main() {
    int num1 = 2;
    int num2 = 3;

    std::cout << num1 << " " << num2 << std::endl;
    swap(num1, num2);
    std::cout << num1 << " " << num2 << std::endl;

    return 0;
}