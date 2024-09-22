/**
* This program lets the user play the game called Hex. This version of
* the program is optimized to play more efficiently than the original.
*/

#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <array>

inline int rand_int(int max) {
    // Random int between 0 and max(exclusive)
    return std::floor(std::rand() / (RAND_MAX + 1.0) * max); 
}

class Node {
    /** 
    * A node is a singular space on the board. It can be filled in with a color.
    * The color indicates which player put the piece there.
    */
    public:
        int label;
        int x;
        int y;
        int side_len;
        char marker;
        bool visited;
        
        // Adjacent Nodes
        int t_right;
        int right;
        int b_right;
        int b_left;
        int left;
        int t_left;

        // Constructor
        Node(int label, int side_len) : label(label), side_len(side_len), marker(' '),
            x(label % side_len), y(label / side_len), left(-1), right(-1), b_right(-1), 
            t_left(-1), t_right(-1), b_left(-1), visited(false) {
            
            // Ensure node is in correct bounds
            assert(label >= 0 && label < side_len * side_len);

            // Connect the nodes by direction
            if (label % side_len != 0) left = label - 1;
            if (label % side_len != side_len - 1) right = label + 1;
            if (label / side_len < side_len - 1) b_right = label + side_len;
            if (label / side_len > 0) t_left = label - side_len;
            if (label % side_len != side_len - 1 &&  label / side_len > 0) 
                t_right = label - side_len + 1; 
            if (label % side_len != 0 && label / side_len < side_len - 1)
                b_left = label + side_len - 1;
        }
        
};

class Board {
    /** 
    * The board contains all the nodes and methods used for gameplay.
    */
    
    public:

        std::vector<Node> graph;
        int side_len;
        int node_num;

        Board(int side_len) : side_len(side_len), node_num(side_len * side_len) {
            for (int i = 0; i < node_num; i++) {
                graph.push_back(Node(i, side_len));        
            }        
        }

        void clear() {
            clear_visited(&graph);
            for (int i = 0; i < graph.size(); i++) {
                graph.at(i).marker = ' ';
            }
        }

        bool check_winner(char marker, std::vector<Node>* g) {
            /** 
            * Finds a starting wall for the player being checked, then tries to find
            * a path to the opposite wall by calling find_path() 
            */

            int interval = 1;
            if (marker == 'O') interval = side_len;
            clear_visited(g);

            // Begin check from the player's start wall
            for (int i = 0; i < interval * side_len; i+=interval) {
                if(find_path(marker, i, g)) return true;
            }            
            return false;
        }

        void get_user_move(char marker) {
            /** 
            * Allows the user to input a move
            */
            int x, y;

            while (true) {
                std::cout << "Choose an X then Y coordinate: ";
                std::cin >> x >> y;
                int index = side_len * y + x;
                if (graph.at(index).marker == ' ') {
                    graph.at(index).marker = marker;
                    break;
                } else {
                    std::cout << "\nInvalid space!\n";
                }
            }
        }

        int simulate_moves(int sim_num, char current_player, char other_player) {
            std::vector<Node> sim_graph;
            std::vector<Node> sim_graph_t;
            std::vector<int> rates(node_num);
            std::fill(rates.begin(), rates.end(), 0);
            char cp = current_player;
            int r_index;
            int wins;
            int empty_nodes = -1;

            // Get the number of empty nodes
            for (Node n : graph) if(n.marker == ' ') empty_nodes++;

            // Run simulations with every potential move that can be made
            for (int i = 0; i < node_num; i++) {
                if (graph.at(i).marker != ' ') continue; // If the current node is not empty, skip it
                sim_graph_t = graph;
                sim_graph_t.at(i).marker = current_player;              
                wins = 0;

                // Simulate 'sim_num' games with the move 
                for (int j = 0; j < sim_num; j++) {
                    sim_graph = sim_graph_t;

                    // Randomly fill in every space, alternating cpu and user
                    for (int k = 0; k < empty_nodes; k++) {
                        while (true) { 
                            r_index = rand_int(node_num);
                            if(sim_graph.at(r_index).marker == ' ') {
                                sim_graph.at(r_index).marker = current_player;
                                break;
                            } 
                        }
                        std::swap(current_player, other_player);
                    }

                    // Increment over wins when the cpu won with the move
                    if (check_winner(cp, &sim_graph)) wins++;
                }
                rates.at(i) = wins;
            }

            // Return the move with the most wins
            int b_index = 0;
            int biggest = 0;
            for (int i = 0; i < rates.size(); i++) {
                if (rates.at(i) > biggest) {
                    biggest = rates.at(i);
                    b_index = i;
                }
            }
            return b_index;
        }
        
        void print() {
            /** 
            * Prints the board to the console
            */
            int counter = 0;
            std::cout << "\n  ";
            for (int i = 0; i < side_len; i++) std::cout << ' ' << i << "  ";
            for (Node n : graph) {
                if(counter % side_len == 0) {
                    std::cout << '\n' << n.y;
                    if (n.y < 10) std::cout << ' ';
                    for (int i = 0; i < counter / side_len; i++) std::cout << "  ";
                }
                counter++;
                std::cout << '{' << n.marker << "} ";
            }
            std::cout << "\n\n";
        }

