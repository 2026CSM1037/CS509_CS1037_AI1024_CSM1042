#include "connected_components.h"
#include <queue>

using namespace std;

ConnectedComponentsResult connectedComponents(
    int vertices,
    const vector<vector<int>>& graph
)
{
    ConnectedComponentsResult result;

    result.numberOfComponents = 0;
    result.component.resize(vertices, -1);

    vector<bool> visited(vertices, false);

    for (int start = 0; start < vertices; start++)
    {
        if (visited[start])
            continue;

        result.numberOfComponents++;

        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            result.component[u] =
                result.numberOfComponents;

            for (int v : graph[u])
            {
                if (!visited[v])
                {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }

    return result;
}