#include <iostream>
#include <string>
#include <thread>

void message2() {
    std::cout << "Message #1!\n";
}

int main() {
    // Initialize threads
    std::thread msg1([]() {
        std::cout << "Hello World!\n";
    });
    std::thread msg2(message2);
    
    msg1.join();
    msg2.join();

    return 0;
}
