#include "bfs.h"
#include <queue>
void runBFS(const CSRGraph &graph, int sourceVertex,
            std::vector<int> &traversalOrder,
            std::vector<int> &distance) {

    int n = graph.numVertices;
        distance.assign(n, -1);          
        traversalOrder.clear();
    std::vector<bool> visited(n, false);
    std::queue<int> q;

    visited[sourceVertex] = true;
    distance[sourceVertex] = 0;
    q.push(sourceVertex);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        traversalOrder.push_back(u);

        int start = graph.rowOffset[u];
        int end   = graph.rowOffset[u + 1];

        for (int i = start; i < end; i++) {
             int v = graph.colIndex[i];
            if (!visited[v]) {
                visited[v] = true;
                distance[v] = distance[u] + 1;
                q.push(v);
            }
        }
    }
}