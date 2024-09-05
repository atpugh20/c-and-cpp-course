/* This program introduces the 'new' and 'delete' keywords 
 *
 * new      - requests for dynamic memory allocation in the heap
 *          - returns a pointer
 *
 * delete   - releases memory pointed by a pointer variable
 *          - used to :w
 * */

#include <iostream>

class Vector {
    int x, y;
    double angle_in_radians;
    
    public:

        // constructor (initialization)
        Vector(int x, int y, double angle_in_radians) : 
            x(x), y(y), angle_in_radians(angle_in_radians) {}

        // destructor
        //~Vector() { release(); }
        
        int get_x() { return x; }
        int get_y() { return y; }
        double get_angle() { return angle_in_radians; }
};

int main() {
    // Initialize object a using the 'new' keyword.
    Vector* a = new Vector(2, 3, 5.4);

    std::cout << "(" << a->get_x() << ", " << a->get_y() << ") at " << a->get_angle() << " radians.";
    
    // Detroy object a using the 'delete' keyword.
    delete a;
}
