#include <iostream>
#include <tuple>

class Point3D {
    /**
    * A 3D point is a location that has a length, a width, and a height. 
    */
    public:
        // Constructors 
        Point3D() {
            coordinates = std::make_tuple(0,0,0);
        }
        Point3D(double x, double y, double z) {
            coordinates = std::make_tuple(x,y,z);
        }

        // Output Overload
        friend std::ostream& operator<<(std::ostream& out, Point3D& p) {
            out << "(" << std::get<0>(p.coordinates) << ", "
                       << std::get<1>(p.coordinates) << ", "
                       << std::get<2>(p.coordinates) << ")";
            return out;
        }

    private:
        std::tuple<double, double, double> coordinates;
};

int main() {

    Point3D point(1, 2, 3);
    std::cout << point << std::endl;
    
    return 0;
}
