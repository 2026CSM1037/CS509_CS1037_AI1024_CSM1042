#include "dijkstra.h"

void dijkstra(int vertices,
              int offset[],
              int intermediate[],
              int property[],
              int dist[])
{
    bool visited[MAX_SIZE];

    fill(dist, dist + MAX_SIZE, INF);
    fill(visited, visited + MAX_SIZE, false);

    int source = 0;
    dist[source] = 0;

    for(int i = 0; i < vertices; i++)
    {
        int u = -1;

        for(int j = 0; j < vertices; j++)
        {
            if(!visited[j] && (u == -1 || dist[j] < dist[u]))
                u = j;
        }

        if(u == -1 || dist[u] == INF)
            break;

        visited[u] = true;

        for(int k = offset[u]; k < offset[u + 1]; k++)
        {
            int v = intermediate[k];
            int w = property[k];

            if(dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }
}