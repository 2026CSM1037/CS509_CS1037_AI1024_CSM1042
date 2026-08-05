#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 100000
#define INF 1000000000

void dijkstra(int vertices,
              int offset[],
              int intermediate[],
              int property[],
              int dist[]);

#endif