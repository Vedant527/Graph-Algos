#ifndef BFS_H
#define BFS_H

#include <vector>
#include "WeightedGraph.hpp"

// class Dist {
//     public:
//         Dist(int path_cost, bool path_exists);
//         ~Dist();

//         int getPathCost() const;
//         bool getPathExists() const;
//         std::vector<int> getPath();
    
//     private:
//         int path_cost;
//         bool path_exists;
//         std::vector<int> path;
// };

class BFS {
    public:
        BFS();
        ~BFS();

        static int runBfs(WeightedGraph graph, int start, int end);
};

#endif