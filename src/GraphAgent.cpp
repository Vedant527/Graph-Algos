#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <stack>

#include "GraphAgent.hpp"

GraphAgent::GraphAgent() {};
GraphAgent::~GraphAgent() {};

int GraphAgent::runBfs(WeightedGraph graph, int start, int end) {
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

int GraphAgent::runBfs(UnweightedGraph graph, int start, int end) {
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
        LinkedList* neighbors = graph.getNeighbors(curr);
        for (int n = 0; n < graph.getNumVertices(); n++) {
            if (visited.find(n) == visited.end() && neighbors->find(n) > 0) {
                queue.push(n);
            }
        }
    }

    return 0;
}

int GraphAgent::runDfs(WeightedGraph graph, int start, int end) {
    std::stack<int> queue;
    std::set<int> visited;

    queue.push(start);

    while (!queue.empty()) {
        int curr = queue.top();
        queue.pop();
        visited.insert(curr);

        if (curr == end) {
            return 1;
        }
        int* neighbors = graph.getNeighbors(curr);
        for (int n = 0; n < graph.getNumVertices(); n++) {
            if (visited.find(curr) == visited.end() && neighbors[n] != graph.getNoEdgeVal()) {
                queue.push(n);
            }
        }
    }

    return 0;
}

int GraphAgent::runDfs(UnweightedGraph graph, int start, int end) {
    std::stack<int> queue;
    std::set<int> visited;

    queue.push(start);

    while (!queue.empty()) {
        int curr = queue.top();
        queue.pop();
        visited.insert(curr);

        if (curr == end) {
            return 1;
        }
        LinkedList* neighbors = graph.getNeighbors(curr);
        for (int n = 0; n < graph.getNumVertices(); n++) {
            if (visited.find(n) == visited.end() && neighbors->find(n) > 0) {
                queue.push(n);
            }
        }
    }

    return 0;
}