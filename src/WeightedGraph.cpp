#include "WeightedGraph.hpp"
#include <iostream>
#include <vector>

// original no_edge_val = std::numeric_limits<int>::min()
WeightedGraph::WeightedGraph(int num_vertices) : num_vertices(num_vertices), num_edges(0), no_edge_val(0) {
    adj_matrix = new int*[num_vertices];

    for (int i = 0; i < num_vertices; i++) {
        adj_matrix[i] = new int[num_vertices];
        for (int j = 0; j < num_vertices; j++) {
            adj_matrix[i][j] = no_edge_val;
        }
    }
}

WeightedGraph::~WeightedGraph() {}

void WeightedGraph::addEdge(int start, int end, int edge_weight) {
    // blocks self loops
    if (start == end) {
        return;
    }
    
    if (start >= num_vertices || end >= num_vertices) {
        throw std::invalid_argument("Invalid edge!");
    } else {
        adj_matrix[start][end] = edge_weight;
        num_edges++;
    }
}

void WeightedGraph::removeEdge(int start, int end) {
    if (start >= num_vertices || end >= num_vertices) {
        printf("Edge from %d to %d is invalid!\n", start, end);
    } else if (adj_matrix[start][end] == no_edge_val) {
        printf("No edge exists from %d to %d", start, end);
    } else {
        adj_matrix[start][end] = no_edge_val;
        num_edges--;
    }
}

void WeightedGraph::addVertex(int new_vertices) {
    int old_num_vertices = num_vertices;
    num_vertices += new_vertices;

    int** old_adj_matrix = adj_matrix;
    adj_matrix = new int*[num_vertices];

    for (int i = 0; i < old_num_vertices; i++) {
        adj_matrix[i] = new int[num_vertices];
        std::fill(adj_matrix[i], adj_matrix[i] + num_vertices, no_edge_val);
        for (int j = 0; j < old_num_vertices; j++) {
            adj_matrix[i][j] = old_adj_matrix[i][j];
        }
        delete[] old_adj_matrix[i];
    }
    delete[] old_adj_matrix;
}

void WeightedGraph::printGraph() {
    std::cout << "   ";
    for (int j = 0; j < num_vertices; j++) {
        std::cout << "  " << j;
    }
    std::cout << std::endl;

    // Print the array with row indices
    for (int i = 0; i < num_vertices; i++) {
        std::cout << i << " |";
        for (int j = 0; j < num_vertices; j++) {
            if (adj_matrix[i][j] != no_edge_val) {
                std::cout << "  " << adj_matrix[i][j];
            } else 
                std::cout << "  N";
        }
        std::cout << std::endl;
    }
}

int WeightedGraph::getNumVertices() const {
    return num_vertices;
}

int WeightedGraph::getNumEdges() const {
    return num_edges;
}

int WeightedGraph::getNoEdgeVal() const {
    return no_edge_val;
}

int* WeightedGraph::getNeighbors(int vertex) {
    return adj_matrix[vertex];
}

int WeightedGraph::getEdgeWeight(int start, int end) {
    return adj_matrix[start][end];
}