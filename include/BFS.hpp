#ifndef BFS_H
#define BFS_H

#include <vector>
#include "WeightedGraph.hpp"
#include "UnweightedGraph.hpp"

class BFS {
    public:
        BFS();
        ~BFS();

        int runBfs(WeightedGraph graph, int start, int end);
        int runBfs(UnweightedGraph graph, int start, int end);
};

#endif