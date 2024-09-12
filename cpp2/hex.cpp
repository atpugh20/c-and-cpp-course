#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Node {
    public:
        Node* t_left;
        Node* t_right;
        Node* left;
        Node* right;
        Node* b_left;
        Node* b_right;
        std::string color;
        
        // Constructor
        Node() : t_left(nullptr), t_right(nullptr), left(nullptr),
                 b_left(nullptr), b_right(nullptr), right(nullptr),
                 color("grey") {}
};  

class Board {
    public:
        int size;
        std::vector<std::vector<Node*>> graph;
    
        // Constructor
        Board(int size) : size(size) {
            for (int i = 0; i < size; i++) {
                std::vector<Node*> v;
                for (int j = 0; j < size; j++) {
                    
                    v.push_back(new Node);                   
                }
                graph.push_back(v);
            } 
        }

        // Destructor
        ~Board() {
            for (std::vector<Node*> row : graph) {
                for (Node* node : row) {
                    delete node;
                }
            }    
        }
};

int main() {
    Board* board = new Board(5);
    for (std::vector<Node*> row : board->graph) {
        std::cout << '\n';
        for (Node* node : row) {
            std::cout << node->color << " ";
        } 
    }

    delete board;
    return 0;
}
