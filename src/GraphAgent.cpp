#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <stack>

#include "GraphAgent.hpp"

GraphAgent::GraphAgent() {};
GraphAgent::~GraphAgent() {};

bool GraphAgent::runBfs(WeightedGraph graph, int start, int end, int parent[]) {
    std::queue<int> queue;
    std::set<int> visited;

    queue.push(start);
    parent[start] = -1;

    while(!queue.empty()) {
        int curr = queue.front();
        visited.insert(curr);
        queue.pop();

        if (curr == end) {
            return true;
        }
        int* neighbors = graph.getNeighbors(curr);
        for (int n = 0; n < graph.getNumVertices(); n++) {
            if (visited.find(n) == visited.end() && neighbors[n] != graph.getNoEdgeVal()) {
                queue.push(n);
                parent[n] = curr;
            }
        }
    }

    return false;
}

bool GraphAgent::runBfs(UnweightedGraph graph, int start, int end, int parent[]) {
    std::queue<int> queue;
    std::set<int> visited;

    queue.push(start);
    for (int i = 0; i < graph.getNumVertices(); i++) {
        parent[i] = -1;
    }

    while(!queue.empty()) {
        int curr = queue.front();
        visited.insert(curr);
        queue.pop();

        if (curr == end) {
            return true;
        }
        LinkedList* neighbors = graph.getNeighbors(curr);
        for (int n = 0; n < graph.getNumVertices(); n++) {
            if (visited.find(n) == visited.end() && neighbors->find(n) > 0) {
                queue.push(n);
                parent[n] = curr;
            }
        }
    }

    return false;
}

bool GraphAgent::runDfs(WeightedGraph graph, int start, int end, int parent[]) {
    std::stack<int> queue;
    std::set<int> visited;

    queue.push(start);
    for (int i = 0; i < graph.getNumVertices(); i++) {
        parent[i] = -1;
    }

    while (!queue.empty()) {
        int curr = queue.top();
        queue.pop();
        visited.insert(curr);

        if (curr == end) {
            return true;
        }
        int* neighbors = graph.getNeighbors(curr);
        for (int n = 0; n < graph.getNumVertices(); n++) {
            if (visited.find(n) == visited.end() && neighbors[n] != graph.getNoEdgeVal()) {
                queue.push(n);
                parent[n] = curr;
            }
        }
    }

    return false;
}

bool GraphAgent::runDfs(UnweightedGraph graph, int start, int end, int parent[]) {
    std::stack<int> queue;
    std::set<int> visited;

    queue.push(start);
    for (int i = 0; i < graph.getNumVertices(); i++) {
        parent[i] = -1;
    }

    while (!queue.empty()) {
        int curr = queue.top();
        queue.pop();
        visited.insert(curr);

        if (curr == end) {
            return true;
        }
        LinkedList* neighbors = graph.getNeighbors(curr);
        for (int n = 0; n < graph.getNumVertices(); n++) {
            if (visited.find(n) == visited.end() && neighbors->find(n) > 0) {
                queue.push(n);
                parent[n] = curr;
            }
        }
    }

    return false;
}

int GraphAgent::fordFulkerson(WeightedGraph graph, int start, int end) {
    int N = graph.getNumVertices();
    WeightedGraph residual(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            residual.addEdge(i, j, graph.getEdgeWeight(i, j));
        }
    }

    int max_flow = 0;
    int parent[graph.getNumVertices()];

    int u, v;
    while (runDfs(residual, start, end, parent)) {
        int flow = INT_MAX;
        for (v = end; v != start; v = parent[v]) {
            u = parent[v];
            flow = std::min(flow, residual.getEdgeWeight(u, v));
        }

        for (v = end; v != start; v = parent[v]) {
            u = parent[v];
            residual.addEdge(u, v, residual.getEdgeWeight(u, v) - flow);
            residual.addEdge(v, u, residual.getEdgeWeight(u, v) + flow);
        }

        max_flow += flow;
    }

    return max_flow;
}

int GraphAgent::edmondsKarp(WeightedGraph graph, int start, int end) {
    int N = graph.getNumVertices();
    WeightedGraph residual(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            residual.addEdge(i, j, graph.getEdgeWeight(i, j));
        }
    }

    int max_flow = 0;
    int parent[graph.getNumVertices()];

    int u, v;
    while (runBfs(residual, start, end, parent)) {
        int flow = INT_MAX;
        for (v = end; v != start; v = parent[v]) {
            u = parent[v];
            flow = std::min(flow, residual.getEdgeWeight(u, v));
        }

        for (v = end; v != start; v = parent[v]) {
            u = parent[v];
            residual.addEdge(u, v, residual.getEdgeWeight(u, v) - flow);
            residual.addEdge(v, u, residual.getEdgeWeight(u, v) + flow);
        }

        max_flow += flow;
    }

    return max_flow;
}

int GraphAgent::dijkstras(WeightedGraph graph, int start, int end, int parent[]) {
    int N = graph.getNumVertices();
    std::set<int> visited;
    int distance[N];
    for (int i = 0; i < N; i++) {
        if (i != start) {
            distance[i] = INT_MAX;
        } else {
            distance[i] = 0;
        }
    }

    return -1;
}