#include <iostream>
#include "UnweightedGraph.hpp"
#include "GraphAgent.hpp"

int main() {
    UnweightedGraph g = UnweightedGraph(10);
    unsigned seed = time(0);
    srand(seed);

    int random_edge_count = rand() % 100;
    for (int i = 0; i < random_edge_count; i++) {
        int v1 = rand() % 10;
        int v2 = rand() % 10;
        g.addEdge(v1, v2);
    }
    g.printGraph();
    GraphAgent b;
    int x = b.runBfs(g, 0, 3);
    int y = b.runDfs(g, 0, 3);
    if (x == 1) { 
        std::cout << "BFS found path!" << std::endl;
    } else {
        std::cout << "BFS path not found!" << std::endl;
    }

    if (y == 1) { 
        std::cout << "DFS found path!" << std::endl;
    } else {
        std::cout << "DFS path not found!" << std::endl;
    }
}