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

inline int rand_int(int max) {
    // Random int between 0 and max(exclusive)
    return std::floor(std::rand() * 1.0 / RAND_MAX * max); 
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

        Board(int side_len) : side_len(side_len) {
            for (int i = 0; i < side_len * side_len; i++) {
                graph.push_back(Node(i, side_len));        
            }        
        }

        bool check_winner(char marker) {
            /** 
            * Finds a starting wall for the player being checked, then tries to find
            * a path to the opposite wall by calling find_path() 
            */

            int interval = 1;
            if (marker == 'O') interval = side_len;
            clear_visited();

            // Begin check from the player's start wall
            for (int i = 0; i < interval * side_len; i+=interval) {
                if(find_path(marker, i)) {
                    print();
                    std::cout << marker << " wins!\n\n";
                    return true;
                }
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

        int simulate_moves(char current_player, char other_player) {
            std::vector<Node> sim_graph;
            sim_graph = graph;
            for (int i = 0; i < sim_graph.size(); i++) {
                    
            }
            return 0;
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

    private:

        inline void clear_visited() {
            for (int i = 0; i < side_len * side_len; i++) graph.at(i).visited = false;
        }
       
        bool find_path(char marker, int node_label) {
            /** 
            * Checks the node in the graph at index 'node_label'. If a full path from
            * one wall to another has been reached, return true. If not, return false.
            * This is called recursively to check adjacent nodes.  
            */
            Node* n = &graph.at(node_label);

            // Check if the node has the right marker and is unvisited
            if (n->marker == marker && !n->visited) {
                n->visited = true;

                // Check if the opposite wall has been reached
                if (n->marker == 'X' && n->y == side_len - 1) return true;
                if (n->marker == 'O' && n->x == side_len - 1) return true;

                // Check each adjacent node
                if (n->right != -1) if (find_path(marker, n->right)) return true;
                if (n->b_right != -1) if (find_path(marker, n->b_right)) return true;
                if (n->t_right != -1) if (find_path(marker, n->t_right)) return true;
                if (n->left != -1) if (find_path(marker, n->left)) return true;
                if (n->b_left != -1) if (find_path(marker, n->b_left)) return true;
                if (n->t_left != -1) if (find_path(marker, n->t_left)) return true;
            }
            return false;
        }
};

int main() {
    std::srand(std::time(0));
    int side_len = 4;
    Board board(side_len);
    char user = 'X';
    char cpu = 'O';

    board.simulate_moves(cpu, user);
    
    // Game Loop
    // while (true) {
    //     board.print();
    //     board.get_user_move(user);
    //     if (board.check_winner(user)) break;
    // }

    return 0;
}
