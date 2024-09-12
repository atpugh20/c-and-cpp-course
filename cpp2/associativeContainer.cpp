#include <iostream>
#include <map>
#include <unordered_map>
#include <string>

int main() {
    // Standard Map
    std::map<unsigned long, std::string> worker;
    
    // Unordered Map
    std::unordered_map<unsigned long, unsigned> payroll;
    std::unordered_map<std::string, std::string> positions;

    positions["AR1"] = "Alex";
    positions["AR2"] = "Dakota";
    positions["SMG1"] = "Bryce";
    positions["SMG2"] = "Chase";

    unsigned total_pay = 0;

    worker[99567800] = "Alfredo Abromaitis";
    payroll[99567800] = 100000;
    
    worker[8567800] = "A.C. Acy";
    payroll[8567800] = 120000;
    
    // increment with ':'
    for (auto& [key, value] : worker) {
        std::cout << key << " : " << value << '\n';
    }
    // increment with .begin() and .end() 
    for (auto p = payroll.begin(); p != payroll.end(); p++) {
        std::cout << (*p).first << " : " << (*p).second << '\n';
    }
    // back to ':' - Will use this in most situations
    for (auto& [key, value] : positions) {
        std::cout << key << " : " << value << '\n';
    }



    return 0;
}
