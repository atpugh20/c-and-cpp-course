/* This program simulates a virtual Tic-Tac-Toe 
 * match against the computer. The computer will 
 * choose a move at random */

#include <iostream>
#include <ctime>
#include <algorithm>

////
// CLASSES
////

class Table {
    int rows, cols, last_x, last_y;
    
    public:
        int user_score, cpu_score;
        char last_player;
        char data[3][3];

        // Constructor
        Table() {
            rows = cols = 3;
            user_score = cpu_score = 0;
            clear_board();
        }

        // Methods

        void clear_board() {
            /* Sets the table array back to the 
             * default char of ' ' (space) */
        
            for (int y = 0; y < rows; y++) {
                for (int x = 0; x < cols; x++) {
                    data[y][x] = ' ';
                } 
            }
        }

        void print() {
            /* Prints out the current tic-tac-toe 
             * table into the console */
            
            std::string w = "\t|\t";
            std::string fl = "\t-------------------------------------------------";
            
            std::cout << '\n';
            std::cout << fl << '\n'; 
            for (int y = 0; y < rows; y++) {
                for (int x = 0; x < cols; x++) {
                    std::cout << w;
                    if (data[y][x] == ' ') {
                        int cell = y * 3 + x + 1;
                        std::cout << cell;
                    } else {
                        std::cout << "[" << data[y][x] << "]";
                    }
                }
                std::cout << w << '\n';
                std::cout << fl << '\n';
            }
        }

        bool check_square(int move, char player) {
            /* Checks a square to see if it filled. If not, it is filled 
             * with the player's symbol and last move is updated */
            
            // convert move number to array indexes
            int y = (move - 1) / rows;
            int x = (move - 1) % cols;

            if (data[y][x] == ' ') {
                data[y][x] = player; // fill square
                last_x = x; last_y = y; // update the last move
                last_player = player;
                return true;
            } else {
                if (player == 'X') std::cout << "Space filled!\n";
                return false;
            }
        }

        bool is_winner() {
            /* Checks for horizontal, vertical, and 
             * diagonal sequences in that order. */

            bool is_winner = false;

            if (data[last_y][0] == data[last_y][1] && data[last_y][1] == data[last_y][2]) {
                is_winner = true;
            } else if (data[0][last_x] == data[1][last_x] && data[1][last_x] == data[2][last_x]) {
                is_winner = true; 
            } else if ((last_x + last_y) % 2 == 0) {
                if (last_x - last_y == 0) {
                    if (data[0][0] == data[1][1] && data[1][1] == data[2][2]) {
                        is_winner = true; 
                    }         
                }
                if (last_x - last_y != 0 || last_x == 1 && last_y == 1) {
                    if (data[2][0] == data[1][1] && data[1][1] == data[0][2]) {
                        is_winner = true;
                    }
                }
            }
            return is_winner;
        }

        bool is_draw() {
            /* Checks every sqaure in the table for a space. 
             * If there is a space, then it is NOT a draw  */
            bool is_draw = true;
            
            for (int y = 0; y < rows; y++) {
                for (int x = 0; x < cols; x++) {
                    if (data[y][x] == ' ') is_draw = false;
                }
            }
            return is_draw;
        }

        void print_score() {
            /* Prints a premade scoreboard to the console */
            std::cout << "\t-----------------\n";
            std::cout << "\tUser Score:\t" << user_score << '\n';
            std::cout << "\tCPU Score:\t" << cpu_score << '\n';
            std::cout << "\t-----------------" << std::endl;
        }
};

////
// FUNCTIONS //
////

int get_user_move() {
    /* This function gets a move from 
     * the user using the console. */
    
    while (true) {
        int move;
        std::cout << "\n\tPlease choose a square (Type '0' to quit): ";
        std::cin >> move;
        if (move > 0 && move < 10) {
            return move;
        } else if (move == 0) {
            std::cout << "\n\tGoodbye!" << std::endl;
            exit(0);
        } else {
            std::cout << "\n\tInvalid move." << std::endl;
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

bool replay_prompt() {
    /* Prompts the user to see if they want to play the game again */
    
    char input;
    bool replay = true;
    std::cout << "\n\n\tPlay again? (Y/n): ";
    std::cin >> input;
    if (input == 'n' || input == 'N') replay = false;
    return replay;
}

////
// MAIN //
////

int main() {
    std::srand(std::time(NULL)); // use current time as seed
    Table table;
    int match_num = 1;
    const char USER = 'X'; // symbol for the user
    const char CPU = 'O'; // symbol for the CPU
    bool playing_game = true;
    
    // Game Loop
    while (playing_game) {
        table.clear_board();
        std::cout << "\t_________________________________________________\n\n\n";
        std::cout << "\t- Match " << match_num << " -\n\n";

        // Match Loop
        while (true) {
            table.print();

            // User's turn
            execute_turn(USER, table);
            if (table.is_winner()) {
                std::cout << "\n\t--------\n\tYOU WIN!\n\t--------\n";
                table.user_score++;
                break;
            }

            // Check for draw (can only happen on user's turn)
            if (table.is_draw()) {
                std::cout << "\n\t-----\n\tDRAW!\n\t-----\n";
                break;
            }

            // CPU's turn
            execute_turn(CPU, table);
            if (table.is_winner()) {
                table.cpu_score++;
                std::cout << "\n\t---------\n\tYOU LOST!\n\t---------\n";
                break;
            }
        }

        // Post match
        match_num++;
        table.print();
        table.print_score();
        playing_game = replay_prompt(); // Ask to play again
    }

    std::cout << "\n\n\tThank you for playing!" << std::endl;
}
