#ifndef U_GRAPH_H
#define U_GRAPH_H

#include <vector>
#include "LinkedList.hpp"

class UnweightedGraph {
    public:
        UnweightedGraph(int num_vertices);
        ~UnweightedGraph();

        void addEdge(int start, int end);
        void removeEdge(int start, int end);
        void addVertex(int new_vertices);
        void printUnweightedGraph();

        int getNumVertices() const;
        int getNumEdges() const;

    private:
        int num_vertices;
        int num_edges;
        const int no_edge_val = std::numeric_limits<int>::min();
        // std::vector<std::vector<int>> adjacency_matrix;
        LinkedList** adj_list;
};

#endif