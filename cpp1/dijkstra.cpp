/* This program implements the famous pathfinding 
 * algorithm known as "Dijkstra's Algorithm." */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <array>
#include <vector>
#include <climits>

const int MAX_DIST = 100000;
const int NODES = 25;

class Node {
    /* The basic unit of a path that will be 
     * generated with the algorithm. */

    public:
        int n; // identifier
        int dist; // distance to start node
        Node* prev; // previous node

        // Constructor
        Node(int n, int dist = MAX_DIST, Node* prev = nullptr) :
            n(n), dist(dist), prev(prev) {}
};

class Graph {
    /* The Graph class contains the mapping of each node to the other. 
     * If the value of an edge is greater than 0, then there is a path.
     * This value is also the weight of the path. */

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
                        // There is a 10% chance of generating an edge between 1-9
                        if (rand() % 100 / 100.0 < 0.1) matrix[i][j] = rand() % 9 + 1;
                        else matrix[i][j] = 0;
                    }
                }
            }
        }

        void print() {
            /* prints out the matrix as a table */

            std::cout << "-------Graph-------\n\n\n";
            for (int i = -1; i < NODES; i++) {
                for (int j = -1; j < NODES; j++) {
                    if (i == -1 && j == -1) {
                        std::cout << '\t';
                    } else if (i == -1) { 
                        std::cout << j << ' ';
                        if (j < 10) std::cout << ' ';
                        if (j == NODES - 1) std::cout << "\n\n";
                    } else if (j == -1) { 
                        std::cout << i << '\t';
                    } else { 
                        std::cout << matrix[i][j] << "  "; 
                    }
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
        float total_distance = 0.0f;
        int total_paths = 0;

        // Constructor
        Dijkstra() {
            graph.generate_edges();
            reset_vectors();
        }
        // Destructor
        ~Dijkstra() {
            for (Node* node : unvisited) delete node;
            for (Node* node : visited) delete node;
        }

        // Methods

        void reset_vectors() {
            /* Releases all nodes from memory, clears the vectors,
             * then restores the unvisited vector back to default */

            for (Node* node : unvisited) delete node;
            for (Node* node : visited) delete node;
            unvisited.clear();
            visited.clear();

            for (int i = 0; i < NODES; i++) {
                unvisited.push_back(new Node(i));    
            }
        }

       
        
        void sort_unvisited() {
            /* Sorts the unvisited nodes by distance, from shortest to largest */

            for (int i = 0; i < unvisited.size() - 1; i++) {
                for (int j = 0; j < unvisited.size() - 1; j++) {
                    if (unvisited.at(j)->dist > unvisited.at(j + 1)->dist) {
                        // swaps nodes if the current node is larger than the next
                        Node* temp = unvisited.at(j);
                        unvisited.at(j) = unvisited.at(j+1);
                        unvisited.at(j+1) = temp;
                    } 
                }
            }
        }

        bool is_visited(int n) {
            /* Checks if a node with an integer label of 'n' is 
             * located in the visited nodes vector */

            bool v = false;
            if (!visited.size()) return v;
            for (int i = 0; i < visited.size(); i++) {
                if (visited.at(i)->n == n) v = true;
            }
            return v;
        }

        void check_neighbors(Node* current_node, int cn) {
            /* Get the neighbors of the current node, and update
            their node distances according to the graph matrix */
            
            for (int i = 0; i < graph.matrix[cn].size(); i++) {
                int distance = graph.matrix[cn][i];
                // if node is not visited and there is a path between
                if (!is_visited(i) && distance != 0) {
                    for (int j = 0; j < unvisited.size(); j++) {
                        if (i == unvisited.at(j)->n) {
                            int sum = distance + current_node->dist;
                            // Only update if the new distance is smaller than what is was before
                            if (sum < unvisited.at(j)->dist) {
                                unvisited.at(j)->dist = sum;
                                unvisited.at(j)->prev = current_node;
                            }
                        }
                    }
                }
            }
        } 
        
        void print_path(Node* path) {
            /* Uses recursion to print the 'path' 
             * node from the tail to the head */
                
            Node* p = path;
            if (p->prev != nullptr) {
                print_path(p->prev);
                std::cout << "->";
            }
            std::cout << p->n;
        }

        void get_shortest_path(int start, int end) {
            /* Sweeps through all the nodes and their paths, starting from 'start'
             * until the shortest distance to 'end' is found.  */
            unvisited.at(start)->dist = 0;
            
            // Keep repeating as long as there are unvisited nodes
            while (unvisited.size()) {

                // Get the closest node
                sort_unvisited();
                Node* current_node = unvisited.at(0);
                int cn = current_node->n; 
                                
                // Set current node as visited
                unvisited.erase(unvisited.begin());
                visited.insert(visited.begin(), current_node);
                if (cn == end) break; // Exit function if final node
                check_neighbors(current_node, cn);
            }
            Node* path = visited.at(0);
            if (path->dist == MAX_DIST) {
                std::cout << "No paths found to " << start << " from " << end << "!\n\n";
            } else {
                std::cout << "\n\n-----Chosen-Path-Statistics-----\n\n";
                print_path(path);
                std::cout << "\n\nPath total distance: " << path->dist << "\n\n";
                std::cout << "--------------------------------\n";
            }
            if (path->dist > 0 && path->dist != MAX_DIST) {
                total_distance += path->dist;
                total_paths++;
            }
            reset_vectors();
        }

        void average_shortest_path() {
            /* Finds all shortest paths, then prints 
             * out the average shortest path size */
            float average;

            for (int i = 0; i < NODES; i++) {
                get_shortest_path(0, i);
            }

            if (total_paths > 0) {
                average = total_distance / total_paths;
                std::cout << "\nThe average path length is: " << average << ".\n\n";
            } else {
                std::cout << "Cannot divide by 0!\n"; 
            }
            
            total_distance = 0.0f;
            total_paths = 0;
        }

        
};

void input_nodes(int& start, int& end) {
    while (true) {
        std::cout << "Choose a start and end node (separate by space): " << std::endl;
        std::cin >> start >> end;
        break;
    }
}

int main() {
    srand(time(0));
    Dijkstra* finder = new Dijkstra;
    std::vector<Node*> paths;
    Node* shortest_path;
    int choice = 0;
    int start, end;

    std::cout << "\n\n--------------------------------\n";
    std::cout << "|     Dijkstra's Algorithm     |\n";
    std::cout << "--------------------------------\n\n\n";
    finder->graph.print();
        
    while (choice != 3) {
        std::cout << "\n\nWhat would you like to do?\n\n";
        std::cout << "0. Get the average shortest path\n";
        std::cout << "1. Get shortest path between two points\n";
        std::cout << "2. Reprint graph\n";
        std::cout << "3. Quit\n\n(0-3): ";
        std::cin >> choice;
        
        switch (choice) {
            case 0:
                finder->average_shortest_path();
                break;
            case 1:
                input_nodes(start, end);
                finder->get_shortest_path(start, end);
                break;
            case 2:
                finder->graph.print();
                break;
            case 3:
                std::cout << "\n\nGoodbye!\n\n";
                break;
            default:
                std::cout << "\n\nInvalid choice.\n\n";
        }
    }

    delete finder;
}
