#ifndef MAXFLOW_H
#define MAXFLOW_H

#include<bits/stdc++.h>
using namespace std;

// Runs the Maxflow-Mincut (Dinic's algorithm) pipeline on the given input file.
// - Reads/validates the file
// - Calls the shared CSR conversion helper (executeCSR) as preprocessing
// - Builds the residual graph from the CSR arrays, runs Dinic's algorithm,
//   extracts the min cut, and prints the result
// calledFromOtherAssignment is forwarded to executeCSR (kept false here since
// this program's own output format is used instead of csr.cpp's).
void executeMaxflowMincut(string fileName);

#endif