/**
 * This program shows how child classes can 
 * inherit the constructors from the parent classes. 
 * There is also a method override.
 */

#include <iostream>
#include <string>


enum class year { FRESHMAN, SOPHOMORE, JUNIOR, SENIOR, GRADUATE };

std::ostream& operator<<(std::ostream& out, const year y) {
    /**
     * Overloads the << operator to output 
     * strings for the enum class year
     */
    switch(y) {
        case year::FRESHMAN: out << "FRESHMAN"; break;
        case year::SOPHOMORE: out << "SOPHOMORE"; break;
        case year::JUNIOR: out << "JUNIOR"; break;
        case year::SENIOR: out << "SENIOR"; break;
        case year::GRADUATE: out << "GRADUATE"; break;
    }
    return out;
}

class Student {
    /** 
     * A student is a person attending the school.
     * They have a name, id, gpa, and class year.
     */
    public:
    // Constructor
        Student(std::string nm, int id, double gpa, year y) : 
            name(nm), student_id(id), gpa(gpa), y(y) {}
        
        void print() const {
            std::cout << name << ", " << student_id << ", " << gpa << ", " << y;    
        }

    protected:
        int student_id;
        double gpa;
        year y;
        std::string name;
};

class GradStudent : public Student {
    /** 
     * A grad student is a student, but with an added department.
     * The print() function is overloaded to include the new attribute.
     */
    public:
        // Constructor
        GradStudent(std::string nm, int id, double gpa, year y, std::string dept) : 
            Student(nm, id, gpa, y), // inheritance of parent class constructor 
            department(dept) {}
        
        void print() const {
            Student::print();
            std::cout << ", " << department;
        }
    protected:
        std::string department;
};

int main() {
    Student a("Seph", 20, 3.94, year::SENIOR);
    GradStudent b("Alex", 21, 3.93, year::GRADUATE, "Computer Science");

    a.print();
    std::cout << '\n';
    b.print();
    
    return 0;
}
