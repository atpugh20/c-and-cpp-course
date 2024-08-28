/* This program converts and input number 
 * of miles to kilometers, then prints it */

// INIT //

#include <iostream>

const double m_to_k = 1.609;

// FUNCTIONS //

inline double convert(int mi) { return (mi * m_to_k); }

// MAIN //

int main() {
    int miles = 1;
    
    while (miles != 0) {
        std::cout << "Input a distance in miles ('0' to quit): ";
        std::cin >> miles;
        std::cout << miles << " miles is " << convert(miles) << " miles." << std::endl;
    }

    return 0;
}
