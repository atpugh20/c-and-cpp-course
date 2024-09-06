#include <iostream>
#include <vector>

void print(std::vector<int> v) {
    std::cout << "[ "; 
    for (int i = 0; i < v.size(); i++) {
        std::cout << v.at(i) << " ";
    }
    std::cout << "]\n";
}

int main() {
    std::vector<int> v1;
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
    for (int i = 0; i < 10; i++) {
        v1.push_back(i);
    }
    print(v1);

    for (int i = 0; i < 10; i++) {
        v1.insert(v1.begin(), i);
    }
    print(v1);
}   
