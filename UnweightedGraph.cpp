#include "UnweightedGraph.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

UnweightedGraph::UnweightedGraph(int num_vertices) : num_vertices(num_vertices), num_edges(0) {
    adj_list = new LinkedList*[num_vertices];

    for (int i = 0; i < num_vertices; i++) {
        adj_list[i] = new LinkedList();
    }
}

UnweightedGraph::~UnweightedGraph() {}

void UnweightedGraph::addEdge(int start, int end) {
    if (start >= num_vertices || end >= num_vertices) {
        throw std::invalid_argument("Invalid edge!");
    } else {
        adj_list[start]->addToBack(end);
        num_edges++;
    }
}

void UnweightedGraph::removeEdge(int start, int end) {
    if (start >= num_vertices || end >= num_vertices) {
        printf("Edge from %d to %d is invalid!\n", start, end);
    } else {
        adj_list[start]->remove(end);
        num_edges--;
    }
}

void UnweightedGraph::addVertex(int new_vertices) {
    int old_num_vertices = num_vertices;
    num_vertices += new_vertices;

    LinkedList** old_adj_list = adj_list;
    adj_list = new LinkedList*[num_vertices];

    for (int i = 0; i < old_num_vertices; i++) {
        adj_list[i] = old_adj_list[i];
        delete old_adj_list[i];
    }

    for (int j = old_num_vertices; j < num_vertices; j++) {
        adj_list[j] = new LinkedList();
    }

    delete[] old_adj_list;
}

void UnweightedGraph::printUnweightedGraph() {
    // Print the array with row indices
    for (int i = 0; i < num_vertices; i++) {
        std::cout << i << ": ";
        adj_list[i]->printLinkedList();
    }
}

int UnweightedGraph::getNumVertices() const {
    return num_vertices;
}

int UnweightedGraph::getNumEdges() const {
    return num_edges;
}

int main() {
    UnweightedGraph g = UnweightedGraph(10);
    unsigned seed = time(0);
    srand(seed);

    int random_edge_count = rand() % 10;
    for (int i = 0; i < random_edge_count; i++) {
        int v1 = rand() % 10;
        int v2 = rand() % 10;
        g.addEdge(v1, v2);
    }
    g.printUnweightedGraph();
}