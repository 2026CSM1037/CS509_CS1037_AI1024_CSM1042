# CS509 - Assignment 1: DFS (Depth-First Search)

**Task:** Buddy Task – DFS

## Files
- `dfs.h`, `dfs.cpp` – CSR graph + dfs implementation
- `driver.cpp` – reads input, builds CSR graph, times dfs, prints output
- `Makefile` – build script
- `graph_test_01.txt`, `graph_test_02.txt` – inputs
- `graph_test_01_output.txt`, `graph_test_02_output.txt`, `graph_test_03_output.txt`, `graph_test_04_output.txt`, `graph_test_05_output.txt` – outputs

## Project Structure
```
CS509_CS1037_AI1024_CSM1042/
└── Assignment1/
    └── dfs/
        ├── dfs.h
        ├── dfs.cpp
        ├── driver.cpp
        ├── Makefile
        ├── dfs_exec.exe          (generated after build)
        ├── graph_test_01.txt
        ├── graph_test_01_output.txt
        ├── graph_test_02.txt
        ├── graph_test_02_output.txt
        ├── graph_test_03.txt
        ├── graph_test_03_output.txt
        ├── graph_test_04.txt
        ├── graph_test_04_output.txt
        ├── graph_test_05.txt
        └── graph_test_05_output.txt
```

## Build & Run
Open a terminal inside the `dfs` folder, then:
```
make
./dfs_exec graph_test_01.txt
./dfs_exec graph_test_02.txt
```
On Windows, if `make` isn't available, build directly with:
```
g++ -O2 -std=c++17 driver.cpp dfs.cpp -o dfs_exec.exe
dfs_exec.exe graph_test_01.txt
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
Algorithm: dfs
Source: <s>
Traversal: <dfs order>
Distances:
<vertex> <distance, INF if unreachable>
...
Execution time: <value> ms
```

## Timing Rule
Only `dfsCSR()` is timed; file I/O and CSR conversion are excluded.

## Result Table
| Test File      | Vertices(V)| Edges(E)  | Source | Execution Time (ms) |
|---------------------|:---:|:---:|:---:|:---:|
| graph_test_01.txt   | 6  | 7  | 0 | 0 |
| graph_test_02.txt   | 10 | 17 | 4 | 0 |
| graph_test_03.txt   | 100 | 112 | 6 | 0 |
| graph_test_04.txt   | 1000 | 11438 | 3 | 35 |
| graph_test_05.txt   | 10000 | 160108 | 3 | - |
