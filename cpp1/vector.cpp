#include <iostream>
#include <vector>

template <class T>
void print(std::vector<T> v) {
    std::cout << "[ "; 
    for (T e : v) {
        std::cout << e << " ";
    }
    std::cout << "]\n";
}

int main() {
    std::vector<double> v1;
    print(v1);

    v1.push_back(10);
    print(v1);

    v1.pop_back();
    print(v1);
    
    v1.insert(v1.begin(), 5);
    print(v1);
    
    v1.erase(v1.begin());
    print(v1);
    
    v1.clear();
    print(v1);
    
    for (double i = 0.1; i < 10; i++) {
        v1.push_back(i);
    }
    print(v1);

    for (double i = 0; i < 10; i++) {
        v1.insert(v1.begin(), i);
    }
    print(v1);
}   
