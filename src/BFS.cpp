#include "BFS.hpp"

#include <iostream>
#include <set>
#include <vector>
#include <queue>

BFS::BFS() {};
BFS::~BFS() {};

int BFS::runBfs(WeightedGraph graph, int start, int end) {
    std::queue<int> queue;
    std::set<int> visited;

    queue.push(start);

    while(!queue.empty()) {
        int curr = queue.front();
        visited.insert(curr);
        queue.pop();

        if (curr == end) {
            return 1;
        }
        int* neighbors = graph.getNeighbors(curr);
        for (int n = 0; n < graph.getNumVertices(); n++) {
            if (visited.find(n) == visited.end() && neighbors[n] != graph.getNoEdgeVal()) {
                queue.push(n);
            }
        }
    }

    return 0;
}
