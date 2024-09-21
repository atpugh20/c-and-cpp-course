#include <vector>
#include <iostream> 

int main() {

    std::vector<int> nums;

    for (int i = 0; i < 10; i++) {
        nums.push_back(i);
    }
    for (int n : nums) {
        std::cout << n << " ";
    }

    for (int i = 0; i < 10; i++) {
        nums.at(i) = 0;
    }
    for (int n : nums) {
        std::cout << n << " ";
    }

    return 0;
}
