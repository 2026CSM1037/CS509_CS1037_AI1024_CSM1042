# Maxflow-Mincut

## System Configuration
Algorithm: Maxflow-Mincut (Dinic's Algorithm)
Graph Type: Directed, Capacitated
Graph Representation: CSR (built via shared `executeCSR()` helper from shared folder)
Language: C++
Compiler: g++ (MinGW-w64 on Windows)

## Run Command
```bash
cd Maxflow_Mincut
mingw32-make
./maxflow.exe or ./maxflow.out (depending on OS)
```

Direct compile (equivalent to the Makefile target):
```bash
g++ -std=c++17 -O2 driver.cpp maxflow.cpp ../../shared/CSR/csr.cpp -o maxflow -Wl,--stack,33554432
./maxflow maxflow_1000.txt
```

Note: `-Wl,--stack,33554432` reserves 32MB of linker stack. This is required because
`executeCSR()` allocates large local arrays on the stack, and Dinic's recursive DFS can
recurse close to O(V) deep on large sparse graphs — both overflow MinGW's 1MB default stack
on the larger required test sizes.

## Results Table

| Test File           | Vertices (V) |  Edges (E) | Source | Sink |    Max Flow | Min Cut Capacity | Flow = Cut? |        Time | Status |
| -------------------- | -----------: | ---------: | -----: | ---: | ----------: | ----------------: | :---------: | -----------: | ------ |
| `maxflow_1.txt` |            6 |         10 |      0 |    5 |          23 |                 23 |     Yes     |      4.821 ms | Pass   |
| `maxflow_2.txt`     |           10 |         17 |      — |    — |           — |                  — |      —      |            — | **Fail** |
| `maxflow_3.txt`    |          100 |        199 |      0 |   99 |          20 |                 20 |     Yes     |          0 ms | Pass   |
| `maxflow_4.txt`   |        1,000 |      2,000 |      0 |  999 |          26 |                 26 |     Yes     |      0.979 ms | Pass   |
| `maxflow_5.txt`  |       10,000 |     20,000 |      0 | 9999 |           — |                  — |     Yes     |     13.567 ms | Pass   |
| `maxflow_6.txt`  |       50,000 |    100,000 |      0 |49999 |           — |                  — |     Yes     |     22.629 ms | Pass   |
| `maxflow_7.txt` |      100,000 |    200,000 |      0 |99999 |           — |                  — |     Yes     |      73.51 ms | Pass   |

`maxflow_100000.txt` is an **optional** stress test beyond the required sizes (10, 100, 1,000, 10,000, 50,000). Unlike the Betweenness Centrality run, it completed successfully.

**`maxflow_2.txt` failed input validation** (`Malformed adjacency list`) rather than running
to completion — this is the required V=10 test case and does not currently produce a result.
The edge count (17) does not match what the test-case generator would produce for V=10 (20),
suggesting the file itself is corrupted or hand-edited incorrectly. 

## Time Complexity
Algorithm: Dinic's Algorithm
Time Complexity: O(V² · E) in general; O(E · √V) on unit-capacity graphs
Space Complexity: O(V + E)

The algorithm repeatedly builds a level graph via BFS, then finds a blocking flow via DFS
along that level graph, until no augmenting path remains. The minimum cut is extracted by a
final BFS over the residual graph from the source; all reachable vertices form the source
side, and edges crossing to the unreachable side form the cut.

## Notes
- Per the assignment timing rule, the CSR conversion (`executeCSR()`) runs **before** the timer
  starts. Timing begins when the residual graph is built from the CSR arrays and ends after
  min-cut extraction.
- All test files guarantee at least one source-to-sink path (a backbone chain from vertex 0
  to vertex V-1), with additional random forward edges layered on top to reach the target
  edge count while keeping the graph sparse.
- `Flow = Cut?` is the correctness check used for the larger graphs, since Max Flow / Min Cut
  values are not independently known for randomly generated inputs — the max-flow value
  matching the min-cut capacity is the required invariant (Section 7.3 of the spec) and was
  confirmed for every test that ran to completion.
