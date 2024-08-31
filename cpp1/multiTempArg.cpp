/* This program shows how templates can be used
 * using more than one argument type */

#include <iostream>

template<class T1, class T2>

void copy(const T1 source[], T2 destination[], int size) {
    /* takes an array of one type, then copies 
     * it into another array of a different type */

    for (int i = 0; i < size; i++) {
        destination[i] = static_cast<T2>(source[i]);
    }

}

int main() {
    int size = 5;
    int nums[] = {1, 2, 3, 4, 5};
    double decimals[size];

    copy(nums, decimals, size);

    // print each new double to console
    std::cout << "New array as doubles + 0.1: ";
    for (int i = 0; i < size; i++) {
        std::cout << decimals[i] + 0.1 << " ";
    }
    
    return 0;
}
