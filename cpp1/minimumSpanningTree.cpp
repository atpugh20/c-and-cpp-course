/* Alexander Pugh
 *
 * This program implements Prim's minimum spanning tree algorithm.  
 *
 * */

//// INIT ////

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

inline double prob() { return (static_cast<double>(std::rand())/RAND_MAX);}

//// CLASSES ////

class Node {
    /* A node is a basic element that is represented within 
     * the graph, and may be connected to other nodes */

    public:
    int label;
    int prev;
    bool visited = false;

    // Constructor
    Node(int label, int prev = -1) : label(label), prev(prev) {}
};

class Graph {
    /* A Graph object is a matrix of edges that represent how nodes are connected.
     * There are 'size' nodes and the maximum weight of the endge is 'max_dist'.
     * The Graph creates the connection between the nodes */
    
    const int max_dist;
    int size;
    int start;
    std::vector<std::vector<int>> matrix;
    std::vector<Node> nodes;

    public:
    
    int tree_dist;
    
    // Constructor
    Graph(int size) : size(size), max_dist(9), tree_dist(0) {
        fill();
    }
    
    void fill() {
        /* Fills the matrix with edges. There is a 0.2 probability
         * that an edge will be generated. Otherwise, a 0
         * will be filled at the index */

        matrix.clear();
        nodes.clear();
        for (int i = 0; i < size; i++) {
            Node node(i);
            nodes.push_back(node);
            std::vector<int> v;
            matrix.push_back(v);
            for (int j = 0; j < size; j++) {
                if (i == j) matrix.at(i).push_back(0);
                else if (prob() < 0.2) matrix.at(i).push_back(std::rand() % max_dist + 1);
                else matrix.at(i).push_back(0);
            }
        }
    }

    void print() {
        /* Prints the graph matrix to the console */
        std::cout << '\n';
        std::cout << "-------GRAPH-------\n\n";
        for (std::vector<int> row : matrix) {
            for (int dist : row) {
                std::cout << dist << " ";
            }
            std::cout << '\n';
        }
        std::cout << "\n-------------------\n\n";
    }

    int get_shortest(std::vector<int> row) {
        /* Returns the index of the closest unvisited node. 
         * If there are no nodes left, -1 is returned */

        int shortest = 0;
        int shortest_dist = 10000;

        for (int i = 0; i < row.size(); i++) {
            // If node is unvisited, has an edge, and is shorter than the current shortest distance
            if (!nodes.at(i).visited && row.at(i) && row.at(i) < shortest_dist) {
                shortest = i;
                shortest_dist = row.at(i);
            }
        }
        
        // Will return -1 if there are no more edges from the current node
        if (shortest_dist == 10000) shortest = -1;

        return shortest;
    }

    void prim_tree(int current) {
        /* Uses a recursive prim's algorithm to find the
         * minimum spanning tree for the current graph.
         * The shortest path is continuously used to decide
         * the next node */

        int shortest = 0;
        // While more paths remain
        while (shortest != -1) {
            nodes.at(current).visited = true;
            shortest = get_shortest(matrix.at(current));
            // If there is a path that can be used, call function on its node
            if (shortest != -1) {
                nodes.at(shortest).prev = current;
                tree_dist += matrix.at(current).at(shortest);
                std::cout << nodes.at(current).label << "->" << nodes.at(shortest).label << '\n';
                prim_tree(shortest);
            }
        }
    }
};

//// MAIN /////

int main() {
    std::srand(std::time(0));
    int graph_size = 50;
    int start_node = -1;

    // Create and print graph
    Graph graph(graph_size);
    graph.print();

    // Get start node from user
    while (start_node < 0 || start_node > graph_size - 1) {
        std::cout << "\nChoose a starting integer (0-" << graph_size - 1 << "): ";
        std::cin >> start_node;
    }

    // Find a shortest spanning tree. If there is one, print it
    std::cout << "\n\n-------Minimum Spanning Tree-------\n\n";
    graph.prim_tree(start_node);
    if (graph.tree_dist > 0) {
        std::cout << "\n\nMinimum Spanning Tree Distance: " << graph.tree_dist;
    } else {
        std::cout << "\n\nThere is no path from " << start_node << " as a start node!";
    }
    std::cout << "\n\n-----------------------------------\n\n";

    
    return 0;
}
