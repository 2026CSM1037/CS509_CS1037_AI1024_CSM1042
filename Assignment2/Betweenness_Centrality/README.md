# Betweenness Centrality

System Configuration
Algorithm: Betweenness Centrality
Graph Type: Undirected
Graph Representation: CSR
Language: C++
Compiler: g++

## Run Command

```bash
cd betweenness_centrality
g++ -std=c++17 -O2 driver/driver.cpp src/betweenness_centrality.cpp -o betweenness_centrality
./betweenness_centrality

| Algorithm              | Test File           | Vertices |     Edges | Expected Output       | Actual Output         |        Time | Status |
| ---------------------- | ------------------- | -------: | --------: | --------------------- | --------------------- | ----------: | ------ |
| Betweenness Centrality | `graph_test_01.txt` |        5 |         4 | Centrality per vertex | Centrality per vertex |        0 ms | Pass   |
| Betweenness Centrality | `graph_test_02.txt` |       10 |        12 | Centrality per vertex | Centrality per vertex |        0 ms | Pass   |
| Betweenness Centrality | `graph_test_03.txt` |      100 |       612 | Centrality per vertex | Centrality per vertex |    4.988 ms | Pass   |
| Betweenness Centrality | `graph_test_04.txt` |    1,000 |    11,438 | Centrality per vertex | Centrality per vertex |  469.248 ms | Pass   |
| Betweenness Centrality | `graph_test_05.txt` |   10,000 |   160,108 | Centrality per vertex | Centrality per vertex | 50,456.1 ms | Pass   |
| Betweenness Centrality | `graph_test_06.txt` |  100,000 | 1,604,357 | Centrality per vertex | System Freeze         |           - | Fail   |

```
Time Complexity
Algorithm: Brandes' Algorithm
Time Complexity: O(VE)
Space Complexity: O(V + E)

The algorithm performs a BFS from every vertex and computes the dependency of each vertex to obtain its Betweenness Centrality.

The 100,000-vertex test was an additional stress test. The system froze during execution due to the high computational cost.
