/* This program introduces the idea of 
 * operator overloading with input output */

#include <iostream>

enum Color {RED, BLUE, GREEN};

std::ostream& operator<<(std::ostream& out, const Color& c) {
    /* This function assigns output strings to each enum Color type */
    switch(c) {
        case RED: out << "RED"; break;
        case BLUE: out << "BLUE"; break;
        case GREEN: out << "GREEN"; break;
    }
    return out;
}

int main() {
    Color c = GREEN;
    std::cout << c << " ";
    c = BLUE;
    std::cout << c << " ";
    c = RED;
    std::cout << c << " ";
}
