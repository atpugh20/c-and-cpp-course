/* This program implements the famous pathfinding 
 * algorithm known as "Dijkstra's Algorithm." */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <array>
#include <vector>
#include <climits>
#include <typeinfo>

const int NODES = 9;

class Node {
    public:
        int n;
        int dist;
        Node* prev;

        // Constructor
        Node(int n, int dist = INT_MAX, Node* prev = nullptr) :
            n(n), dist(dist), prev(prev) {}
};

class Graph {
    /* The Graph class contains the mapping of each node to the other */

    public:
        std::array<std::array<int, NODES>, NODES> matrix; 
        
        // Constructor
        Graph() {
            for (int i = 0; i < matrix.size(); i++) {
                matrix[i].fill(-1); // fills each std::array with -1
            }
        }
        // Methods
        
        void generate_edges() {
            /* Fills the matrix with each nodes edges to the other nubers.
             * This function assumes edges travel both ways */

            for (int i = 0; i < NODES; i++) {
                for (int j = 0; j < NODES; j++) {
                    if (i == j) { 
                        matrix[i][j] = 0; // set distance to itself to 0
                    } else if (matrix[j][i] != -1) {
                        matrix[i][j] = matrix[j][i]; // if path already created, copy it
                    } else {
                        matrix[i][j] = rand() % 3; // decide if there is a path or not
                    }
                }
            }
        }

        void print() {
            /* prints matrix as a table */
 
            for (int i = -1; i < NODES; i++) {
                for (int j = -1; j < NODES; j++) {
                    if (i == -1 && j == -1) std::cout << ' ';
                    else if (i == -1) std::cout << j;
                    else if (j == -1) std::cout << i;
                    else std::cout << matrix[i][j];
                    std::cout << " ";
                }
                std::cout << "\n";
            }
            std::cout << "\n";
        }
};

class Dijkstra {
    /* This class handles the pathfinding portion of the program. 
     * It sorts through all nodes starting from the start-node until
     * it reaches the end-node.  */

    public:
        Graph graph;
        std::vector<Node*> unvisited;
        std::vector<Node*> visited;
        std::vector<Node*> neighbors;

        // Constructor
        Dijkstra() {
            graph.generate_edges();
            graph.print();
            for (int i = 0; i < NODES; i++) {
                unvisited.push_back(new Node(i));    
            }
        }
        
        void sort_unvisited() {
            /* Sorts the unvisited nodes by distance, from shortest to largest */

            for (int i = 0; i < unvisited.size() - 1; i++) {
                for (int j = 0; j < unvisited.size() - 1; j++) {
                    if (unvisited.at(j)->dist > unvisited.at(j + 1)->dist) {
                        Node* temp = unvisited.at(j);
                        unvisited.at(j) = unvisited.at(j+1);
                        unvisited.at(j+1) = temp;
                    } 
                }
            }
        }

        bool is_visited(int n) {
            bool vis = false;
            if (!visited.size()) return vis;
            for (int i = 0; i < visited.size(); i++) {
                if (visited.at(i)->n == n) vis = true;
            }
            return vis;
        }

        std::vector<Node*> get_shortest_path(int start, int end) {
            /* Sweeps through all the nodes and their paths, starting from 'start'
             * until the shortest distance to 'end' is found.  */

            // set start distance to 0 and start the loop
            unvisited.at(start)->dist = 0;
            
            while (unvisited.size()) {
                // get closest node and set it to current
                sort_unvisited();
                for (int i = 0; i < unvisited.size(); i++) {
                    std::cout << unvisited.at(i)->n << " ";
                }
                std::cout << '\n';

                Node* current_node = unvisited.at(0);
                int cn = current_node->n; // current node identifier
                
                // set current node as visited
                unvisited.erase(unvisited.begin());
                visited.insert(visited.begin(), current_node);

                if (cn == end) return visited; // reaches final node
                
                // Get the neighbors of the current node, and update
                // their node distances according to the graph matrix
                for (int i = 0; i < graph.matrix[cn].size(); i++) {
                    if (!is_visited(i)) {
                        int distance = graph.matrix[cn][i];
                        if (distance != 0) {
                            for (int j = 0; j < unvisited.size(); j++) {
                                if (i == unvisited.at(j)->n) {
                                    int sum = distance + current_node->dist;
                                    if (sum < unvisited.at(j)->dist) {
                                        unvisited.at(j)->dist = distance + current_node->dist;
                                        unvisited.at(j)->prev = current_node;
                                    }
                                    //std::cout << unvisited.at(j)->n << ": " << unvisited.at(j)->dist << "\n";
                                }
                            }
                        }
                    }
                }
            }

            return visited;
        }
};


int main() {
    srand(time(0));
    Dijkstra finder;
    std::vector<Node*> shortest = finder.get_shortest_path(3, 8);
    std::cout << shortest.at(0)->dist << "\n\n";
    Node* path = shortest.at(0);
    while (path != nullptr) {
        std::cout << path->n << "->";
        path = path->prev;
    }
}

