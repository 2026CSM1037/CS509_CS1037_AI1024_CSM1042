#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include "bfs.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Usage:"<< argv[0] << "<input_file>\n";
        return 1;
    }

    std::ifstream inFile(argv[1]);
    if (!inFile.is_open()) {
        std::cerr << "Error: could not open input file "<< argv[1] << "\n";
        return 1;
    }
    int V, E;
    inFile >> V >> E;
    std::vector<std::vector<int>> adjList(V);

    for (int i = 0; i < V; i++) {
        int u, degree;
        inFile >> u >> degree;
        for (int j = 0; j < degree; j++) {
            int neighbor;
            inFile >> neighbor;
            adjList[u].push_back(neighbor);
        }
    }
    std::string sourceLabel;
    int sourceVertex;
    inFile >> sourceLabel >> sourceVertex;  
    inFile.close();
    CSRGraph graph;
    graph.numVertices = V;
    graph.numEdges = E;
    graph.rowOffset.resize(V + 1, 0);

    for (int u = 0; u < V; u++) {
        graph.rowOffset[u + 1] = graph.rowOffset[u] + (int)adjList[u].size();
    }
    graph.colIndex.resize(graph.rowOffset[V]);
    for (int u = 0; u < V; u++) {
        int pos = graph.rowOffset[u];
        for (size_t k = 0; k < adjList[u].size(); k++) {
            graph.colIndex[pos + k] = adjList[u][k];
        }
    }
    std::vector<int> traversalOrder;
    std::vector<int> distance;

    auto startTime = std::chrono::high_resolution_clock::now();
    runBFS(graph, sourceVertex, traversalOrder, distance);
    auto endTime = std::chrono::high_resolution_clock::now();
    double elapsedMs = std::chrono::duration<double, std::milli>(endTime - startTime).count();
    std::cout << "Algorithm: BFS\n";
    std::cout << "Source: " << sourceVertex << "\n";

    std::cout << "Traversal: ";
    for (size_t i = 0; i < traversalOrder.size(); i++) {
        std::cout << traversalOrder[i];
        if (i != traversalOrder.size() - 1) std::cout << " ";
    }
    std::cout << "\n";

    std::cout << "Distances:\n";
    for (int i = 0; i < V; i++) {
        std::cout << i << " ";
        if (distance[i] == -1) std::cout << "INF\n";
        else std::cout << distance[i] << "\n";
    }

    std::cout << "Execution time: "<< elapsedMs << " ms\n";

    return 0;
}