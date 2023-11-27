#include "UnweightedGraph.hpp"

int main() {
    UnweightedGraph g = UnweightedGraph(10);
    unsigned seed = time(0);
    srand(seed);

    int random_edge_count = rand() % 10;
    for (int i = 0; i < random_edge_count; i++) {
        int v1 = rand() % 10;
        int v2 = rand() % 10;
        g.addEdge(v1, v2);
    }
    g.printUnweightedGraph();
}