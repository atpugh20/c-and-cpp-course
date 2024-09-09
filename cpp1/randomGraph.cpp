/* This program uses a randomly generated probability to generate an edge 
 * matrix. If a 1 is printed, then there is a path. If a 0 is printed, then
 * there is not a path. */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

inline double prob() { return (static_cast<double>(std::rand())/RAND_MAX); }

void fill_graph(std::vector<std::vector<int>>& graph, int size) {
    /* Fills a matrix with edges. There is a 0.2 probability
     * that an edge, or a 1, will be generated. Otherwise, a
     * 0 will be filled into the index */

    for (int i = 0; i < size; i++) {
        std::vector<int> v;
        graph.push_back(v);
        for (int j = 0; j < size; j++) {
            if (prob() < 0.2) graph.at(i).push_back(1);
            else graph.at(i).push_back(0);
        }
    }        
}

void print_graph(std::vector<std::vector<int>>& graph) {
    /* Prints the graph vector to the console as a matrix */
    std::cout << '\n';
    for (std::vector<int> row : graph) {
        for (int cell : row) {
            std::cout << cell << " ";
        }
        std::cout << '\n';
    }   
}

int main() {
    std::srand(time(0));
    std::vector<std::vector<int>> graph;
    const int edge_num = 20;
    
    fill_graph(graph, edge_num);
    print_graph(graph);
    
    return 0;
}
