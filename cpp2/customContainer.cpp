/**
* This program shows how to use templates and classes
* to create a custom container.
*/

#include <iostream>

template <class T, int n>
class my_container {
    public:
        my_container() {
            a = new T[n];
        }
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