        bool is_full() {
            for (Node n : graph) if (n.marker == ' ') return false;
            return true;
        }

    private:

        inline void clear_visited(std::vector<Node>* g) {
            for (int i = 0; i < node_num; i++) g->at(i).visited = false;
        }

        
       
        bool find_path(char marker, int node_label, std::vector<Node>* g) {
            /** 
            * Checks the node in the graph at index 'node_label'. If a full path from
            * one wall to another has been reached, return true. If not, return false.
            * This is called recursively to check adjacent nodes.  
            */
            Node* n = &g->at(node_label);

            // Check if the node has the right marker and is unvisited
            if (n->marker == marker && !n->visited) {
                n->visited = true;

                // Check if the opposite wall has been reached
                if (n->marker == 'X' && n->y == side_len - 1) return true;
                if (n->marker == 'O' && n->x == side_len - 1) return true;

                // Check each adjacent node
                if (n->right != -1) if (find_path(marker, n->right, g)) return true;
                if (n->b_right != -1) if (find_path(marker, n->b_right, g)) return true;
                if (n->t_right != -1) if (find_path(marker, n->t_right, g)) return true;
                if (n->left != -1) if (find_path(marker, n->left, g)) return true;
                if (n->b_left != -1) if (find_path(marker, n->b_left, g)) return true;
                if (n->t_left != -1) if (find_path(marker, n->t_left, g)) return true;
            }
            return false;
        }
};

void play_hex_as_x(Board board, int number_of_sims, int& user_score, int& cpu_score,
                   int& x_wins, int& o_wins, int& user_x_wins, int& user_x_losses) {
    char user = 'X';
    char cpu = 'O';
    while (true) {

        // User Move
        board.print();
        // board.get_user_move(user);
        board.graph.at(board.simulate_moves(number_of_sims, user, cpu)).marker = user;
        if (board.check_winner(user, &board.graph)) { 
            user_score++;
            user_x_wins++;
            x_wins++;
            break;
        }
        if (board.is_full()) break;
    
        // CPU Move
        board.print();
        board.graph.at(board.simulate_moves(number_of_sims, cpu, user)).marker = cpu;
        if (board.check_winner(cpu, &board.graph)) {
            cpu_score++;
            user_x_losses++;
            o_wins++;
            break;
        }
        if (board.is_full()) break;
    }
    board.print();
}

void play_hex_as_o(Board board, int number_of_sims, int& user_score, int& cpu_score,
                   int& x_wins, int& o_wins, int& user_o_wins, int& user_o_losses) {
    char user = 'O';
    char cpu = 'X';

    while (true) {
        
        // CPU Move
        board.graph.at(board.simulate_moves(number_of_sims, cpu, user)).marker = cpu;
        if (board.check_winner(cpu, &board.graph)) {
            cpu_score++;
            user_o_losses++;
            x_wins++;
            break;
        }
        if (board.is_full()) break;
        board.print();
        

        // User Move
        // board.get_user_move(user);
        board.graph.at(board.simulate_moves(number_of_sims, user, cpu)).marker = user;
        if (board.check_winner(user, &board.graph)) { 
            user_score++;
            user_o_wins++;
            o_wins++;
            break;
        }
        if (board.is_full()) break;
        board.print();
    }
    board.print();
}

int main() {
    std::srand(std::time(0));

    int side_len = 5;
    int number_of_sims = 1000;
    int score_limit = 25;

    char user = 'X';
    char cpu = 'O';
    int user_score = 0;
    int cpu_score = 0;
    int x_wins = 0;
    int o_wins = 0;
    int user_x_wins = 0;
    int user_o_wins = 0;
    int user_x_losses = 0;
    int user_o_losses = 0;

    Board board(side_len);
    
    // Game Loop
    while (user_score < score_limit && cpu_score < score_limit) {
        
        // Round Loop
        if (user == 'X') {
            play_hex_as_x(board, number_of_sims, user_score, cpu_score, x_wins, o_wins,
                          user_x_wins, user_x_losses);
        } else {
            play_hex_as_o(board, number_of_sims, user_score, cpu_score, x_wins, o_wins,
                          user_o_wins, user_o_losses);
        }

        // End of round / Scoreboard
        std::cout << "User score: " << user_score << '\n';
        std::cout << "CPU Score: " << cpu_score << '\n';
       
        std::swap(user, cpu); // Switch Sides
    }

    std::cout << "\nStatistics:\n";
    std::cout << "Total X wins: " << x_wins << '\n';
    std::cout << "Total O wins: " << o_wins << '\n';
    std::cout << "\nUser Statistics:\n";
    std::cout << "X record: " << user_x_wins << " - " << user_x_losses << '\n';
    std::cout << "O record: " << user_o_wins << " - " << user_o_losses << "\n\n\n";
    std::cout << "\n\nThank you for playing!\n\n";

    return 0;
}
