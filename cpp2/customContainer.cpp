/**
* This program shows how to use templates and classes
* to create a custom container.
*/

#include <iostream>

template <class T, int n>
class my_container {
    public:
        // Constructors
        my_container() {
            a = new T[n];
        }
        
        // Conversion Constructor        
        explicit my_container(T* b):my_container() {
            for (int i = 0; i < n; i++) {
                a[i] = b[i];
            }   
        }
        
        // Copy Constructor
        my_container(const my_container& b): my_container() {
            for (int i = 0; i < n; i++) {
                a[i] = b.a[i];
            }
        }

        // Move Constructor
        my_container(my_container&& b) noexcept {
            a = b.a;
            b.a = nullptr;
        }
            
        // Deconstructor
        ~my_container() {
            delete[] a;
        }
              
    private:
        T* a;
};

int main(){
    my_container<int,5> data;

    std::cout << "Container created.\n";    
    return 0;
}
