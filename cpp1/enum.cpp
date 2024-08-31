/* This program reviews enum and operator overloading */

#include <iostream>

typedef enum days {SUN, MON, TUE, WED, THU, FRI, SAT} days;

inline days operator++(days d) {
    return static_cast<days>((static_cast<int>(d) + 1) % 7);
}

int main() {
    std::cout << FRI;
    return 0;
}
