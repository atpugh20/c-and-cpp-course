/* This program simulates a virtual Tic-Tac-Toe 
 * match against the computer. The computer will 
 * choose a move at random */

// INIT //

#include <iostream>
#include <ctime>
#include <algorithm>

class Table {
    public:
        int size;
        char data[9];

        // Constructor
        Table() {
            size = 9;
            clear_board();
        }

        void clear_board() {
            /* Sets the table array back to the 
             * default int */
        
            for (int i = 0; i < size; i++) {
                data[i] = ' ';
            }
        }

        bool check_square(int move, char player) {
            if (data[move - 1] == ' ') {
                data[move-1] = player;
                return true;
            } else {
                std::cout << "Space filled!" << std::endl;
                return false;
            }
        }

        void print() {
            /* Prints out the current tic-tac-toe table 
             * into the console */

            std::string w = "\t|\t";
            std::string fl = "\t-------------------------------------------------";
            std::cout << std::endl;
            std::cout << fl << std::endl; 
            for (int i = 0; i < size; i++) {
                std::cout << w;
                if (data[i] == ' ') {
                    std::cout << "[" << i + 1 << "]";
                } else {
                    std::cout << data[i];
                }
                if ((i + 1) % 3 == 0) {
                    std::cout << w << std::endl;
                    std::cout << fl << std::endl;
                }
            }
        }
};

int get_user_move();
int get_cpu_move();
void execute_turn(char player, Table& table);

// MAIN //

int main() {
    std::srand(std::time(NULL)); // use current time as seed
    Table table;
    int user_move;
    int cpu_move;
    const char USER = 'X';
    const char CPU = 'O';
    
    // Game Loop
    while (true) {
        table.print();
        execute_turn(USER, table);
        table.print();
        execute_turn(CPU, table);
    }
}

// FUNCTIONS //

int get_user_move() {
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

int get_cpu_move() {
    /* This function returns a random 
     * integer(1-9) as the computer's move */
    
    return std::rand() % 9 + 1;
}

void execute_turn(char player, Table& table) {
    /* Starts the input player's turn and
     * ensures that their move was successful */

    int move;
    bool move_successful;
    
    while (true) {
        if (player == 'X') move = get_user_move(); 
        else move = get_cpu_move();
        move_successful = table.check_square(move, player);
        if (move_successful) break;
        else continue;
    }
   
}
