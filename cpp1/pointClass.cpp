/* This program uses a point on the x and y axis
 * to show how classes and objects are used */

// Constructor methods:
// 1. point() { x = y = 0.0; }
// 2. point() { this->x = 0.0, this->y = 0.0; }
// 3. point() : x(0.0), y(0.0) {}
//
// 3 is an initialization, which can set a const


#include <iostream>

class Point {
    /* A point is a location on the x,y axis */

    double x, y;

    public:
        // constructor
        Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}
        
        // methods
        double getx() { return x; }
        double gety() { return y; }
        void setx(double v) { x = v; }
        void sety(double v) { y = v; }
};

int main() {
    Point a(2.1, 3.5);
    std::cout << a.getx() << ", " << a.gety() << "\n";
}
