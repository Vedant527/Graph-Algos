#include <iostream>
#include <chrono>

#include "GraphAgent.hpp"
#include "UnweightedGraph.hpp"

int main() {
    int N = 10;
    int NUM_ITS = 1000;

    WeightedGraph g = WeightedGraph(N);
    GraphAgent agent;

    float ff_time = 0;
    float ek_time = 0;

    for (int i = 0; i < NUM_ITS; i++) {
        unsigned seed = time(0);
        srand(seed);
        int random_edge_count = rand() % (N * N);
        for (int i = 0; i < random_edge_count; i++) {
            int v1 = rand() % N;
            int v2 = rand() % N;
            g.addEdge(v1, v2, rand() % 10);
        }

        int parents1[g.getNumVertices()];
        int parents2[g.getNumVertices()];
        int v1 = rand() % g.getNumVertices();
        int v2 = rand() % g.getNumVertices();

        auto start = std::chrono::high_resolution_clock::now();
        int f1 = agent.fordFulkerson(g, v1, v2);
        auto end = std::chrono::high_resolution_clock::now();
        ff_time += std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        start = std::chrono::high_resolution_clock::now();
        int f2 = agent.edmondsKarp(g, v1, v2);
        end = std::chrono::high_resolution_clock::now();
        ek_time += std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        std::cout << i << std::endl;
    }

    std::cout << "Ford Fulkerson took: " << ff_time << "us and Edmonds Karp took " << ek_time << "us" << std::endl;
}