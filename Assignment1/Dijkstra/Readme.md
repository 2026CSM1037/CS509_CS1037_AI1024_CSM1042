# Run Commad
g++ -std=c++17 -O2 driver/driver.cpp src/dijkstra.cpp -o dijkstra.exe
# Dijkstra Algorithm Results

## System Configuration

- **Algorithm:** Dijkstra (CSR Representation)
- **Language:** C++
- **Compiler:** g++ (C++17)
- **Source Vertex:** 0

---

## Test Results

| Test File | Vertices | Edges | Graph Type | Source | Execution Time (ms) | Status |
|-----------|----------:|------:|------------|:------:|--------------------:|:------:|
| graph_test_01.txt | 10 | 22 | Weighted Directed | 0 | 0 | ✅ Pass |
| graph_test_02.txt | 100 | 495 | Weighted Directed | 0 | 0 | ✅ Pass |
| graph_test_03.txt | 10000 | 100040 | Weighted Directed | 0 | 27.46 | ✅ Pass |
| graph_test_04.txt | 50000 | 373823 | Weighted Directed | 0 | 168.93 | ✅ Pass |
| graph_test_05.txt | 100000 | 1102067 | Weighted Directed | 0 | 721.15 | ✅ Pass |

---

## Output

For each test case, the program prints:

- Shortest distance from source vertex (0)
- Execution time
- Pass/Fail status

Example:

```text
Algorithm : Dijkstra
Source : 0

Shortest Distance from Source

0 : 0
1 : 4
2 : 7
3 : 12
...

Execution Time : 27 ms
```

---

## Complexity

| Operation | Complexity |
|-----------|------------|
| CSR Construction | O(V + E) |
| Dijkstra (Simple) | O(V²) |
| Memory | O(V + E) |