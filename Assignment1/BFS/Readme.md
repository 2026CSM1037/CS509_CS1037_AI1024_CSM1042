# CS509 - Assignment 1: BFS (Breadth-First Search)
**Name:** Anwesha Roy Oishi

**Entry No:** 2026CSM1042

**Task:** Buddy Task – BFS

## Files
- `bfs.h`, `bfs.cpp` – CSR graph + BFS implementation
- `driver.cpp` – reads input, builds CSR graph, times BFS, prints output
- `Makefile` – build script
- `graph_test_01.txt`, `graph_test_02.txt` – inputs
- `graph_test_01_output.txt`, `graph_test_02_output.txt` – outputs

## Project Structure
```
CS509_CS1037_AI1024_CSM1042/
└── Assignment1/
    └── BFS/
        ├── bfs.h
        ├── bfs.cpp
        ├── driver.cpp
        ├── Makefile
        ├── bfs_exec.exe          (generated after build)
        ├── graph_test_01.txt
        ├── graph_test_01_output.txt
        ├── graph_test_02.txt
        └── graph_test_02_output.txt
```

## Build & Run
Open a terminal inside the `BFS` folder, then:
```
make
./bfs_exec graph_test_01.txt
./bfs_exec graph_test_02.txt
```
On Windows, if `make` isn't available, build directly with:
```
g++ -O2 -std=c++17 driver.cpp bfs.cpp -o bfs_exec.exe
bfs_exec.exe graph_test_01.txt
```

## Input Format
```
V E
u0 degree neighbor1 neighbor2 ...
...
SOURCE s
```

## Output Format
```
Algorithm: BFS
Source: <s>
Traversal: <BFS order>
Distances:
<vertex> <distance, INF if unreachable>
...
Execution time: <value> ms
```

## Timing Rule
Only `runBFS()` is timed; file I/O and CSR conversion are excluded.

## Result Table
| Test File      | Vertices(V)| Edges(E)  | Source | Execution Time (ms) |
|---------------------|:---:|:---:|:---:|:---:|
| graph_test_01.txt   | 5  | 5  | 0 | 0 |
| graph_test_02.txt   | 10 | 12 | 7 | 0 |