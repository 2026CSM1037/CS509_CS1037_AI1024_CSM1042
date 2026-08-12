# Triangle Counting

## System Configuration
- **Algorithm:** Triangle Counting
- **Graph Type:** Undirected
- **Graph Representation:** CSR
- **Language:** C++
- **Compiler:** g++

## Folder Layout

```
<parent>/
├── assignment_01/
│   ├── include/graph.h
│   ├── include/csr.h
│   ├── src/graph/graph.cpp
│   └── src/helper/csr_helper.cpp
└── Assignment2/
    └── TriangleCounting/   <- this folder
```

## Run Command

**Using Makefile:**
```bash
cd Assignment2/TriangleCounting
make
./bin/assignment2 triangle_counting tests/tc_10.txt
```

**Without Makefile (direct g++):**
```bash
cd Assignment2/TriangleCounting
g++ -std=c++17 -O2 -Iinclude -I../../assignment_01/include src/main.cpp src/triangle_counting.cpp ../../assignment_01/src/graph/graph.cpp ../../assignment_01/src/helper/csr_helper.cpp -o triangle_counting
./triangle_counting triangle_counting tests/tc_10.txt
```

## Results

| Test File | Vertices | Edges | Directed | Total Triangles | Time | Status |
|---|---:|---:|---|---:|---:|---|
| `tc_10.txt` | 10 | 15 | No | 1 | 0.000271 ms | Pass |
| `tc_100.txt` | 100 | 300 | No | 41 | 0.012813 ms  | Pass |
| `tc_10000.txt` | 10,000 | 30,000 | No | 42 | 15.769 ms | Pass |
| `tc_50000.txt` | 50,000 | 150,000 | No | 39 | 16.595 ms | Pass |
| `tc_100000.txt` | 100,000 | 300,000 | No | 34 | 55.079 ms | Pass |

## Complexity

**Approach:** Common-neighbour check per vertex (CSR + binary search)  
**Time Complexity:** O(V · d²), where d = average vertex degree  
**Space Complexity:** O(V + E)

