/* 
    Alexander Pugh

    This program lets the user play the game called Hex.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

class Node {
    /** 
     * A node is a space that a user can place a piece on. These 
     * nodes are connected to adjacent nodes through pointer references.
     */
    public:
        int x;
        int y;
        std::string color;
        bool visited;
        Node* t_left;
        Node* t_right;
        Node* left;
        Node* right;
        Node* b_left;
        Node* b_right;
        
        // Constructor
        Node(int x, int y) : x(x), y(y), color("none"), visited(false), 
                             t_left(nullptr), t_right(nullptr), left(nullptr),
                             b_left(nullptr), b_right(nullptr), right(nullptr) {}
}; 

std::ostream& operator<<(std::ostream& out, const Node* n) {
    /** 
     * Overloads the << operator to be able to print a node to the console. 
     */
    out << "Coordinates: (" << n->x << ", " << n->y << "), ";
    out << "Color: " << n->color;
    return out;    
}

class Board {
    /** 
     * The board is an object that contains the full collection of nodes.
     */
    public:
        int size;
        std::vector<std::vector<Node*>> graph;
    
        // Constructor
        Board(int size) : size(size) {
            fill_nodes();
            connect_nodes();
        } 

        // Destructor
        ~Board() {
            for (std::vector<Node*> row : graph) {
                for (Node* node : row) {
                    delete node;
                }
            }    
        }

        void print() {
            /** 
             * Prints the board to the console. Below are the options for the spaces:
             * '[ ]' - Empty Space
             * '[X]' - Player 1
             * '[O]' - Player 2
             * '[?]' - Incorrect color string (for debugging)
             */
            std::cout << "\n\nRed (X): Top <-> Bottom\n";
            std::cout << "Blue (O): Left <-> Right\n\n";
            for (int y = -1; y <= size; y++) {
                for (int indent = 0; indent < y; indent++) std::cout << "  ";
                for (int x = -1; x <= size; x++) {
                    
                    if ((x == -1 && y == -1) ||
                        (x == size && y == -1) || 
                        (y == size && x == -1) || 
                        (x == size && y == size)) { 
                        std::cout << "   "; 
                    } else if (x == -1) { 
                        std::cout << y << "  ";
                    } else if (x == size) { 
                        std::cout << " " << y;
                    } else if (y == -1) { 
                        std::cout << " " << x << "  ";
                    } else if (y == size) {
                        std::cout << x << "   ";
                    } else {
                        std::cout << "[";
                        if (graph.at(y).at(x)->color == "none") std::cout << " ";
                        else if (graph.at(y).at(x)->color == "red") std::cout << "X";
                        else if (graph.at(y).at(x)->color == "blue") std::cout << "O";
                        else std::cout << "?";
                        std::cout << "] ";   
                    }
                }
                std::cout << '\n';
            }
            std::cout << "\n\n";
        }

        void get_user_move(std::string player_color) {
            /** 
             * This function allows the player to input a move, 
             * checks if the input space is empty,
             * then fills in the space with the appropriate color.
             */
            int x;
            int y;
            while (true) {
                std::cout << "Input an X coordinate then a Y coordinate (X=Horizontal; Y=Vertical):\n";
                std::cin >> x;
                std::cin >> y;
                if (node_is_empty(x, y)) break;
                else std::cout << "Invalid coordinate!\n";
            }
            graph.at(y).at(x)->color = player_color;
        }

        void get_cpu_move(std::string player_color) {
            int x;
            int y;
            while (true) {
                x = (std::rand() / static_cast<float> (RAND_MAX)) * size;
                y = (std::rand() / static_cast<float> (RAND_MAX)) * size;
                if (node_is_empty(x, y)) break;
            }
            graph.at(y).at(x)->color = player_color;
        }

        bool node_is_empty(int x, int y) {
            /** 
             * Checks if the node at the selected coordinates it empty. 
             * If empty, return true. Otherwise, return false.
             */
            if (x >= 0 && y >= 0 && x < size && y < size) {
                if (graph.at(y).at(x)->color == "none") {
                    return true;
                }
            }
            return false;
        }

