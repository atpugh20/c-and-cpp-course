/** 
 * This program shows how virtual functions are 
 * changed from the parent to the child
 */

#include <iostream>
#include <cmath>

class Duo {
    /** 
     * This is the parent class
     */
    public:
        Duo() : first(0.0), second(0.0) {}

        void set_first(double lf) { first = lf; }
        void set_second(double lf) { second = lf; }
        
        double get_first() { return first; }
        double get_second() { return second; }
        
    protected:
        double first, second;
};

class Point : public Duo {
    /** 
     * This is the child class that has the virtual function
     */
    public:
        virtual double length() { return std::sqrt(first * first + second * second); }
};

class Point3D final: public Point {
    /**
     * This is the child class that changes the virtual function.
     * (final means it cannot be inherited from)
     */
    public:
        Point3D() : Point(), third(0.0) {}
        
        void set_third(double lf) { third = lf; }
        double length() { return std::sqrt(first * first + second * second + third * third); }
        
    private:
        double third;
};

int main() {
    
    Point p;
    p.set_first(3.0); p.set_second(4.0);
    std::cout << p.length() << '\n';
    
    Point3D p3d;
    p3d.set_first(3.0); p3d.set_second(4.0); p3d.set_third(2.3);
    std::cout << p3d.length();

    return 0;
}
