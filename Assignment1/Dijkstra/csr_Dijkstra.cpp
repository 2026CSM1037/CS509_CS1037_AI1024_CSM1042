#include <bits/stdc++.h>

using namespace std;

#define MAX_SIZE 100000
#define INF 1000000000

int main() {

    ifstream fin("graph_test_01.txt");

    if(!fin) {
        cout << "File not found\n";
        return 0;
    }

    int vertices, edges;
    fin >> vertices >> edges;

    map<int, vector<pair<int,int>>> graph;

    for(int i = 0; i < vertices; i++) {
        int vertex, outDegree;
        fin >> vertex >> outDegree;

        for(int j = 0; j < outDegree; j++) {
            int neighbor, weight;
            fin >> neighbor >> weight;

            graph[vertex].push_back({neighbor, weight});
        }
    }

    int offset[MAX_SIZE];
    int intermediate[MAX_SIZE];
    int property[MAX_SIZE];

    fill(offset, offset + MAX_SIZE, -1);

    int pos = 0;

    for(int i = 0; i < vertices; i++) {
        offset[i] = pos;

        for(int j = 0; j < graph[i].size(); j++) {
            intermediate[pos] = graph[i][j].first;
            property[pos] = graph[i][j].second;
            pos++;
        }
    }

    offset[vertices] = pos;

    auto start = chrono::high_resolution_clock::now();

    int dist[MAX_SIZE];
    bool visited[MAX_SIZE];

    fill(dist, dist + MAX_SIZE, INF);
    fill(visited, visited + MAX_SIZE, false);

    int source = 0;
    dist[source] = 0;

    // Simple O(V^2) Dijkstra
    for(int i = 0; i < vertices; i++) {

        int u = -1;

        for(int j = 0; j < vertices; j++) {
            if(!visited[j] && (u == -1 || dist[j] < dist[u]))
                u = j;
        }

        if(u == -1 || dist[u] == INF)
            break;

        visited[u] = true;

        for(int k = offset[u]; k < offset[u + 1]; k++) {

            int v = intermediate[k];
            int w = property[k];

            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    auto end = chrono::high_resolution_clock::now();
    auto timeTaken = chrono::duration_cast<chrono::milliseconds>(end - start);

    cout << "Algorithm : Dijkstra\n";
    cout << "Source : 0\n\n";

    cout << "Shortest Distance from Source\n";

    for(int i = 0; i < vertices; i++) {
        if(dist[i] == INF)
            cout << i << " : INF\n";
        else
            cout << i << " : " << dist[i] << endl;
    }

    cout << "\nDijkstra completed in : "
         << timeTaken.count() << " milliseconds\n";

    return 0;
}