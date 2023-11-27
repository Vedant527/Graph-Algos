#include "BFS.hpp"

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
