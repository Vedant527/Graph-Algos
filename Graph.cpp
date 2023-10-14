#include "Graph.hpp"
#include <iostream>
#include <random>

Graph::Graph(int num_vertices) : num_vertices(num_vertices), num_edges(0) {
    adjacency_matrix = new int*[num_vertices];

    for (int i = 0; i < num_vertices; i++) {
        adjacency_matrix[i] = new int[num_vertices];
        for (int j = 0; j < num_vertices; j++) {
            adjacency_matrix[i][j] = no_edge_val;
        }
    }
}

Graph::~Graph() {

}

void Graph::addEdge(int start, int end, int edge_weight) {
    if (start >= num_vertices || end >= num_vertices) {
        printf("Edge from %d to %d is invalid!", start, end);
    } else {
        adjacency_matrix[start][end] = edge_weight;
        num_edges++;
    }
}

void Graph::removeEdge(int start, int end) {
    if (start >= num_vertices || end >= num_vertices) {
        printf("Edge from %d to %d is invalid!\n", start, end);
    } else if (adjacency_matrix[start][end] == no_edge_val) {
        printf("No edge exists from %d to %d\n", start, end);
    } else {
        adjacency_matrix[start][end] = no_edge_val;
        num_edges--;
    }
}

void Graph::addVertex(int new_vertices) {
    int old_num_vertices = num_vertices;
    num_vertices += new_vertices;

    int** old_adjacency_matrix = adjacency_matrix;
    adjacency_matrix = new int*[num_vertices];

    for (int i = 0; i < old_num_vertices; i++) {
        adjacency_matrix[i] = new int[num_vertices];
        std::fill(adjacency_matrix[i], adjacency_matrix[i] + num_vertices, no_edge_val);
        for (int j = 0; j < old_num_vertices; j++) {
            adjacency_matrix[i][j] = old_adjacency_matrix[i][j];
        }
        delete[] old_adjacency_matrix[i];
    }
    delete[] old_adjacency_matrix;
}

void Graph::printGraph() {
    std::cout << "   ";
    for (int j = 0; j < num_vertices; j++) {
        std::cout << " " << j;
    }
    std::cout << std::endl;

    // Print the array with row indices
    for (int i = 0; i < num_vertices; i++) {
        std::cout << i << " |";
        for (int j = 0; j < num_vertices; j++) {
            if (adjacency_matrix[i][j] != no_edge_val) {
                std::cout << " " << adjacency_matrix[i][j];
            } else 
                std::cout << " N";
        }
        std::cout << std::endl;
    }
}

int Graph::getNumVertices() const {
    return num_vertices;
}

int Graph::getNumEdges() const {
    return num_edges;
}

int main() {
    Graph g = Graph(10);
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> vert_dist(0, g.getNumVertices() - 1);
    std::uniform_int_distribution<int> edge_dist(0, g.getNumVertices() * g.getNumVertices());

    int random_edge_count = edge_dist(rng);
    for (int i = 0; i < random_edge_count; i++) {
        int v1 = vert_dist(rng);
        int v2 = vert_dist(rng);
        g.addEdge(v1, v2, vert_dist(rng));
    }
    g.printGraph();
}