#include <iostream>

template<class T>
inline void swap(T& d, T& s) {
    T temp = d;
    d = s;
    s = temp;
}

int main() {
    int a = 1, b = 2;
    double c = 1.2, d = 1.4;
    char e = 'e', f = 'f';
    std::string g = "Sentence #1", h = "Sentence #2";

    // Integer swap
    std::cout << a << ", " << b << " ->\n";
    swap(a, b);
    std::cout << a << ", " << b << "\n\n";
    
    // Double swap
    std::cout << c << ", " << d << " ->\n";
    swap(c, d);
    std::cout << c << ", " << d << "\n\n";
    
    // Char swap    
    std::cout << e << ", " << f << " ->\n";
    swap(e, f);
    std::cout << e << ", " << f << "\n\n";

    // String swap
    std::cout << g << ", " << h << " ->\n";
    swap(g, h);
    std::cout << g << ", " << h << "\n\n";

    return 0;
}
