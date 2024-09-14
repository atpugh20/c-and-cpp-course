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
        Node* t_left;
        Node* t_right;
        Node* left;
        Node* right;
        Node* b_left;
        Node* b_right;
        
        // Constructor
        Node(int x, int y) : x(x), y(y), color("none"),  
                             t_left(nullptr), t_right(nullptr), left(nullptr),
                             b_left(nullptr), b_right(nullptr), right(nullptr) {}
};  

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
            
        }

        bool node_is_empty(int x, int y) {
            /** 
             * Checks if the node at the selected coordinates it empty. 
             * If yes return true, otherwise return false.
             */
            bool empty = false;
            if (x >= 0 && y >= 0 && x < size && y < size) {
                if (graph.at(y).at(x)->color == "none") {
                    empty = true;
                }
            }
            return empty;
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

std::ostream& operator<<(std::ostream& out, const Node* n) {
    /** 
     * Overloads the << operator to be able to print a node to the console. 
     */
    out << "Coordinates: (" << n->x << ", " << n->y << "), ";
    out << "Color: " << n->color;
    return out;    
}

int main() {
    std::srand(std::time(0));

    Board* board = new Board(11);
    board->print();
    board->get_user_move("red");
    board->print();

    delete board;
    return 0;
}
