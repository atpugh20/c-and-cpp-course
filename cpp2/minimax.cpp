/**
* Alex Pugh 
*
* This program implements the minimax 
* algorithm for deciding the next best move.
* 
* Alpha beta pruning can be used as well if the commented 
* lines in the minimax conditionals are uncommented out.
*/

///// INIT /////

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

const int INF = 100000;

///// FUNCTIONS /////

int get_random() {
    /** 
    * Generates a random int between -5 and 5    
    */
    
    int result = std::floor((static_cast<double>(std::rand()) / RAND_MAX) * 11 - 5); 
        
    return result;
}

int minimax(int choices, int depth, int alpha, int beta, bool maximizing_player) {
    /** 
    * This algorithm decides what the next best
    * move is based on potential future best moves.
    * - choices - number of choices to be decided between each turn
    * - depth - number of future moves to predict
    */
    
    int eval;
    
    // At the bottom of the tree
    if (depth == 0) {
        int num = get_random();
        std::cout << num << " ";
        return num;
    }
    if (maximizing_player) {
        int max_eval = -INF;
        for (int i = 0; i < choices; i++) {
            eval = minimax(choices, depth - 1, alpha, beta, false);
            max_eval = std::max(max_eval, eval);
            alpha = std::max(alpha, eval);
            // if (beta <= alpha) break;
        }
        return max_eval;
    } else {
        int min_eval = INF;
        for (int i = 0; i < choices; i++) {
            eval = minimax(choices, depth - 1, alpha, beta, true);
            min_eval = std::min(min_eval, eval);
            beta = std::min(beta, eval);
            // if (beta <= alpha) break;
        }
        return min_eval;
    }
}

///// MAIN /////

int main() {
    std::srand(std::time(0));
    const int choices = 2;
    const int depth = 3;
    
    std::cout << "\n---MINIMAX ALGORITHM---";
    std::cout << "\n\nBottom Nodes:\n\n";

    int move = minimax(choices, depth, -INF, INF, true);
    
    std::cout << "\n\nBest Move:\n\n" << move << "\n\n";
    return 0;
}
