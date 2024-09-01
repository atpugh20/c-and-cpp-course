/* This program simulates a virtual Tic-Tac-Toe 
 * match against the computer. The computer will 
 * choose a move at random */

// INIT //

#include <iostream>
#include <ctime>

void clear_table(int t[]);
void print_table(int t[]);
int get_player_move();
int get_computer_move();

const int T_SIZE = 9;

// MAIN //

int main() {
    std::srand(std::time(NULL)); // use current time as seed
    int table[T_SIZE];
    clear_table(table);
    print_table(table);
    for (int i = 0; i < T_SIZE; i++) {
        std::cout << table[i] << " ";
    }
}

// FUNCTIONS //

void clear_table(int t[]) {
    /* Sets the table array back to the 
     * default integers of 1-9 */
    
    for (int i = 0; i < T_SIZE; i++) {
        t[i] = i + 1;
    }
}

void print_table(int t[]) {
    /* Prints out the current tic-tac-toe table 
     * into the console */

    std::string w = "\t|\t";
    std::string fl = "\t-------------------------------------------------";
    std::cout << std::endl;
    for (int i = 0; i < 3; i++) {
        int j = 3 * i; //first index of the row
        std::cout << fl << std::endl;
        std::cout << w << t[j] << w << t[j+1] << w << t[j+2] << w << std::endl;
    }
    std::cout << fl << std::endl << std::endl;
}

int get_player_move() {
    /* This function gets a move from 
     * the user using the console. */
    
    while (true) {
        int move;
        std::cout << "Please choose a square (Type '0' to quit):" << std::endl;
        std::cin >> move;
        if (move > 0 && move < 10) {
            return move;
        } else if (move == 0) {
            std::cout << "Goodbye!" << std::endl;
            exit(0);
        } else {
            std::cout << "Invalid move." << std::endl;
        }
    }
}

int get_computer_move() {
    /* This function returns a random 
     * integer(1-9) as the computer's move */
    
    return std::rand() % 9 + 1;
}
