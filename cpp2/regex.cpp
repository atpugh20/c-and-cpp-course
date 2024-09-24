#include <iostream>
#include <string>
#include <regex>

int main() {
    std::string file_paths[] = {
        "words.txt",
        "numbers.txt",
        "people.tt",
        "inventory.txt"
    };

    // Set regex pattern
    std::regex txt_regex("[a-z]+\\.txt");

    for (int i = 0; i < 4; i++) {
        std::cout << file_paths[i] << " : " << regex_match(file_paths[i], txt_regex) << '\n';
    }
    
    return 0;
}
