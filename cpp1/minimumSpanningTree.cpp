/* This program implements two  */

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

inline double prob() { return (static_cast<double>(std::rand())/RAND_MAX);}

class Node {
    public:
    int label;
    
    bool visited = false;

    // Constructor
    Node(int label) : label(label) {}
};

class Graph {
    int size;
    std::vector<std::vector<int>> matrix;
    std::vector<Node>
    public:

    // Constructor
    Graph(int size) : size(size) {
        fill();
    }
    
    void fill() {
        /* Fills the matrix with edges. There is a 0.2 probability
         * that an edge, or a 1, will be generated. Otherwise, a 0
         * will be filled at the index */

        matrix.clear();
        for (int i = 0; i < size; i++) {
            std::vector<int> v;
            matrix.push_back(v);
            for (int j = 0; j < size; j++) {
                if (i == j) matrix.at(i).push_back(0);
                else if (prob() < 0.2) matrix.at(i).push_back(1);
                else matrix.at(i).push_back(0);
            }
        }
    }

    void print() {
        /* Prints the graph matrix to the console */

        std::cout << '\n';
        for (std::vector<int> row : matrix) {
            for (int dist : row) {
                std::cout << dist << " ";
            }
            std::cout << '\n';
        }
    }

    int get_shortest(std::vector<int> row) {
        /* */
        std::vector<int> temp = row;
        for (int i = 0; i < temp.size() - 1; i++) {
            for (int j = 0; j < temp.size() - 1; j++) {
                if (temp.at(j) > temp.at(j+1)) {
                    std::swap(temp.at(j), temp.at(j+1));
                }
            }
        }
        for (Node n : temp) if (n.dist && !n.visited) return n.to;
        return -1;
    }

    void prim_tree(int start) {
        
        int shortest = get_shortest(matrix.at(start));
        if (shortest != -1) prim_tree(shortest);
    }
    
};

int main() {
    std::srand(std::time(0));
    int graph_size = 25;

    Graph graph(graph_size);
    graph.print();
    graph.prim_tree(0);

    return 0;
}
