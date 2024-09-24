
#include <iostream>

// Bidirectional Iterator
bool is_palindrome(std::string word){
    int start {0};
    int end = word.size() - 1;

    while (true) {
        std::cout << word[start] << " and " << word[end] << '\n';
        if (word[start] != word[end]) {
            std::cout << "Not a palindrome!";
            return false;
        }
        start++; end--;
        if (start > end) break;
    }
    std::cout << "Is a palindrome!" << std::endl;
    return true;
}

int main() {
    std::string name = "racecar";
    is_palindrome(name);
    return 0;
}
