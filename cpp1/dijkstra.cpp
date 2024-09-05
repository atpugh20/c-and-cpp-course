/* This program implements the famous pathfinding 
 * algorithm known as "Dijkstra's Algorithm." */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <array>

const int NODES = 9;

class Node {
    public:
        int d;
        int dist;
        Node* next;
        Node* prev;

        // Constructor
        Node(int d, int dist = 0, Node* next = nullptr, Node* prev = nullptr) :
            d(d), dist(dist), next(next), prev(prev) {}
};

class Path {
    /* A path is a linked list that connects
     * the origin to the destination */
    
    public:
        Node* head;
        Node* cursor;
        
        Path() : head(nullptr), cursor(nullptr) {}
        ~Path() {
            for (cursor = head; cursor != nullptr;) {
                cursor = head->next;
                delete head;
                head = cursor;
            }
            std::cout << "Destroyed Path.";
        }
        void prepend(int n, int dist_to_next = 0) {
            /* Adds a node to the beginning of the list */
            if (head == nullptr) {
                cursor = head = new Node(n, 0, head);
            } else {
                int tot_dist;
                if (head->next == nullptr) { 
                    tot_dist = dist_to_next;
                } else {
                    tot_dist = dist_to_next + head->dist;
                }
                head = new Node (n, tot_dist, head);
                head->next->prev = head;
            }

        }
        
        void print() {
            /* Prints the linked list an its entirety to the console */

            Node* h = head;
            while (h != nullptr) {
                std::cout << h->dist << ", ";
                h = h->next;
            }
            std::cout << "###" << std::endl;
        }

        void print_reverse() {
            Node* h = head;
            while (h->next != nullptr) {
                h = h->next;
            }

            while (h != nullptr) {
                std::cout << h->d << ", ";
                h = h->prev;
            }
            std::cout << "###\n";
        }
        
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
                    if (i == -1) std::cout << j + 1;
                    else if (j == -1) std::cout << i + 1;
                    else std::cout << matrix[i][j];
                    std::cout << " ";
                }
                std::cout << "\n";
            }
        }
};

class Dijkstra {
    /* This class handles the pathfinding portion of the program. 
     * It sorts through all nodes starting from the start-node until
     * it reaches the end-node.  */

    public:
        Graph graph;

        // An std::array with length NODES starting from 0. 
        // Being a non-negative number means that the 
        // coresponding node still needs to be checked
        std::array<int, NODES> unvisited;
        std::array<int, NODES> neighbors;
        // Constructor
        Dijkstra() {
            graph.generate_edges();
            graph.print();
            for (int i = 0; i < NODES; i++) {
                unvisited[i] = i;
            }
        }
        
        bool nodes_remaining() {
            /* Checks if there are any unvisited nodes. 
             * An index with -1 as its value indicates 
             * that that node has been visited */

            bool remaining = false;
            for (int i = 0; i < NODES; i++) {
                // -1 means it has been checked
                if (unvisited[i] != -1) {
                    remaining = true;
                    break;
                }
            }
            return remaining;
        }

        void get_shortest_path() {
        }

};


int main() {
    srand(time(0));
    
    //Path* path = new Path();
    //for (int i = 0; i < 10; i++) {
    //    path->prepend(i, 2);
    //}
    
    Dijkstra finder;
    finder.get_shortest_path();
    for (int i = 0; i < NODES; i++) {
        std::cout << "\n" << finder.unvisited[i] << " ";
    }
    //delete path;
}

