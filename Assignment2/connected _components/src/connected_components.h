#ifndef CONNECTED_COMPONENTS_H
#define CONNECTED_COMPONENTS_H

#include <vector>

using namespace std;

struct ConnectedComponentsResult
{
    int numberOfComponents;
    vector<int> component;
};

ConnectedComponentsResult connectedComponents(
    int vertices,
    const vector<vector<int>>& graph
);

#endif