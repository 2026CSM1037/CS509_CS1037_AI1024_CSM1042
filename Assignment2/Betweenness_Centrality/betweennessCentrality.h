#ifndef BETWEENNESSCENTRALITY_H
#define BETWEENNESSCENTRALITY_H

#include <bits/stdc++.h>

using namespace std;

struct CSRGraph{
    int numVertices;
    int numEdges;
    vector<int> offset;
    vector<int> intermediate;
};

void executeBetweennessCentrality(string fileName);

#endif