#include <vector>
#include <iostream> 
#include <cstdlib>
#include <ctime>
#include <cmath>

int main() {
    std::srand(std::time(0));
    int n = 0;
    for (int j = 0; j < 100; j++) {
        for (int i = 0; i < 1000000; i++) {
            n = std::floor(std::rand() / (RAND_MAX + 1.0) * 121);
            std::cout << n << ' ';
            if (n == 121) std::cout << "yes";
        }
    }
    
    return 0;
}
