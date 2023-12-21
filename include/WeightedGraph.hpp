#ifndef W_GRAPH_H
#define W_GRAPH_H

#include <vector>

class WeightedGraph {
    public:
        WeightedGraph(int num_vertices);
        ~WeightedGraph();

        void addEdge(int start, int end, int edge_weight);
        void removeEdge(int start, int end);
        void addVertex(int new_vertices);
        void printGraph();

        int getNumVertices() const;
        int getNumEdges() const;
        int getNoEdgeVal() const;
        int* getNeighbors(int vertex);
        int getEdgeWeight(int start, int end);

    private:
        int num_vertices;
        int num_edges;
        const int no_edge_val;
        int** adj_matrix;
};

#endif