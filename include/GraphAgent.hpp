#ifndef GRAPH_AGENT_H
#define GRAPH_AGENT_H

#include <vector>
#include "WeightedGraph.hpp"
#include "UnweightedGraph.hpp"

class GraphAgent {
    public:
        GraphAgent();
        ~GraphAgent();

        static bool runBfs(WeightedGraph graph, int start, int end, int parent[]);
        static bool runBfs(UnweightedGraph graph, int start, int end, int parent[]);
        static bool runDfs(WeightedGraph graph, int start, int end, int parent[]);
        static bool runDfs(UnweightedGraph graph, int start, int end, int parent[]);
        static int fordFulkerson(WeightedGraph graph, int start, int end);
        static int dijkstras(WeightedGraph graph, int start, int end, int parent[]);
};

#endif