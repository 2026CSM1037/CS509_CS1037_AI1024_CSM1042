#include <bits/stdc++.h>

using namespace std;

void generateGraph(int V, int E, string filename)
{
    vector<vector<int>> graph(V);

    random_device rd;
    mt19937 gen(rd());

    set<pair<int,int>> usedEdges;

    // Generate edges
    while((int)usedEdges.size() < E)
    {
        int u = gen() % V;
        int v = gen() % V;

        // No self-loop
        if(u == v)
            continue;

        // Keep smaller vertex first
        if(u > v)
            swap(u, v);

        if(usedEdges.count({u, v}))
            continue;

        usedEdges.insert({u, v});

        // Undirected edge
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    ofstream fout(filename);

    if(!fout)
    {
        cout << "Cannot create " << filename << "\n";
        return;
    }

    // V E
    fout << V << " " << E << "\n";

    // Adjacency list
    for(int u = 0; u < V; u++)
    {
        fout << u << " "
             << graph[u].size();

        for(int v : graph[u])
        {
            fout << " " << v;
        }

        fout << "\n";
    }

    fout.close();

    cout << "Created: "
         << filename
         << "  V=" << V
         << " E=" << E << "\n";
}

int main()
{
    generateGraph(
        10,
        15,
        "tests/cc_10.txt"
    );

    generateGraph(
        100,
        200,
        "tests/cc_100.txt"
    );

    generateGraph(
        10000,
        20000,
        "tests/cc_10000.txt"
    );

    generateGraph(
        50000,
        100000,
        "tests/cc_50000.txt"
    );

    generateGraph(
        100000,
        200000,
        "tests/cc_100000.txt"
    );

    return 0;
}