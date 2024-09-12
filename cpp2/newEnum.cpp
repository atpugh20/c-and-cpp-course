/*
 * This program reviews the C++ version of enumerated classes
 */

#include <iostream>

enum class Response:unsigned{ 
    NO, 
    MAYBE = 5, 
    YES = 10 
};

std::ostream& operator<<(std::ostream& out, const Response& r) {
    /*
     * This function assigns output strings to each enum Response type
     */
    switch(r) {
        case Response::NO: out << "NO"; break;
        case Response::MAYBE: out << "MAYBE"; break;
        case Response::YES: out << "YES"; break;
    }
    return out;
}

int main() {
    Response r = Response::YES;
    std::cout << r << " - " << int(r) << '\n';
    r = Response::MAYBE;
    std::cout << r << " - " << int(r) << '\n';
    r = Response::NO;
    std::cout << r << " - " << int(r) << '\n';
}
