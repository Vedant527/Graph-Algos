#ifndef GRAPH_AGENT_H
#define GRAPH_AGENT_H

#include <vector>
#include "WeightedGraph.hpp"
#include "UnweightedGraph.hpp"

class GraphAgent {
    public:
        GraphAgent();
        ~GraphAgent();

        static int runBfs(WeightedGraph graph, int start, int end, int parent[]);
        static int runBfs(UnweightedGraph graph, int start, int end, int parent[]);
        static int runDfs(WeightedGraph graph, int start, int end, int parent[]);
        static int runDfs(UnweightedGraph graph, int start, int end, int parent[]);
};

#endif