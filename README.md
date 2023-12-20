# Graph Algorithms

This repository contains (work in progress) implementations of basic graph algorithms in C++. I made it to test the algorithms I've learnt in my Graduate Algorithms course.
In the future it will include support for: DFS, Ford Fulkerson, Min Cut, and more. Currently, it includes:

## Unweighted Graphs

- Representation of unweighted graphs using an adjacency list.
- Breadth-First Search (BFS) algorithm for unweighted graphs.
- Depth-First Search (DFS) algorithm for unweighted graphs.


## Weighted Graphs

- Representation of weighted graphs using an adjacency matrix.
- Breadth-First Search (BFS) algorithm for weighted graphs.
- Depth-First Search (DFS) algorithm for weighted graphs.

## How to Use

1. Clone the repository:

   ```bash
   git clone https://github.com/vedant527/graph-algos.git
   
2. Run the following commands to build files
 
   ```bash
   mkdir build && cmake ..

3. Create and run the executable
 
   ```bash
   make && ./out
