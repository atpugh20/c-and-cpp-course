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

inline void print_title() {
    std::cout << "\n\n";
    std::cout << "--------------------------------------------------------------------\n";
    std::cout << "|                                                                  |\n";
    std::cout << "|                         PRIM'S ALGORITHM                         |\n";
    std::cout << "|                                                                  |\n";
    std::cout << "--------------------------------------------------------------------\n\n";
}

//// CLASSES ////

class Edge {
    /* An edge represents a path between two nodes */

    public:
        int from;
        int to;
        int weight;
    
        Edge(int from, int to, int weight) : from(from), to(to), weight(weight) {}
};

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
    std::vector<Edge> edges;

    public:
    
        int tree_dist;
        
        // Constructor
        Graph(int size) : size(size), max_dist(9), tree_dist(0) {
            fill();
            sort_edges();
        }
        
        void fill() {
            /* Fills the matrix with edges. There is a 0.2 probability
             * that an edge will be generated. Otherwise , a 0 will be
             * filled at the index */

            matrix.clear();
            nodes.clear();
            edges.clear();
            for (int i = 0; i < size; i++) {
                Node node(i);
                nodes.push_back(node);
                std::vector<int> v;
                matrix.push_back(v);
                for (int j = 0; j < size; j++) {
                    if (i == j) matrix.at(i).push_back(0);
                    else if (prob() < 0.2) matrix.at(i).push_back(std::rand() % max_dist + 1);
                    else matrix.at(i).push_back(0);
                    Edge e(i, j, matrix.at(i).at(j));
                    edges.push_back(e);
                }
            }

        }

        void sort_edges() {
            /* Sorts the edges vector by the weight 
             * of the edge, from shortest to furthest */ 
            
            for (int i = 0; i < edges.size() - 1; i++) {
                for (int j = 0; j < edges.size() - 1; j++) {
                    if (edges.at(j).weight > edges.at(j+1).weight) {
                        std::swap(edges.at(j), edges.at(j+1));
                    }    
                }
            }
        }

        int get_next_node() {
            /* Grabs the next edge in edges that connects to an unvisited node. 
             * This requires that the vector edges is sorted to work correctly  */

            int next_node = -1;
            for (Edge e : edges) {
                // If there is an edge, the 'from' node has been visited, and the 'to' node is unvisited
                if (e.weight != 0 && nodes.at(e.from).visited && !nodes.at(e.to).visited) {
                    next_node = nodes.at(e.to).label;
                    tree_dist += e.weight; // updates total distance traveled
                    return next_node;
                }
            }
            return next_node; // returns -1 if there are no more available nodes
        }

        void prim_tree(int current) {
            /* This function uses recursion to find the minimum spanning tree of the graph 
             * using Prim's algorithm. */

            nodes.at(current).visited = true;
            int next = get_next_node();

            // If there are remaining nodes
            if (next != -1) {
                // prints the current branch of the tree, along with the current distance traveled
                std::cout << nodes.at(current).label << "\t->\t" << nodes.at(next).label << '\t';
                std::cout << "Distance traveled: " << tree_dist << '\n';
                
                // moves to the next node
                prim_tree(next);
            } else { 
                std::cout << "\nFINISHED";
            }
        }

        void print() {
            /* Prints the graph matrix to the console */
            std::cout << '\n';
            std::cout << "-------------------------------GRAPH--------------------------------\n\n\n";
            for (int i = -1; i < size; i++) {
                for (int j = -1; j < size; j++) {
                    if (i == -1 && j == -1) {
                        std::cout << '\t';
                    } else if (i == -1) { 
                        std::cout << j << ' ';
                        if (j < 10) std::cout << ' ';
                        if (j == size - 1) std::cout << "\n\n";
                    } else if (j == -1) {
                        std::cout << i << '\t';
                    } else {
                        std::cout << matrix.at(i).at(j) << "  ";
                    }
                }
                std::cout << '\n';
            } 
            std::cout << "\n\n--------------------------------------------------------------------\n\n";
        }
};

//// MAIN ////

int main() {
    std::srand(std::time(0));
    int graph_size = 20;
    int start_node = -1;

    print_title();

    // Create and print graph
    Graph graph(graph_size);
    graph.print();

    // Get start node from user
    while (start_node < 0 || start_node > graph_size - 1) {
        std::cout << "\nChoose a starting integer (0-" << graph_size - 1 << "): ";
        std::cin >> start_node;
    }

    // Find a shortest spanning tree. If there is one, print it
    std::cout << "\n\n-------------Minimum Spanning Tree-------------\n\n";
    graph.prim_tree(start_node);
    if (graph.tree_dist > 0) {
        std::cout << "\n\nMinimum Spanning Tree Distance: " << graph.tree_dist;
    } else {
        std::cout << "\n\nThere is no path from " << start_node << " as a start node!";
    }
    std::cout << "\n\n-----------------------------------------------\n\n";

    
    return 0;
}
