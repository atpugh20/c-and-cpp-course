/**
* This program lets the user play the game called Hex. This version of
* the program is optimized to play more efficiently than the original.
* It also uses the Union Find algorithm rather than Dijkstra's algorithm
* to find a winning path.
*/

#include <iostream>
#include <string>
#include <vector>
#include <cassert>

class Node {
    /** 
    * A node is a singular space on the board. It can be filled in with a color.
    * The color indicates which player put the piece there.
    */
    public:
        int label;
        int side_len;
        std::string marker;
        bool visited;
        
        // Adjacent Nodes
        int t_right;
        int right;
        int b_right;
        int b_left;
        int left;
        int t_left;

        // Constructor
        Node(int label, int side_len) : label(label), side_len(side_len), marker(" "),
                                        left(-1), right(-1), b_right(-1), 
                                        t_left(-1), t_right(-1), b_left(-1) {
            
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

        void print() {
            /** 
            * Prints the board to the console (Will bring over old version)
            */
            int counter = 0;
            for (Node n : graph) {
                std::cout << '[' << n.marker << "] ";
                counter++;
                if(counter % side_len == 0) {
                    std::cout << '\n';
                    for (int i = 0; i < counter / side_len; i++) std::cout << "  ";
                }
            }
        }
};

int main() {
    int side_len = 4;
    Board board(side_len);
    std::string player = "X";
    std::string cpu = "O";

    board.print();
    return 0;
}
