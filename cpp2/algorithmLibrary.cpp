#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string names[] = {"alex", "zach", "austin", "matt", "jj", "chase"};
    for (std::string name : names) {
        std::cout << name << '\n';
    }

    // find
    std::string* where = find(names, names+5, "jj");
    if (where != nullptr) std::cout << *where << '\n';
    
    // sort (uses quicksort)
    sort(names, names+5);
    for (std::string name : names) {
        std::cout << name << '\n';
    }  

    return 0;
}
