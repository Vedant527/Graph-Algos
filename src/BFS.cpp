#include "BFS.hpp"

#include <iostream>
#include <set>
#include <vector>
#include <queue>

BFS::BFS() {};
BFS::~BFS() {};
// Dist::Dist(int path_cost, bool path_exists) : path_cost(path_cost), path_exists(path_exists) {};

// int Dist::getPathCost() const {
//     return path_cost;
// }

// bool Dist::getPathExists() const {
//     return path_exists;
// }

// std::vector<int> Dist::getPath() {
//     return path;
// }

int BFS::runBfs(WeightedGraph graph, int start, int end) {
    std::queue<int> queue;
    std::set<int> visited;

    queue.push(start);

    while(!queue.empty()) {

        // std::queue<int> tempQueue = queue;

        // // Printing the contents of the queue
        // while (!tempQueue.empty()) {
        //     std::cout << tempQueue.front() << " ";  // Access the front element
        //     tempQueue.pop();  // Remove the front element
        // }
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
