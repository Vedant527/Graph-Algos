#include "BFS.hpp"
#include "Graph.hpp"

#include <iostream>
#include <set>
#include <vector>

BFS::BFS() {};
BFS::~BFS() {};
Dist::Dist(int path_cost, bool path_exists) : path_cost(path_cost), path_exists(path_exists) {};

int Dist::getPathCost() const {
    return path_cost;
}

bool Dist::getPathExists() const {
    return path_exists;
}

std::vector<int> Dist::getPath() {
    return path;
}

// Dist* BFS::runBfs(Graph* graph, int starting_node) {
//     if (starting_node >= graph->getNumVertices()) {
//         throw std::invalid_argument("Starting node is not in graph!");
//     }

//     std::set<int> explored;
//     std::vector<int> queue;
//     queue.push_back(starting_node);

//     while (queue.size() > 0) {
//         int node = queue.p
//     }

//     return 0;
// }

int main() {
    return 0;
}