        bool spaces_remain() {
            /**
             * Checks if any nodes are unfilled. 
             * If there is at least one space available, return true.
             * Otherwise, return false.
             */
            for (std::vector<Node*> row : graph) {
                for (Node* node : row) {
                    if (node->color == "none") return true; 
                }
            }
            return false;
        }

        bool check_for_winner(Node* n, std::string color) {
            if (n->color == color && !n->visited) {
                n->visited = true;
                
                // Checks for the win conditions
                if (n->color == "red" && n->y == size - 1) return true;
                if (n->color == "blue" && n->x == size - 1) return true;
                
                // Checks the neighbor nodes
                if (n->right->color == color &&
                    !n->right->visited) {
                    check_for_winner(n->right, color);
                }
                if (n->b_right->color == color &&
                    !n->b_right->visited) {
                    check_for_winner(n->b_right, color);
                }
                if (n->t_right->color == color &&
                    !n->t_right->visited) {
                    check_for_winner(n->t_right, color);
                }
                if (n->b_left->color == color &&
                    !n->b_left->visited) {
                    check_for_winner(n->b_left, color);
                }
                if (n->t_left->color == color &&
                    !n->t_left->visited) {
                    check_for_winner(n->t_left, color);
                }
                if (n->left->color == color &&
                    !n->left->visited) {
                    check_for_winner(n->left, color);
                }
            }
            // If the end is not reached
            return false;
        }

        void clear_visited() {
            /** 
             * Sets the visited attribute of all nodes to false.
             */
            for (std::vector<Node*> row : graph) {
                for (Node* n : row) {
                    n->visited = false;
                }
            }
        }

    private:
        void fill_nodes() {
            /**
             * Pushes all needed nodes into the graph vectors. Because the nodes 
             * have pointer references to unknown nodes, they will be reserved
             * in the heap.
             */
            for (int i = 0; i < size; i++) {
                std::vector<Node*> v;
                for (int j = 0; j < size; j++) { 
                    v.push_back(new Node(j, i));
                }
                graph.push_back(v);
            }
        }

        

        void connect_nodes() {
            /**
             * Connects all the nodes together by checking the coordinates of the current node. 
             * If a side is empty, it will remain a nullptr.
             */
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    // Top Right
                    if (i > 0 && j < size - 1) graph.at(i).at(j)->t_right = graph.at(i-1).at(j+1);
                    // Right
                    if (j < size - 1) graph.at(i).at(j)->right = graph.at(i).at(j+1);
                    // Bottom Right
                    if (i < size - 1) graph.at(i).at(j)->b_right = graph.at(i+1).at(j);
                    // Bottom Left
                    if (i < size - 1 && j > 0) graph.at(i).at(j)->b_left = graph.at(i+1).at(j-1);
                    // Left
                    if (j > 0) graph.at(i).at(j)->left = graph.at(i).at(j-1);
                    // Top Left
                    if (i > 0) graph.at(i).at(j)->t_left = graph.at(i-1).at(j);
                }
            } 
        }
};

void print_title() {
    std::cout << '\n';
    std::cout << "-----------------------------------------------------------------------\n";
    std::cout << "|                                                                     |\n";
    std::cout << "|                                 HEX                                 |\n";
    std::cout << "|                                                                     |\n";
    std::cout << "-----------------------------------------------------------------------\n";
}

int main() {
    std::srand(std::time(0));
    Board* board = new Board(11);
    std::string user_color = "red";
    std::string cpu_color = "blue";
    bool winner = false;

    print_title();
    
    // Game Loop
    while (true) {
        board->print();
        board->get_user_move(user_color);
        for (Node* n : board->graph.at(0)) {        
            if (board->check_for_winner(n, user_color)) {
                std::cout << "You win!";
                winner = true;
                break;
            }
        }
        if (winner) break;
//        if (!board->spaces_remain()) break;
//        board->get_cpu_move(cpu_color);
//        if (!board->spaces_remain()) break;
    }
    
    board->print();
    delete board;
    return 0;
}
