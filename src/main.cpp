#include <iostream>
#include "UnweightedGraph.hpp"
#include "GraphAgent.hpp"

int main() {
    WeightedGraph g = WeightedGraph(20);
    unsigned seed = time(0);
    srand(seed);

    int random_edge_count = rand() % 100;
    for (int i = 0; i < random_edge_count; i++) {
        int v1 = rand() % 20;
        int v2 = rand() % 20;
        g.addEdge(v1, v2, rand() % 10);
    }
    g.printGraph();
    GraphAgent b;
    int parents1[g.getNumVertices()];
    int parents2[g.getNumVertices()];

    int start = 0;
    int end = 2;
    int x = b.runBfs(g, start, end, parents1);
    int y = b.runDfs(g, start, end, parents2);
    int flow = b.fordFulkerson(g, start, end);
    std::cout << "MAX FLOW: " << flow << std::endl;

    if (x == 1) { 
        std::cout << "BFS found path! ";
        int curr = end;
        std::cout << "path: ";
        while (curr != -1) {
            std::cout << curr << " ";
            curr = parents1[curr];
        }
        std::cout << std::endl;
    } else {
        std::cout << "BFS path not found!" << std::endl;
    }

    if (y == 1) { 
        std::cout << "DFS found path! ";
        int curr = end;
        std::cout << "path: ";
        while (curr != -1) {
            std::cout << curr << " ";
            curr = parents2[curr];
        }
        std::cout << std::endl;
    } else {
        std::cout << "DFS path not found!" << std::endl;
    }
}