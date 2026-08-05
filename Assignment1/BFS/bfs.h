#ifndef BFS_H
#define BFS_H

#include <vector>
struct CSRGraph {
    int numVertices;
    int numEdges;
    std::vector<int> rowOffset;   
    std::vector<int> colIndex;    
};
void runBFS(const CSRGraph &graph, int sourceVertex,
            std::vector<int> &traversalOrder,
            std::vector<int> &distance);

#endif