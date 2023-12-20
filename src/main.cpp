#include "UnweightedGraph.hpp"
#include "BFS.hpp"
#include <iostream>

int main() {
    WeightedGraph g = WeightedGraph(10);
    unsigned seed = time(0);
    srand(seed);

    int random_edge_count = rand() % 100;
    for (int i = 0; i < random_edge_count; i++) {
        int v1 = rand() % 10;
        int v2 = rand() % 10;
        g.addEdge(v1, v2, rand() % 10);
    }
    g.printGraph();
    BFS b;
    int x = b.runBfs(g, 0, 3);
    std::cout << x;
    
}