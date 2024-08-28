/* This program prints out the factorials of 0 to 15 */

#include <iostream>

long long factorial(int n) {
    long long f = 1;
    for (int i = 1; i <= n; i++) {
        f *= i;
    }
    return f;
}

int main() {
    std::cout << "\nFactorial:\n\n";
    for (auto i = 0; i < 16; i++) {
        std::cout << "!" << i << "\t=\t" << factorial(i) << std::endl;
    }
    return 0;
}
