## Connected Components

### System Configuration

- **Algorithm**: Connected Components
- **Graph Type**: Undirected
- **Graph Representation**: CSR
- **Language:** C++
- **Compiler:** g++

### Result Table

| Algorithm             | Test File       | Vertices | Edges | Expected Output | Actual Output | Time | Status |
| --------------------- | --------------- | -------: | ----: | --------------- | ------------- | ---: | ------ |
| Connected Components  | `cc_10.txt`     |       10 |   15 | Component per vertex | Component per vertex | 0.003 ms | Pass |
| Connected Components  | `cc_100.txt`    |      100 |   200 | Component per vertex | Component per vertex | 0.012 ms | Pass |
| Connected Components  | `cc_10000.txt`  |   10,000 |   20,000 | Component per vertex | Component per vertex | 0.534 ms | Pass |
| Connected Components  | `cc_50000.txt`  |   50,000 |   1,00,000 | Component per vertex | Component per vertex | 2.995 ms | Pass |
| Connected Components  | `cc_100000.txt` |  100,000 |   2,00,000 | Component per vertex | Component per vertex | 8.664 ms | Pass |
