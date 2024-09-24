/* This program shows the syntax and a
 * use case of the lambda function 
 *
 * Syntax: [] (int n) { std::cout << i; }
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> nums;
    for (int i = 0; i < 100; i++) nums.push_back(i);

    // Lambda used in this for_each:
    for_each(nums.begin(), nums.end(), [](int i){
        std::cout << i << '\n';
    });

    return 0;
}
