/** 
* This program shows the syntax used for class inheritence
*/

#include <iostream>
#include <cmath>

class Duo {
    /**
     * This is the parent class
     */ 
    public:
        Duo() : first(0.0), second(0.0) {}
        void set_first(double d) {first = d;}
        void set_second(double d) {second = d;}
        double get_first() {return first;}
        double get_second() {return second;}
    
    protected: // can be used with inheritance, when private cannot
        double first, second;
};

class Point:public Duo {
    /**
     * this is the child class
     */
    public:
        double length() { return std::sqrt(first* first + second* second); }
};

int main() {
    Point p;
    p.set_first(3.0); p.set_second(4.0);
    std::cout << p.length();

    return 0;
}
