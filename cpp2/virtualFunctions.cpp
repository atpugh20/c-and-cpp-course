/** 
* This program shows how virtual 
* functions are used with inheritence
* - Virtual functions are functions that 
* - are declared in a base class and then 
* - are redefined in a derived class
*
*/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

class Duo {
    
    public:
        Duo() : first(0.0), second(0.0) {}
        void set_first(double d) {first = d;}
        void set_second(double d) {second = d;}
        double get_first() {return first;}
        double get_second() {return second;}
    
    protected: // can be used with inheritance
        double first, second;
};

class Point:public Duo {
    public:
        double length() { return std::sqrt(first* first + second* second); }
};

int main() {
    Point p;
    p.set_first(3.0); p.set_second(4.0);
    std::cout << p.length();

    return 0;
}